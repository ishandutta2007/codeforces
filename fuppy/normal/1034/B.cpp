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

int main() {
  ll h, w;
  cin >> h >> w;
  if (h > w) {
    swap(h, w);
  }
  if (h >= 3) {
    if (h * w % 2 == 0) {
      cout << h * w << endl;
    }
    else {
      cout << h * w - 1 << endl;
    }
  }
  else if (h == 2) {
    if (w == 1 || w == 2) {
      cout << 0 << endl;
    }
    else if (w == 3) {
      cout << 4 << endl;
    }
    else if (w == 7) {
      cout << 12 << endl;
    }
    else {
      cout << h * w << endl;
    }
  }
  else if (h == 1) {
    ll w2 = w % 6;
    if (w2 <= 3) {
      cout << w - w2 << endl;
    }
    else if (w2 == 4) {
      cout << w - 2 << endl;
    }
    else if (w2 == 5) {
      cout << w - 1 << endl;
    }
    else {
      cout << w << endl;
    }
  }
}

/*/
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

const int N = 15000010;
vector<bool> isprime(N, true);
vii soinsu(N);
vi prime_;
vi cnt(N);

void prime(vector<bool> &isprime, vii &soinsu) {
	ll i, j;
	isprime[0] = isprime[1] = false;
	for (i = 2; i < isprime.size(); i++) {
		if (isprime[i]) {
			soinsu[i].push_back(i);
			for (j = 2; i*j < isprime.size(); j++) {
				isprime[i*j] = false;
				soinsu[i * j].push_back(i);
			}
		}
	}
}


int main () {
  prime(isprime, soinsu);
  int n;
  scanf(" %d", &n);
  vi a(n);
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
    rep (j, soinsu[a[i]].size()) {
      cnt[soinsu[a[i]][j]]++;
    }
  }
  int ans = n - 1;
  rep (i, N) {
    ans = min(ans, n - cnt[i]);
  }
  cout << ans << endl;
}
*/