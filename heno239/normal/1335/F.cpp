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
#include<numeric>
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
#define all(v) (v).begin(),(v).end()
typedef pair<ll, ll> LP;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-12;
const ld pi = acos(-1.0);

ll mod_pow(ll a, ll n, ll m = mod) {
	ll res = 1;
	while (n) {
		if (n & 1)res = res * a%m;
		a = a * a%m; n >>= 1;
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
const int max_n = 10000;
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

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int nex[1 << 20];
bool isw[1 << 20];
vector<int> rG[1 << 20];
void solve() {
	int h, w; cin >> h >> w;

	rep(i, h*w)rG[i].clear();
	int ans1 = 0, ans2 = 0;
	rep(i, h)rep(j, w) {
		char c; cin >> c;
		isw[i*w + j] = (c == '1');
	}
	rep(i, h*w) {
		char c; cin >> c;
		if (c == 'R') {
			nex[i] = i + 1;
			rG[i + 1].push_back(i);
		}
		else if (c == 'L') {
			nex[i] = i - 1;
			rG[i - 1].push_back(i);
		}
		else if (c == 'U') {
			nex[i] = i - w;
			rG[i - w].push_back(i);
		}
		else {
			nex[i] = i + w;
			rG[i + w].push_back(i);
		}
	}
	vector<bool> used(h*w, false);
	rep(i, h*w) {
		if (used[i])continue;
		stack<int> st;
		int cur = i;
		while (!used[cur]) {
			used[cur] = true;
			st.push(cur);
			cur = nex[cur];
		}
		vector<int> loop;
		loop.push_back(cur);
		while (st.top() != cur) {
			loop.push_back(st.top()); st.pop();
		}
		reverse(all(loop));
		vector<bool> exi(loop.size(),false);

		queue<P> q;
		rep(j, loop.size()) {
			if (!isw[loop[j]])exi[j] = true;
			int pre;
			if (j == 0)pre = loop.back();
			else pre = loop[j - 1];
			for (int to : rG[loop[j]])if(to!=pre) {
				q.push({ to,j - 1 });
			}
		}
		while (!q.empty()) {
			P p = q.front(); q.pop();
			int id = p.first;
			used[id] = true;
			if (p.second < 0)p.second += loop.size();
			if (!isw[id])exi[p.second] = true;
			for (int to : rG[id]) {
				q.push({ to,p.second - 1 });
			}
		}

		ans1 += loop.size();
		rep(j, exi.size())if (exi[j])ans2++;
	}
	//cout << "ans is ";
	cout << ans1 << " " << ans2 << "\n";
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(7);
	//init_f();
	//init();
	//experi();
	int t; cin >> t; rep(i, t)solve();
	//solve();
	stop
		return 0;
}