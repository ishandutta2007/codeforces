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
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define rep1(i,n) for(ll i=1;i<=(ll)(n);i++)
#define rrep(i,n) for(ll i=(ll)(n)-1;i>=0;i--)
#define rrep1(i,n) for(ll i=(ll)(n);i>0;i--)
#define REP(i,a,b) for(ll i=(ll)a;i<(ll)b;i++)
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
#define mp make_pair



int main() {
  random_device rnd;
  mt19937_64 mt(rnd());
  ll n, k;
  cin >> n >> k;
  ll left = 0, right = n;
  while (true) {
    ll num = (right - left);
    if (num <= 5*k || num <= 3) {
      ll ask = mt() % num + left + 1;
      cout << ask << " " << ask << endl << flush;
      string res;
      cin >> res;
      if (res == "Bad") {
        assert(false);
      }
      else if (res == "Yes") {
        return 0;
      }
      else {
        left = max(left - k, 0LL);
        right = min(right + k, n);
      }
    }
    else {
      ll mid = (left + right) / 2;
      cout << left + 1 << " " << mid + 1 << endl << flush;
      string res;
      cin >> res;
      if (res == "Bad") {
        assert(false);
      }
      else if (res == "Yes") {
        left = max(left - k, 0LL);
        right = min(n, mid + 1 + k);
      }
      else {
        left = max(mid + 1 - k, 0LL);
        right = min(right + k, n);
      }
    } 
  }
}

/*
int main(){
  fio();
  int n;
  ll t;
  cin >> n >> t;
  vl a(n);
  rep (i, n) {
    cin >> a[i];
  }
  vl x(n);
  ll pre = 0;
  int nokori = 0;
  rep (i, n) {
    cin >> x[i];
    if (i + 1 > x[i]) {
      cout << "No" << endl;
      return 0;
    }
    x[i]--;
    if (pre > x[i]) {
      cout << "No" << endl;
      return 0;
    }
    pre = x[i];
  }
  vl mi(n), ma(n, INF);
  rep (i, n) {
    mi[i] = a[i] + t;
  }
  int ma2 = -1;
  rep (i, n) {
    if (i <= ma2) {
      mi[i - 1] = a[i] + t;
    }
    ma2 = x[i];
  }
  rep (i, n) {
    if (x[i] < n - 1) {
      ma[x[i]] = min(ma[x[i]], t + a[x[i] + 1]);
    }
  }
  pre = -1;
  vl ans;
  rep (i, n) {
    if (mi[i] >= ma[i]) {
      cout << "No" << endl;
      return 0;
    }
    ll nex = pre + 1;
    if (nex >= ma[i]) {
      cout << "No" << endl;
      return 0;
    }
    if (nex < mi[i]) {
      nex = mi[i];
    }
    ans.push_back(nex);
    pre = nex;
  }
  cout << "Yes" << endl;
  rep (i, n) {
    cout << ans[i] << " ";
  }
  cout << endl;
    
}
*/