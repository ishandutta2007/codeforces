#include <bits/stdc++.h>
 
//#include <unistd.h>
//#include <iostream>
 
using namespace std;
 
#define DEBUG(x) cerr<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cerr<<#v<<":";for(int i=0;i<v.size();i++) cerr<<" "<<v[i]; cerr<<endl;
#define DEBUG_MAT(v) cerr<<#v<<endl;for(int i=0;i<v.size();i++){for(int j=0;j<v[i].size();j++) {cerr<<v[i][j]<<" ";}cerr<<endl;}
typedef long long ll;
//#define int ll
 
#define vi vector<int>
#define vl vector<ll>
#define vii vector< vector<int> >
#define vll vector< vector<ll> >
#define vs vector<string>
#define pii pair<int,int>
#define pis pair<int,string>
#define psi pair<string,int>
#define pll pair<ll,ll>
template<class S, class T> pair<S, T> operator+(const pair<S, T> &s, const pair<S, T> &t) { return pair<S, T>(s.first + t.first, s.second + t.second); }
template<class S, class T> pair<S, T> operator-(const pair<S, T> &s, const pair<S, T> &t) { return pair<S, T>(s.first - t.first, s.second - t.second); }
template<class S, class T> ostream& operator<<(ostream& os, pair<S, T> p) { os << "(" << p.first << ", " << p.second << ")"; return os; }
#define X first
#define Y second
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define rrep(i,n) for(int i=(n)-1;i>=0;i--)
#define rrep1(i,n) for(int i=(n);i>0;i--)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define in(x, a, b) (a <= x && x < b)
#define all(c) c.begin(),c.end()
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a = b; return 1; } return 0; }
#define UNIQUE(v) v.erase(std::unique(v.begin(), v.end()), v.end());
const ll inf = 1000000001;
const ll INF = (ll)1e18 + 1;
const long double pi = 3.1415926535897932384626433832795028841971L;
#define Sp(p) cout<<setprecision(25)<< fixed<<p<<endl;
//int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
//int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };
vi dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};
vi dx2 = { 1,1,0,-1,-1,-1,0,1 }, dy2 = { 0,1,1,1,0,-1,-1,-1 };
#define fio() cin.tie(0); ios::sync_with_stdio(false);
const ll MOD = 1000000007;
//const ll MOD = 998244353;
// #define mp make_pair
//#define endl '\n'

const int M = 1e6;
bitset<M + 1> is_prime;

struct dice {
  mt19937 mt;
  dice() : mt(chrono::steady_clock::now().time_since_epoch().count()) {}
  // [0, x)
  ll operator()(ll x) { return this->operator()(0, x); }
  // [x, y)
  ll operator()(ll x, ll y) {
	uniform_int_distribution<ll> dist(x, y - 1);
	return dist(mt);
  }
  vl operator()(int n, ll x, ll y) {
	vl res(n);
	for (int i = 0; i < n; i++) res[i] = this->operator()(x, y);
	return res;
  }
} rnd;

signed main() {
	clock_t start = clock();
	fio();
	is_prime.set();
	int n;
	cin >> n;
	vl a(n);
	rep (i, n) cin >> a[i];

	is_prime[0] = is_prime[1] = false;
	vl primes;
	for (int i = 2; i <= M; i++) {
		if (is_prime[i]) {
			primes.push_back(i);
			for (int j = 2; i * j <= M; j++) {
				is_prime[i * j] = true;
			}
		}
	}

	ll ans = INF;
	set<ll> st;
	int cnt = 0;
	while (static_cast<double>(clock() - start) / CLOCKS_PER_SEC * 1000.0 <= 2400) {
		int i = rnd(n);
		int add = rnd(5);
		add -= 2;
		ll x = a[i] + add;
		if (x <= 0) continue;
		vl p;
		for (ll pr: primes) {
			if (x % pr == 0) {
				p.push_back(pr);
				while (x % pr == 0) x /= pr;
			}
			if (x == 1) break;
		}
		if (x != 1) p.push_back(x);

		ll pr = -1;
		rep (_, p.size()) {
			int idx = rnd(p.size());
			if (st.count(p[idx])) continue;
			pr = p[idx];
			break;
		}
		if (pr == -1) continue;
		st.insert(pr);

		ll res = 0;
		rep (i, n) {
			ll x1 = a[i] / pr * pr;
			ll x2 = x1 + pr;
			if (x1 == 0) x1 = INF;
			ll add = min(abs(x1 - a[i]), abs(x2 - a[i]));
			res += add;
			if (res >= ans) break;
		}
		chmin(ans, res);
	}
	cout << ans << endl;
}