#include <bits/stdc++.h>
#include <unistd.h>
 
using namespace std;
 
#define DEBUG(x) cerr<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cerr<<#v<<":";for(int i=0;i<v.size();i++) cerr<<" "<<v[i]; cerr<<endl
#define DEBUG_MAT(v) cerr<<#v<<endl;for(int i=0;i<v.size();i++){for(int j=0;j<v[i].size();j++) {cerr<<v[i][j]<<" ";}cerr<<endl;}
 
 
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
const ll INF = (ll)1e18 + 1;
//const ll MOD = 1000000007;
const ll MOD = 998244353;
const double pi = 3.14159265358979323846;
#define Sp(p) cout<<setprecision(15)<< fixed<<p<<endl;
int dx[4] = { -1,0, 1,0 }, dy[4] = { 0,1,0,-1 };
int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };
#define fio() cin.tie(0); ios::sync_with_stdio(false);
// #define mp make_pair
//#define endl '\n'

#define int ll

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

ll lcm(ll a, ll b) {
  return (a / gcd(a, b))*b;
}


signed main() {
  fio();
  int q;
  //scanf("%d", &q);
  cin >> q;
  rep (_, q) {
    int n;
    //scanf("%d", &n);
    cin >> n;
    vl p(n);
    rep (i, n) {
      //scanf("%lld", &p[i]);
      cin >> p[i];
    }

    sort(all(p));
    reverse(all(p));
    
    int x, a, y, b;
    //scanf("%d %d %d %d", &x, &a, &y, &b);
    cin >> x >> a >> y >> b;
    
    if (x < y) {
      swap(x, y);
      swap(a, b);
    }
    
    ll k;
    //scanf("%lld", &k);
    cin >> k;

    ll g = lcm(a, b);

    int numg = n / g;
    int numa = n / a - numg, numb = n / b - numg;

    ll ans = 0;
    rep (i, numg) {
      ans += p[i] / 100 * (x + y);
    }
    for (int i = numg; i < numg + numa; i++) {
      ans += p[i] / 100 * x;
    }
    for (int i = numg + numa; i < numg + numa + numb; i++) {
      ans += p[i] / 100 * y;
    }

    if (ans < k) {
      cout << -1 << '\n';
      //printf("-1\n");
      continue;
    }

    int ng = 0, ok = n;
    while (ng + 1 < ok) {
      int mid = (ng + ok) / 2;
      int numg = mid / g;
      int numa = mid / a - numg, numb = mid / b - numg;
      
      ll ans = 0;
      rep (i, numg) {
        ans += p[i] / 100 * (x + y);
      }
      for (int i = numg; i < numg + numa; i++) {
        ans += p[i] / 100 * x;
      }
      for (int i = numg + numa; i < numg + numa + numb; i++) {
        ans += p[i] / 100 * y;
      }
      
      if (ans < k) ng = mid;
      else ok = mid;
    }
    //printf("%d\n", ok);
    cout << ok << '\n';
  }
}