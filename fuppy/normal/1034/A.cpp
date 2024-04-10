#include "bits/stdc++.h"

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
const double pi = 3.14159265358979323846;
#define Sp(p) cout<<setprecision(15)<< fixed<<p<<endl;
int dx[4] = { 1,0, -1,0 }, dy[4] = { 0,1,0,-1 };
int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };
#define fio() cin.tie(0); ios::sync_with_stdio(false);
//#define mp make_pair


//*/
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

const int N = 15000100;
vector<bool> isprime(sqrt(N) + 10, true);
vii soinsu(300010);
vi primes;
vi cnt(N);
//map<int, int> mp;

void prime(vector<bool> &isprime, vii &soinsu) {
  ll i, j;
  isprime[0] = isprime[1] = false;
  for (i = 2; i*i <= N; i++) {
    if (isprime[i]) {
      primes.push_back(i);
      for (j = 2; i*j <= sqrt(N); j++) {
        isprime[i*j] = false;
      }
    }
  }
}


int main () {
  int n;
  scanf(" %d", &n);
  vi a(n);
  int idx = 0;
  rep (i, n) {
    scanf(" %d", &a[i]);
  }
  int temp = a[0];
  bool flag = true;
  REP (i, 1, n) {
    if (temp != a[i]) {
      flag = false;
      break;
    }
  }
  if (flag) {
    cout << -1 << endl;
    return 0;
  }
  int g = a[0];
  rep (i, n) {
    g = gcd(g, a[i]);
  }
  
  rep (i, n) {
    a[i] /= g;
  }
  prime(isprime, soinsu);
  rep (i, n) {
    rep (j, primes.size()) {
      int p = primes[j];
      if (p*p > a[i]) {
        break;
      }
      if (a[i] % p == 0) {
        cnt[p]++;
      }
      while (a[i] % p == 0) {
        a[i] /= p;
      }
    }
    if (a[i] > 1) {
      cnt[a[i]]++;
    }   
  }
  sort(all(a));
  int ma = 1;
  int pre = -1;
  int num = 0;
  rep (i, a.size()) {
    if (a[i] == 1) {
      continue;
    }
    if (pre == a[i]) {
      num++;
    }
    else {
      ma = max(ma, num);
      num = 1;
      pre = a[i];
    }
  }
  ma = max(ma, num);
  int ans = n - ma;
  REP (i, 2, N) {
    ans = min(ans, n - cnt[i]);
  }
  cout << ans << endl;
}