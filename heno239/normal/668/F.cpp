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
#include<unordered_set>
#include<utility>
#include<cassert>
#include<complex>
#include<numeric>
#include<array>
using namespace std;

//#define int long long
typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
constexpr ll mod = 1000000007;
const ll INF = mod * mod;
typedef pair<int, int>P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
#define all(v) (v).begin(),(v).end()
typedef pair<ll, ll> LP;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-12;
const ld pi = acosl(-1.0);

ll mod_pow(ll x, ll n, ll m = mod) {
	if (n < 0) {
		ll res = mod_pow(x, -n, m);
		return mod_pow(res, m - 2, m);
	}
	if (abs(x) >= m)x %= m;
	if (x < 0)x += m;
	ll res = 1;
	while (n) {
		if (n & 1)res = res * x % m;
		x = x * x % m; n >>= 1;
	}
	return res;
}
struct modint {
	ll n;
	modint() :n(0) { ; }
	modint(ll m) :n(m) {
		if (n >= mod)n %= mod;
		else if (n < 0)n = (n % mod + mod) % mod;
	}
	operator int() { return n; }
};
bool operator==(modint a, modint b) { return a.n == b.n; }
modint operator+=(modint& a, modint b) { a.n += b.n; if (a.n >= mod)a.n -= mod; return a; }
modint operator-=(modint& a, modint b) { a.n -= b.n; if (a.n < 0)a.n += mod; return a; }
modint operator*=(modint& a, modint b) { a.n = ((ll)a.n * b.n) % mod; return a; }
modint operator+(modint a, modint b) { return a += b; }
modint operator-(modint a, modint b) { return a -= b; }
modint operator*(modint a, modint b) { return a *= b; }
modint operator^(modint a, ll n) {
	if (n == 0)return modint(1);
	modint res = (a * a) ^ (n / 2);
	if (n % 2)res = res * a;
	return res;
}

ll inv(ll a, ll p) {
	return (a == 1 ? 1 : (1 - p * inv(p % a, a)) / a + p);
}
modint operator/(modint a, modint b) { return a * modint(inv(b, mod)); }
modint operator/=(modint& a, modint b) { a = a / b; return a; }
const int max_n = 1 << 16;
modint fact[max_n], factinv[max_n];
void init_f() {
	fact[0] = modint(1);
	for (int i = 0; i < max_n - 1; i++) {
		fact[i + 1] = fact[i] * modint(i + 1);
	}
	factinv[max_n - 1] = modint(1) / fact[max_n - 1];
	for (int i = max_n - 2; i >= 0; i--) {
		factinv[i] = factinv[i + 1] * modint(i + 1);
	}
}
modint comb(int a, int b) {
	if (a < 0 || b < 0 || a < b)return 0;
	return fact[a] * factinv[b] * factinv[a - b];
}
modint combP(int a, int b) {
	if (a < 0 || b < 0 || a < b)return 0;
	return fact[a] * factinv[a - b];
}


const int max_sz = 205;
modint dp[10001][max_sz];
modint cop[max_sz];
bool can[max_sz][max_sz];
int res[max_sz][max_sz];
vector<vector<int>> oris;
void init(int k) {
	vector<P> ps;
	rep(i, k)Rep(j, i + 1, k) {
		ps.push_back({ i,j });
	}
	int len = ps.size();
	rep(i, (1 << len)) {
		vector<vector<int>> G(k);
		rep(j, len) {
			if (i & (1 << j)) {
				G[ps[j].first].push_back(ps[j].second);
				G[ps[j].second].push_back(ps[j].first);
			}
		}
		vector<int> v;
		vector<bool> used(k);
		rep(j, k) {
			if (used[j])continue;
			queue<int> q; q.push(j); used[j] = true;
			int s = 0;
			while (!q.empty()) {
				int id = q.front(); q.pop();
				s |= (1 << id);
				for (int to : G[id]) {
					if (!used[to]) {
						used[to] = true; q.push(to);
					}
				}
			}
			v.push_back(s);
		}
		sort(all(v));
		oris.push_back(v);
	}
	sort(all(oris));
	oris.erase(unique(all(oris)), oris.end());
	rep(i, oris.size())rep(j, oris.size()) {
		vector<vector<int>> G(k);
		for (int s : oris[i]) {
			int pre = -1;
			rep(l, k) {
				if (s & (1 << l)) {
					if (pre >= 0) {
						G[l].push_back(pre);
						G[pre].push_back(l);
					}
					pre = l;
				}
			}
		}
		for (int s : oris[j]) {
			int pre = -1;
			rep(l, k) {
				if (s & (1 << l)) {
					if (pre >= 0) {
						G[l].push_back(pre);
						G[pre].push_back(l);
					}
					pre = l;
				}
			}
		}
		vector<bool> used(k);
		bool valid = true;
		vector<int> r;
		rep(j, k) {
			if (used[j])continue;
			queue<int> q; q.push(j); used[j] = true;
			int s = 0;
			int ce = 0;
			int cnt = 0;
			while (!q.empty()) {
				int id = q.front(); q.pop();
				ce += G[id].size(); cnt++;
				s |= (1 << id);
				for (int to : G[id]) {
					if (!used[to]) {
						used[to] = true; q.push(to);
					}
				}
			}
			if (ce != 2 * (cnt - 1))valid = false;
			r.push_back(s);
		}
		sort(all(r));
		if (valid) {
			can[i][j] = true;
			res[i][j] = lower_bound(all(oris), r) - oris.begin();
		}
	}
}

void normalize(vector<int>& v, int k) {
	k++;
	int xs = 0;
	for (int s : v)xs |= s;
	rep(i, k) {
		if (xs & (1 << i))continue;
		v.push_back(1 << i);
	}
	sort(all(v));
}

vector<int> ch[10001];
vector<int> nex[10001];

int trans[10001];
void solve() {
	int n, k; cin >> n >> k;
	init(k + 1);
	/*rep(i, oris.size()) {
		rep(j, oris[i].size()) {
			if (j > 0)cout << " ";
			cout << oris[i][j];
		}
		cout << "\n";
	}*/
	rep(i, k) {
		rep(j, i)ch[i].push_back(j);
	}
	for (int i = k; i < n; i++) {
		ch[i].resize(k);
		rep(j, k) {
			cin >> ch[i][j]; ch[i][j]--;
		}
	}
	rep1(i, n - 1) {
		int ma = 0;
		rep(j, ch[i].size())ma = max(ma, ch[i][j]);
		nex[ma].push_back(i);
	}
	for (int i = n - 1; i >= 0; i--) {
		rep(j, ch[i].size()) {
			trans[ch[i][j]] = j;
		}
		trans[i] = ch[i].size();
		vector<int> ori(k + 1);
		rep(j, k + 1)ori[j] = (1 << j);
		int loc = lower_bound(all(oris), ori) - oris.begin();
		dp[i][loc] = 1;
		for (int to : nex[i]) {
			fill(cop, cop + oris.size(), 0);
			vector<int> nv;
			rep(j, oris.size()) {
				nv.clear();
				for (int s : oris[j]) {
					int xs = 0;
					rep(l, ch[to].size()) {
						if (s & (1 << l))xs |= (1 << trans[ch[to][l]]);
					}
					if (xs > 0)nv.push_back(xs);
				}
				normalize(nv, k);
				int id2 = lower_bound(all(oris), nv) - oris.begin();
				rep(id1, oris.size()) {
					if (can[id1][id2]) {
						cop[res[id1][id2]] += dp[i][id1] * dp[to][j];
						//cout << "?! " << i << " " << id1<<" "<<id2<<" "<<dp[i][id1] << " " << dp[to][id2] << "\n";
					}
				}
			}
			rep(j, oris.size()) {
				dp[i][j] = cop[j];
			}
		}
		if (i == 0)break;

		//cout << "start " << i << "\n";
		//rep(j, oris.size())cout << dp[i][j] << "\n";
		vector<int> nexs;
		for (int ss = 0; ss < (1 << ch[i].size()); ss++) {
			vector<int> nv;
			int xs = 1<<ch[i].size();
			rep(j, ch[i].size()) {
				if (ss & (1 << j)) {
					xs |= (1 << j);
				}
				else {
					nv.push_back(1 << j);
				}
			}
			if(xs>0)nv.push_back(xs);
			normalize(nv, k);
			nexs.push_back(lower_bound(all(oris), nv) - oris.begin());
		}
		rep(j, oris.size())cop[j] = 0;
		vector<bool> isout(oris.size());
		rep(j, oris.size()) {
			for (int s : oris[j])if (s == (1 << ch[i].size()))isout[j] = true;
		}
		rep(j, oris.size()) {
			for (int nex : nexs) {
				if (can[j][nex]) {
					if (isout[res[j][nex]])continue;
					cop[res[j][nex]] += dp[i][j];
				}
			}
		}
		rep(j, oris.size()) {
			dp[i][j] = 0;
		}
		rep(j, oris.size()) {
			vector<int> nv;
			for (int s : oris[j]) {
				int xs = s;
				if(xs&(1<<ch[i].size()))xs^=(1<<ch[i].size());
				if (xs > 0)nv.push_back(xs);
			}
			normalize(nv, k);
			int id1 = lower_bound(all(oris), nv) - oris.begin();
			dp[i][id1] += cop[j];
		}
		//cout << "start " << i << "\n";
		//rep(j, oris.size())cout << dp[i][j] << "\n";
	}
	vector<int> ori(k + 1);
	rep(i, k + 1)ori[i] = (1 << i);
	int id = lower_bound(all(oris), ori) - oris.begin();
	modint ans = dp[0][id];
	cout << ans << "\n";
	//rep(j, oris.size())cout << "? " << isout[j] << "\n";
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(10);
	//init_f();
	//init();
	//expr();
	//int t; cin >> t;rep(i,t)
	//while(cin>>n,n)
	//solve();
	solve();
	return 0;
}