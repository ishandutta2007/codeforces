#include <bits/stdc++.h>

using namespace std;

#define DEBUG(x) cerr<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cerr<<#v<<":";for(int i=0;i<v.size();i++) cerr<<" "<<v[i]; cerr<<endl

typedef long long ll;
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
const ll INF = 1e18;
const ll MOD = 1000000007;
//const ll MOD = 998244353;
const double pi = 3.14159265358979323846;
#define Sp(p) cout<<setprecision(15)<< fixed<<p<<endl;
int dx[4] = { 1,0, -1,0 }, dy[4] = { 0,1,0,-1 };
int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };
#define fio() cin.tie(0); ios::sync_with_stdio(false);
#define mp make_pair

ll gcd(ll a, ll b) {
	if (b > a) {
		swap(a, b);
	}
	ll r = a%b;
	while (r != 0) {
		a = b;
		b = r;
		r = a%b;
	}
	return b;
}

const int MAXN = 301000;

ll mod_pow(ll x, ll p, ll M = MOD) {
	ll a = 1;
	while (p) {
		if (p % 2)
			a = a*x%M;
		x = x*x%M;
		p /= 2;
	}
	return a;
}

ll mod_inverse(ll a, ll M = MOD) {
	return mod_pow(a, M - 2, M);
}

void set_fact(ll n, vl &fact, vl &rfact, ll M = MOD) {
	fact[0] = fact[1] = rfact[0] = rfact[1] = 1;
	for (ll i = 2; i <= n; i++) {
		fact[i] = i * fact[i - 1] % M;
		rfact[i] = mod_inverse(fact[i], M);
	}
    
}

ll nCr(ll n, ll r, vl &fact, vl &rfact, ll M = MOD) {
  if (r > n) return 0; 
  ll ret = fact[n];
  ret = (ret*rfact[r]) % M;
  ret = (ret*rfact[n - r]) % M;
  return ret;
}

const int MAX = 300010;
vl fact(MAX + 5), fact2(MAX + 5), rfact(MAX + 5), rfact2(MAX + 5);
vll dp(8, vl(MAX)), dp2(8, vl(MAX));


int main() {
  fio();
  int n;
  cin >> n;
  const ll MOD2 = 998244353;
  set_fact(MAX, fact, rfact, MOD);
  set_fact(MAX, fact2, rfact2, MOD2);
  vi a(n);
  rep (i, n) {
    cin >> a[i];
  }
  int g = a[0];
  rep1 (i, n - 1) {
    g = gcd(g, a[i]);
  }
  if (g != 1) {
    cout << -1 << endl;
    return 0;
  }

  vi num(MAX);
  rep (i, n) {
    num[a[i]]++;
  }
  rep1 (i, MAX - 1) {
    for (int j = 2; j * i < MAX; j++) {
      num[i] += num[j * i];
    }
  }
  int m = 8;
  for (int i = 1; i < m; i++) {
    for (int j = MAX - 1; j >= 1; j--) {
      dp[i][j] = nCr(num[j], i, fact, rfact, MOD);
      dp2[i][j] = nCr(num[j], i, fact2, rfact2, MOD2);
      for (int k = 2; j * k < MAX; k++) {
        dp[i][j] -= dp[i][j * k];
        dp[i][j] %= MOD;
        dp2[i][j] -= dp2[i][j * k];
        dp2[i][j] %= MOD2;
      }
    }
  }
  rep1 (i, m - 1) {
    //DEBUG(dp[i][1]);
    //DEBUG(dp2[i][1]);
    if (dp[i][1] != 0 || dp2[i][1] != 0) {
      cout << i << endl;
      return 0;
    }
  }
}