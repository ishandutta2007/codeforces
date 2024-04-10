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
typedef double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-12;
const ld pi = acos(-1.0);

ll mod_pow(ll x, ll n, ll m = mod) {
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

const int max_n = 1 << 20;
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

ll gcd(ll a, ll b) {
	if (a < b)swap(a, b);
	while (b) {
		ll r = a % b; a = b; b = r;
	}
	return a;
}

struct edge { int to; int cap; int rev; };
struct Dinic {
private:
	int n;
	vector<int> dist, iter;
public:
	vector<vector<edge>> v;
	Dinic(int sz) :n(sz), v(sz), dist(sz), iter(sz) {}

	void add_edge(int from, int to, int cap, int dec = 0) {
		int x = v[to].size(), y = v[from].size();
		v[from].push_back({ to,cap - dec,x });
		v[to].push_back({ from,dec,y });
	}

	void bfs(int s) {
		fill(dist.begin(), dist.end(), -1);
		queue<int> q;
		dist[s] = 0;
		q.push(s);
		while (q.size()) {
			int x = q.front(); q.pop();
			rep(i, v[x].size()) {
				edge& e = v[x][i];
				if (e.cap > 0 && dist[e.to] < 0) {
					dist[e.to] = dist[x] + 1;
					q.push(e.to);
				}
			}
		}
	}

	int dfs(int x, int t, int f) {
		if (x == t)return f;
		for (int& i = iter[x]; i < (int)v[x].size(); ++i) {
			edge& e = v[x][i];
			if (e.cap > 0 && dist[x] < dist[e.to]) {
				int d = dfs(e.to, t, min(f, e.cap));
				if (d > 0) {
					e.cap -= d;
					v[e.to][e.rev].cap += d;
					return d;
				}
			}
		}
		return 0;
	}

	int max_flow(int s, int t) {
		int flow = 0;
		while (1) {
			bfs(s);
			if (dist[t] < 0)return flow;
			fill(iter.begin(), iter.end(), 0);
			int f;
			while ((f = dfs(s, t, 1 << 30)) > 0)flow += f;
		}
	}
};

string ans[3000];
void solve() {
	int n, m; cin >> n >> m;
	vector<int> a(m);
	rep(i, m)cin >> a[i];
	int sum = 0;
	rep(i, m) {
		a[i] -= (n - 1);
		sum += a[i];
	}
	int ma = (n - m) * a.back() + sum;
	if (ma < 0) {
		cout << "no\n"; return;
	}
	rep(i, n - m) {
		int x = sum + (n - m - 1 - i) * a[m - 1];
		if(n-1-2*i>0)x = min(x, n - 1 - 2 * i);
		a.push_back(-x);
		sum -= x;
	}
	//rep(i, n)cout << a[i] << " "; cout << "\n";
	sort(all(a));
	rep(i, n)ans[i].resize(n);
	rep(i, n)rep(j, n) {
		if (i == j)ans[i][j] = 'X';
		else ans[i][j] = 'D';
	}
	vector<int> cnt(n);
	rep(i, n)cnt[i] = a[i];
	vector<bool> used(n);
	rep(i, n) {
		/*rep(j, n) {
			cout << cnt[j] << " ";
		}
		cout << "\n";*/
		vector<P> v;
		rep(j, n) {
			if (used[j])continue;
			v.push_back({ cnt[j],j });
		}
		sort(all(v));
		if (v[0].first<-(n - 1 - i) || v.back().first>n - 1 - i) {
			cout << "no\n"; return;
		}
		int id = 0;
		if (v[0].first + n - 1 - i < n - 1 - v.back().first) {
			id = v[0].second;
			rep(j, -cnt[id]) {
				int to = v[v.size() - 1 - j].second;
				ans[id][to] = 'L';
				ans[to][id] = 'W';
				cnt[to]--;
			}
			//cout << id << "\n";
			used[id] = true;
		}
		else {
			id = v.back().second;
			rep(j, cnt[id]) {
				int to = v[j].second;
				ans[id][to] = 'W';
				ans[to][id] = 'L';
				cnt[to]++;
			}
			//cout << id << "\n";
			used[id] = true;
		}
	}
	cout << "yes\n";
	rep(i, n)cout << ans[i] << "\n";
}





signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init_f();
	//init();
	//expr();
	//int t; cin >> t; rep(i, t)
	solve();
	return 0;

}