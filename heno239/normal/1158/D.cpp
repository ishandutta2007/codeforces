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
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
using namespace std;
typedef long long ll;
typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 1000000007;
typedef long double ld;
typedef complex<ld> Point;
const ll INF = mod * mod;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
const ld eps = 1e-6;
const ld pi = acos(-1.0);
typedef pair<ld, ld> LDP;
typedef pair<ll, ll> LP;

LP v[2000];
bool used[2000];
int ans[2000];

int n;
ld norm(LP &p) {
	ll ret = p.first*p.first + p.second*p.second;
	return sqrt(ret);
}
string check() {
	string ret;
	rep(i, n - 2) {
		int i1 = ans[i], i2 = ans[i + 1], i3 = ans[i + 2];
		ll dx = v[i2].first - v[i1].first, dy = v[i2].second - v[i1].second;
		ll vx = v[i3].first - v[i2].first, vy = v[i3].second - v[i2].second;
		ll z = dx * vy - dy * vx;
		if (z < 0)ret.push_back('R');
		else ret.push_back('L');

	}
	return ret;
}

bool calc(int a, int b, int c) {
	ll dx = v[b].first - v[a].first;
	ll dy = v[b].second - v[a].second;
	ll vx = v[c].first - v[a].first;
	ll vy = v[c].second - v[a].second;
	return dx * vy - dy * vx > 0;
}
void solve() {
	cin >> n;
	rep(i, n) {
		cin >> v[i].first >> v[i].second;
	}
	string s; cin >> s;
	int sta; int mix = -mod;
	rep(i, n) {
		if (v[i].second > mix) {
			mix = v[i].second; sta = i;
		}
	}
	used[sta] = true;
	int sta2;
	rep(i, n) {
		if (used[i])continue;
		int c[2] = {};
		ll dx = v[i].first - v[sta].first;
		ll dy = v[i].second - v[sta].second;
		rep(j, n) {
			if (j==i||j==sta)continue;
			ll vx = v[j].first - v[sta].first;
			ll vy = v[j].second - v[sta].second;
			ll z = dx * vy - dy * vx;
			if (z < 0)c[0]++;
			else c[1]++;
		}
		if (c[0] == 0) {
			sta2 = i; break;
		}
	}
	used[sta2] = true;
	//cout << sta + 1 << " " << sta2 + 1 << endl;
	if (s[0] == 'R') {
		swap(sta, sta2);
	}
	ans[0] = sta, ans[1] = sta2;
	Rep(i, 2, n) {
		char t = s[i - 1];
		int le = ans[i - 2], ri = ans[i - 1];
		LP p = { v[ri].first - v[le].first,v[ri].second - v[le].second };
		int nex;
		if (t == 'R') {
			int f = ri; nex = le;
			rep(j, n) {
				if (used[j])continue;
				if (nex == le)nex = j;
				else if (calc(f, nex, j))nex = j;
			}
		}
		else {
			int f = ri; nex = le;
			rep(j, n) {
				if (used[j])continue;
				if (nex == le)nex = j;
				else if (!calc(f, nex, j))nex = j;
			}
		}
		used[nex] = true; ans[i] = nex;
	}
	/*string st = check();
	if (s != st) {
		cout << -1 << endl; return;
	}*/
	rep(i, n) {
		if (i > 0)cout << " ";
		cout << ans[i]+1;
	}
	cout << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	//stop
	return 0;
}