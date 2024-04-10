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
const ll INF = (1e+18) + 7;
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
const ld eps = 1e-6;
const ld pi = acos(-1.0);
//typedef vector<vector<ll>> mat;
typedef vector<int> vec;

ll mod_pow(ll a, ll n) {
	ll res = 1;
	while (n) {
		if (n & 1)res = res * a%mod;
		a = a * a%mod; n >>= 1;
	}
	return res;
}

struct modint {
	ll n;
	modint() :n(0) { ; }
	modint(ll m) :n(m) {
		if (n >= mod)n %= mod;
		else if (n < 0)n = (n%mod + mod) % mod;
	}
	operator int() { return n; }
};
bool operator==(modint a, modint b) { return a.n == b.n; }
modint operator+=(modint &a, modint b) { a.n += b.n; if (a.n >= mod)a.n -= mod; return a; }
modint operator-=(modint &a, modint b) { a.n -= b.n; if (a.n < 0)a.n += mod; return a; }
modint operator*=(modint &a, modint b) { a.n = ((ll)a.n*b.n) % mod; return a; }
modint operator+(modint a, modint b) { return a += b; }
modint operator-(modint a, modint b) { return a -= b; }
modint operator*(modint a, modint b) { return a *= b; }
modint operator^(modint a, int n) {
	if (n == 0)return modint(1);
	modint res = (a*a) ^ (n / 2);
	if (n % 2)res = res * a;
	return res;
}

ll inv(ll a, ll p) {
	return (a == 1 ? 1 : (1 - p * inv(p%a, a)) / a + p);
}
modint operator/(modint a, modint b) { return a * modint(inv(b, mod)); }

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

const int mn = 5000;
bool iss[mn+1];
bool isp[mn+1];
int pma[mn+1];
vector<int> vs,ps;
void init_iss() {
	iss[1] = true;
	Rep1(i,2, mn) {
		int cop = i;
		int tmp = 0;
		Rep1(j, 2, i) {
			if (cop%j == 0) {
				while (cop%j == 0) {
					cop /= j; tmp++;
				}
				break;
			}
		}
		if (cop > 1)iss[i] = false;
		else {
			iss[i] = true;
			vs.push_back(i);
			if (tmp == 1) {
				isp[i] = true;
				ps.push_back(i);
			}
		}
	}
	Rep1(i, 2, mn) {
		for (int j = i; j > 1; j--) {
			if (i%j==0&&isp[j]) {
				pma[i] = j; break;
			}
		}
	}
}

int calc(int n,int sta) {
	int res = 0;
	rep(j, ps.size()) {
		if (ps[j] <= sta)continue;
		if (ps[j] > n)break;
		int al = n;
		while (al > 0) {
			res += al / ps[j];
			al /= ps[j];
		}
	}
	return res;
}

struct edge {
	int to, dist;
};
vector<vector<edge>> G(100000);

int tmp;
int loc[5001];
void yaru(int l, int r, int parent,int d) {
	//cout << tmp << " " << l << " " << r << endl;
	if (l > r)return;
	if (l == r) {
		//cout << tmp << " " << parent << " " << goa << " "<<l<<endl;
		//cout << calc(l, 0, goa) << endl;
		
		G[parent].push_back({ tmp,calc(l,0)-d });
		loc[l] = tmp;
		tmp++;
		return;
	}
	int ma = 0;
	Rep1(j, l+1, r)ma = max(ma, pma[j]);
	int score = calc(l, ma);
	//cout << "!!! " << calc(l, ma) << endl;
	int cl = l;
	while (cl>0) {
		score += cl / ma;
		cl /= ma;
	}
	G[parent].push_back({ tmp,score-d });
	int cop = tmp;
	tmp++;
	int le = l;
	Rep1(j, l+1, r) {
		if (ma == pma[j]) {
			yaru(le, j-1, cop,score);
			le = j;
		}
	}
	yaru(le, r, cop,score);
}

void init_g() {
	tmp = 1;
	Rep1(i, 2, mn) {
		int le = i;
		while (i + 1 <= mn && !isp[i + 1]) {
			i++;
		}
		yaru(le, i, 0,0);
	}
}

ll sum[1 << 17];
int cnt[1 << 17];
vector<LP> memo[1 << 17];

LP dfs(int id) {
	LP res = { 0,cnt[id] };
	rep(j, G[id].size()) {
		edge &e = G[id][j];
		LP nex = dfs(e.to);
		nex.first += nex.second*e.dist;
		memo[id].push_back(nex);
		res.first += nex.first;
		res.second += nex.second;
	}
	return res;
}

ll ans = INF;
void invdfs(int id,LP pre) {
	LP val = pre;
	val.second += cnt[id];
	rep(j, memo[id].size()) {
		val.first += memo[id][j].first;
		val.second += memo[id][j].second;
	}
	ans = min(ans, val.first);
	rep(j, G[id].size()) {
		edge &e = G[id][j];
		LP cop = val;
		cop.first -= memo[id][j].first;
		cop.second -= memo[id][j].second;

		cop.first += cop.second*e.dist;
		invdfs(e.to, cop);
	}
}

void solve() {
	init_iss();
	init_g();
	int n; cin >> n;
	rep(i, n) {
		int k; cin >> k;
		cnt[loc[k]]++;
	}
	/*rep1(i, 4) {
		cout << "!! " << loc[i] << endl;
	}

	rep(i, 100) {
		if (G[i].empty())continue;
		rep(j, G[i].size()) {
			edge &e = G[i][j];
			cout << i << " " << e.to << " " << e.dist << endl;
		}
	}*/


	dfs(0);
	invdfs(0, { 0,0 });
	cout << ans << endl;
	
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(7);
	//init();
	//int t; cin >> t; rep(i, t)solve();
	solve();
	stop
		return 0;
}