#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
#include<cassert>
#include<complex>
#include<cstdlib>
using namespace std;

//#define int long long
typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 1000000007;
const ll INF = mod * mod;
typedef pair<int, int>P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef pair<ll, ll> LP;
typedef vector<ll> vec;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-5;
const ld pi = acos(-1.0);
typedef vector<int> status;

int k;

vector<vector<int>> ori;
map<vector<int>,int>id_ori;
int f[120][120];

status bas;
vector<status> allstatus;
map<status, int> rev;
map<status, int>chked;
bool used[120];

bool added[100000][120];
int memo[100000][120];
int add(int ds, int id) {
	if (added[ds][id])return memo[ds][id];
	added[ds][id] = true;
	fill(used, used+ori.size(), false);
	status s = allstatus[ds];
	rep(i, s.size()) {
		used[s[i]] = true;
	}
	if (used[id]) {
		//return rev[s];
		return memo[ds][id]=rev[s];
	}
	s.push_back(id); used[id] = true;
	for (int i = s.size() - 1; i < s.size(); i++) {
		rep(j, s.size()) {
			if (!used[f[s[j]][s[i]]]) {
				used[f[s[j]][s[i]]] = true;
				s.push_back(f[s[j]][s[i]]);
			}
			if (!used[f[s[i]][s[j]]]) {
				used[f[s[i]][s[j]]] = true;
				s.push_back(f[s[i]][s[j]]);
			}
		}
	}
	sort(s.begin(), s.end());
	if (!chked[s]) {
		chked[s] = true; rev[s] = allstatus.size();
		allstatus.push_back(s);
	}
	//return rev[s];
	return memo[ds][id]=rev[s];
}

vector<int> seed;
int trans[120];

void init() {
	vector<int> e(k);
	rep(i, k) {
		e[i] = i;
	}
	while (true) {
		id_ori[e] = ori.size();
		ori.push_back(e);
		if (!next_permutation(e.begin(), e.end()))break;
	}
	rep(i, ori.size()) {
		rep(j, ori.size()) {
			vector<int> nex(k);
			rep(l, k) {
				nex[l] = ori[i][ori[j][l]];
			}
			f[i][j] = id_ori[nex];
		}
	}
	bas = { 0 }; rev[bas] = 0; chked[bas] = true;
	allstatus.push_back(bas);
	
	vector<int> c(ori.size());
	rep(i, ori.size()) {
		c[i] = add(0, i);
	}
	rep(j, ori.size()) {
		bool f = true;
		rep(i, j) {
			if (c[i] == c[j]) {
				f = false; trans[j] = trans[i];
			}
		}
		if (f) {
			seed.push_back(j);
			trans[j] = j;
		}
	}
}
vector<int> oris;
int las[120];
void solve() {
	int n; cin >> n >> k;
	vector<vector<int>> p(n);
	rep(i, n) {
		p[i].resize(k);
		rep(j, k) {
			cin >> p[i][j]; p[i][j]--;
		}
	}
	init();
	//cout << seed.size() << endl;
	rep(i, n) {
		oris.push_back(trans[id_ori[p[i]]]);
	}
	ll ans = 0;
	fill(las, las + ori.size(), -1);
	ll sum = 0;
	rep(i, n) {
		las[oris[i]] = i;
		vector<P> v;
		rep(j, seed.size())v.push_back({ las[seed[j]],seed[j] });
		sort(v.begin(), v.end(), greater<P>());
		int u = 0;
		int cur = i;
		rep(j, v.size()) {
			int nex = v[j].first;
			ll dif = cur - nex;
			ans += dif * allstatus[u].size(); //sum += dif;
			cur = nex;
			if (nex < 0)break;
			u=add(u, v[j].second);
		}
		if (cur >= 0)ans += (cur+1) * allstatus[u].size();
		//sum += cur + 1;
	}
	//assert(sum == (ll)n*(n + 1) / 2);
	cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(7);
	//init();
	solve();
	//stop
	return 0;
}