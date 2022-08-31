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
const ld eps = 1e-6;
const ld pi = acos(-1.0);
typedef vector<vector<ll>> mat;
typedef vector<ll> vec;



vector<int> G[1 << 19];

int memo[1 << 19];
vector<P> dep[1 << 19];

int idfs(int id, int fr) {
	int res = 0;
	rep(j, G[id].size()) {
		int to = G[id][j];
		if (to == fr)continue;
		int nex = idfs(to, id);
		res = max(res, nex);
	}
	memo[id] = res+1;
	if (fr >= 0) {
		dep[fr].push_back({ id,res + 1 });
	}
	//dep[id].push_back({ fr,res+1 });
	return res + 1;
}
void rdfs(int id, int fr, int pre) {
	vector<int> cs;
	rep(j, G[id].size()) {
		int to = G[id][j];
		if (to == fr)continue;
		cs.push_back(memo[to]);
	}
	vector<int> lema(cs.size() + 1), rima(cs.size() + 1);
	lema[0] = 0;
	rep(i, cs.size()) {
		lema[i + 1] = max(lema[i], cs[i]);
	}
	rima[cs.size()] = 0;
	per(i, (int)cs.size()) {
		rima[i] = max(rima[i + 1], cs[i]);
	}
	int tmp = 0;
	rep(j, G[id].size()) {
		int to = G[id][j];
		if (to == fr)continue;
		int val = max({ lema[tmp],rima[tmp + 1],pre });
		dep[to].push_back({ id,val + 1 });
		//dep[id].push_back({ to,val+1 });
		rdfs(to, id, val + 1);
		tmp++;
	}
}

void init(int n) {
	idfs(0, -1);
	rdfs(0, -1, 0);
	rep(i, n) {
		sort(dep[i].begin(), dep[i].end());
	}
}


int ans[1 << 20];


int calc_d(int id, int fr) {
	int t = lower_bound(dep[id].begin(), dep[id].end(), P{ fr,-1 }) - dep[id].begin();
	return dep[id][t].second;
}

vector<P> ds[1<<19];

void upd(int l, int r) {
	//cout << "! " << l << r << endl;
	int d1 = calc_d(l, r);
	int d2 = calc_d(r, l);
	rep(i, ds[l].size()){
		if (ds[l][i].first == d1) {
			ds[l][i].second--;
		}
		//cout << ds[l][i].first << " " << ds[l][i].second << endl;
	}

	rep(i, ds[r].size())if (ds[r][i].first == d2)ds[r][i].second--;
	int id1 = 0, id2 = 0;
	int num = dep[l].size() + dep[r].size() - 2;
	while (id1 < ds[l].size() || id2 < ds[r].size()) {
		int x, y;
		if (id1 == ds[l].size()) {
			x = ds[r][id2].first;
			y = ds[r][id2].second;
			id2++;
		}
		else if (id2 == ds[r].size()) {
			x = ds[l][id1].first;
			y = ds[l][id1].second;
			id1++;
		}
		else {
			//cout << id1 << " " << ds[l].size() << " " << id2 << " " << ds[r].size() << endl;
			if (ds[l][id1].first < ds[r][id2].first) {
				x = ds[l][id1].first;
				y = ds[l][id1].second;
				id1++;
			}
			else if (ds[r][id2].first < ds[l][id1].first) {
				x = ds[r][id2].first;
				y = ds[r][id2].second;
				id2++;
			}
			else {
				x = ds[l][id1].first;
				y = ds[l][id1].second + ds[r][id2].second;
				id1++; id2++;
			}
		}
		ans[2 * x] = max(ans[2 * x], num);
		//ans[2 * x + 1] = max(ans[2 * x + 1], num);
		//cout << 2 * x << " " << 2 * x + 1 << " " << num << endl;
		num -= y;
	}
	rep(i, ds[l].size())if (ds[l][i].first == d1)ds[l][i].second++;
	rep(i, ds[r].size())if (ds[r][i].first == d2)ds[r][i].second++;
}

void solve() {
	int n; cin >> n;
	ans[n] = 1;
	ans[n + 1] = 1;
	rep(i, n - 1) {
		int a, b; cin >> a >> b; a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	rep(i, n) {
		sort(G[i].begin(), G[i].end());
	}
	init(n);
	rep(i, n) {
		//cout << "!" << " " << i << endl;
		vector<int> dd;
		rep(j, dep[i].size()) {
			int sc = dep[i][j].second;
			//cout << "? " << sc << endl;
			dd.push_back(sc);
		}
		sort(dd.begin(), dd.end());
		int len = dd.size();
		rep(j, len) {
			int le = j;
			while (j + 1 < len&&dd[j] == dd[j + 1])j++;
			ds[i].push_back({ dd[j],j - le + 1 });
		}
		int num = len;
		rep(j, ds[i].size()) {
			int x = ds[i][j].first;
			ans[2 * x - 1] = max(ans[2 * x - 1], num);
			ans[2 * x] = max(ans[2 * x], num);
			//cout << 2 * x - 1 << " " << 2 * x  << " " << num << endl;
			num -= ds[i][j].second;
			ans[2 * x + 1] = max(ans[2 * x + 1], num + 1);
			//cout << 2 * x + 1 << " " << num << endl;
		}
	}
	rep(i, n) {
		rep(j, G[i].size()) {
			int to = G[i][j];
			if (i > to)continue;
			upd(i, to);
		}
	}
	for (int i = n-1; i >= 1; i--) {
		ans[i] = max(ans[i], ans[i + 2]);
	}
	rep(i, n)ans[1] = max(ans[1],(int)G[i].size()+1);
	rep1(i, n) {
		if (i > 1)cout << " ";
		cout << ans[i];
	}
	cout << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(4);
	//init();
	solve();
	//stop
		return 0;
}