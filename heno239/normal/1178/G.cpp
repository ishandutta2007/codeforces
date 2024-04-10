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
using namespace std;

//#define int long long
typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 1000000007;
const ll INF = mod*mod;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef pair<ll, ll> LP;
typedef vector<LP> vec;
typedef vector<string> svec;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-8;

struct CHT {
	vector<LP> v;
	int l;
	bool check(LP a, LP b, LP c) {
		return (b.first - a.first)*(c.second - b.second) >= (b.second - a.second)*(c.first - b.first);
	}
	void build(vector<LP> a) {
		v.clear(); l = 0;
		//sort(a.begin(), a.end());
		l = 0;
		per(i, (int)a.size()) {
			while (v.size() >= 2 && check(v[v.size() - 2], v[v.size() - 1], a[i]))v.pop_back();
			v.push_back(a[i]);
		}
	}
	ll f(LP a, ll x) {
		return a.first*x + a.second;
	}
	ll query(ll x) {
		while (l + 1 < v.size() && f(v[l], x) > f(v[l + 1], x))l++;
		return f(v[l], x);
	}
};


vector<int> G[1 << 18];
int ri[1 << 18];
int trans[1 << 18];
int cur = 0;

ll coef[1 << 18];
ll ori[1 << 18];

ll a[1 << 18], b[1 << 18];

vector<CHT> v,lv;
ll ad[1000] = {};

void dfs(int id,ll aval,ll bval) {
	aval += a[id]; bval += b[id];
	coef[cur] = abs(bval);
	ori[cur] = aval;
	trans[id] = cur; cur++;
	rep(j, G[id].size()) {
		int to = G[id][j];
		dfs(to,aval,bval);
	}
	ri[trans[id]] = cur;
}

vector<vector<int>> ord;
void solve() {
	int n, q; cin >> n >> q;
	rep1(i, n - 1) {
		int a; cin >> a; a--;
		G[a].push_back(i);
	}
	rep(i, n)cin >> a[i];
	rep(i, n)cin >> b[i];
	dfs(0,0,0);
	//cout << "hello" << endl;
	//rep(i, n)cout << trans[i] << endl;
	/*rep(i, n) {
		cout << ori[i] << " " << coef[i] << endl;
	}*/
	int k = sqrt(n); int d = (n + k - 1) / k;
	v.resize(d); lv.resize(d);

	ord.resize(d);
	rep(i, d) {
		vector<LP> u, lu;
		for (int j = k * i; j < min(n, k*(i + 1)); j++) {
			ori[j] *= coef[j];
			//v[i].add({ coef[j],ori[j] });
			u.push_back({ coef[j],ori[j] });
			//lv[i].add({ -coef[j],-ori[j] });
			lu.push_back({ -coef[j],-ori[j] });
		}
		{
			vector<LP> v;
			for (int j = k * i; j < min(n, k*(i + 1)); j++) {
				v.push_back({ coef[j],j });
			}
			sort(v.begin(), v.end());
			rep(j, v.size()) {
				ord[i].push_back(v[j].second);
			}
		}
		sort(u.begin(), u.end());
		sort(lu.begin(), lu.end());
		v[i].build(u);
		lv[i].build(lu);
	}
	rep(i, q) {
		int t; cin >> t;
		if (t == 1) {
			int loc, x; cin >> loc >> x;
			loc = trans[loc-1];
			int lid = loc / k; int rid = (ri[loc]-1) / k;
			if (lid == rid) {
				vector<LP> nw, lnw;
				rep(id, ord[lid].size()) {
					int j = ord[lid][id];
					if (loc <= j && j<ri[loc]) {
						ori[j] += (ad[lid] + x)*coef[j];
					}
					else {
						ori[j] += ad[lid] * coef[j];
					}
					nw.push_back({ coef[j],ori[j] });
					lnw.push_back({ -coef[j],-ori[j] });
				}
				reverse(lnw.begin(), lnw.end());
				ad[lid] = 0;

				v[lid].build(nw);
				lv[lid].build(lnw);
			}
			else {
				{
					vector<LP> nw, lnw;
					
					rep(id, ord[lid].size()) {
						int j = ord[lid][id];
						if (loc <= j) {
							ori[j] += (ad[lid] + x)*coef[j];
						}
						else {
							ori[j] += ad[lid] * coef[j];
						}
						nw.push_back({ coef[j],ori[j] });
						lnw.push_back({ -coef[j],-ori[j] });
					}
					reverse(lnw.begin(), lnw.end());
					ad[lid] = 0;


					v[lid].build(nw);
					lv[lid].build(lnw);
				}
				{
					//cout << "hello? " << v[rid].query(0) << endl;
					vector<LP> nw, lnw;
					rep(id, ord[rid].size()) {
						int j = ord[rid][id];
						if (j<ri[loc]) {
							ori[j] += (ad[rid] + x)*coef[j];
						}
						else {
							ori[j] += ad[rid] * coef[j];
						}
						nw.push_back({ coef[j],ori[j] });
						lnw.push_back({ -coef[j],-ori[j] });
					}
					reverse(lnw.begin(), lnw.end());
					ad[rid] = 0;

					//cout << "Hello!" << endl;
					//cout << nw.query(0) << endl;

					v[rid].build(nw);
					lv[rid].build(lnw);
				}
				for (int j = lid + 1; j <= rid - 1; j++)ad[j] += x;
			}
		}
		else {
			int loc; cin >> loc;
			loc = trans[loc - 1];
			//cout << "? " << loc << " " << ri[loc] << endl;
			int lid = loc / k; int rid = (ri[loc] - 1) / k;
			//cout << "? " << lid << " " << rid << endl;
			ll ans = 0;
			if (lid == rid) {
				for (int j = loc; j < ri[loc]; j++) {
					ans = max(ans, abs(ad[lid] * coef[j] + ori[j]));
				}
			}
			else {
				for (int j = loc; j < (lid+1)*k; j++) {
					ans = max(ans, abs(ad[lid] * coef[j] + ori[j]));
				}
				for (int j = rid * k; j < ri[loc]; j++) {
					ans = max(ans, abs(ad[rid] * coef[j] + ori[j]));
				}
				//cout << "bef " << ans << endl;
				for (int j = lid + 1; j <= rid - 1; j++) {
					//cout << "wow " << j << endl;
					ll c = v[j].query(ad[j]);
					ll d = lv[j].query(ad[j]);
					//cout << c << " " << d << endl;
					ans = max({ ans,abs(c),abs(d) });
				}
			}
			//cout << "ans is ";
			cout << ans << endl;
		}
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init();
	solve();
	//cout << "finish" << endl;
	//stop
	return 0;
}