#include <bits/stdc++.h>
 
using namespace std;
 
#define DEBUG(x) cerr<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cerr<<#v<<":";for(int i=0;i<v.size();i++) cerr<<" "<<v[i]; cerr<<endl;
#define DEBUG_MAT(v) cerr<<#v<<endl;for(int i=0;i<v.size();i++){for(int j=0;j<v[i].size();j++) {cerr<<v[i][j]<<" ";}cerr<<endl;}
typedef long long ll;
// #define int ll
 
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
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define rrep1(i,n) for(int i=(int)(n);i>0;i--)
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
//const ll MOD = 1000000007;
const ll MOD = 998244353;
// #define mp make_pair
//#define endl '\n'

void prime(vector<bool> &isprime /*, vll &soinsu */) {
  ll i, j;
  assert(isprime[0]);
  isprime[0] = isprime[1] = false;
  for (i = 2; i < isprime.size(); i++) {
    if (isprime[i]) {
      // soinsu[i].push_back(i);
      for (j = 2; i*j < isprime.size(); j++) {
        isprime[i*j] = false;
        /*
          soinsu[i * j].push_back(i);
          int temp = i * j;
          while (temp % i == 0) {
          temp /= i;
          }
        */
      }
    }
  }
}

signed main() {
    fio();
    vector<bool> isprime(222222, true);
    prime(isprime);
    int n;
    cin >> n;
    vi a(n);
    rep (i, n) cin >> a[i];

    vi st;
    for (int i = 0; i < 2; i++) {
        for (int x = 1; x * x <= a[i]; x++) {
            if (a[i] % x == 0) {
                int y = a[i] / x;
                if (isprime[x]) {
                    st.push_back(x);
                    isprime[x] = false;
                }
                if (isprime[y]) {
                    st.push_back(y);
                    isprime[y] = false;
                }
            }
        }
    }

    ll ans = 1;
    for (ll g: st) {
        int mi1 = inf, mi2 = inf;
        rep (i, n) {
            int cnt = 0;
            while (a[i] % g == 0) {
                a[i] /= g;
                cnt++;
            }
            if (mi1 > cnt) {
                mi2 = mi1;
                mi1 = cnt;
            }
            else if (mi2 > cnt) {
                mi2 = cnt;
            }

        }
        while (mi2) {
            ans *= g;
            mi2--;
        }
    }

    cout << ans << endl;
}