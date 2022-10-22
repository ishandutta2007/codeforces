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

struct P {
  int x, y, z, i;
  P(){}
  P(int x, int y, int z, int i):x(x), y(y), z(z), i(i){}
  bool operator<( const P& ot ) const {
    pair<pii, int> me = make_pair(pii(x, y), z);
    pair<pii, int> ai = make_pair(pii(ot.x, ot.y), ot.z);
    return me < ai;
  }
};

int main() {
  fio();
  int n;
  cin >> n;
  vector<P> p(n);
  set<int> st;
  rep (i, n) {
    int x, y, z;
    cin >> x >> y >> z;
    st.insert(x);
    st.insert(y);
    st.insert(z);
    p[i] = P(x, y, z, i);
  }
  map<int, int> mp;
  int cnt = 0;
  for (auto itr = st.begin(); itr != st.end(); itr++) {
    mp[*itr] = cnt++;
  }
  rep (i, n) {
    p[i].x = mp[p[i].x];
    p[i].y = mp[p[i].y];
    p[i].z = mp[p[i].z];
  }
  
  sort(all(p));
  vector<vector<P>> x2(cnt);
  vector<vector<bool>> used(cnt);
  rep (i, n) {
    x2[p[i].x].push_back(p[i]);
    used[p[i].x].push_back(false);
  }

  rep (i, cnt) {
    for (int j = 0; j + 1 < x2[i].size(); j++) {
      if (used[i][j]) continue;
      if (x2[i][j].y == x2[i][j + 1].y) {
        cout << x2[i][j].i + 1 << " " << x2[i][j + 1].i + 1 << '\n';
        used[i][j] = used[i][j + 1] = true;
      }
    }
  }
  
  rep (i, cnt) {
    int pre = -1;
    rep (j, x2[i].size()) {
      if (used[i][j]) continue;
      if (pre == -1) {
        pre = j;
      }
      else {
        cout << x2[i][pre].i + 1 << " " << x2[i][j].i + 1 << '\n';
        used[i][pre] = used[i][j] = true;
        pre = -1;
      }
    }
  }

  int pre = -1;
  rep (i, cnt) {
    rep (j, x2[i].size()) {
      if (used[i][j]) continue;
      if (pre == -1) {
        pre = x2[i][j].i;
      }
      else {
        cout << pre + 1 << " " << x2[i][j].i + 1 << '\n';
        pre = -1;
      }
    }
    
  }
}