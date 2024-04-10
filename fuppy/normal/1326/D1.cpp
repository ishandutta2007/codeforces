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
//const ll MOD = 1000000007;
const ll MOD = 998244353;
// #define mp make_pair
//#define endl '\n'

class Manacher {
public:
  string s, t;
  vi a;

  Manacher (string s): s(s) {
    rep (i, s.size()) {
      t.push_back(s[i]);
      if (i != s.size() - 1) t.push_back('?');
    }
    a.resize(t.size());
    int i = 0, j = 0;
    while (i < t.size()) {
      while (i-j >= 0 && i+j < t.size() && t[i-j] == t[i+j]) ++j;
      a[i] = j;
      int k = 1;
      while (i-k >= 0 && i+k < t.size() && k+a[i-k] < j) a[i+k] = a[i-k], ++k;
      i += k; j -= k;
    }
  }

  // i
  int length(int i) {
    int len_ori = 2*a[2*i] - 1;
    if (len_ori % 4 == 1) return len_ori / 2 + 1;
    if (len_ori % 4 == 3) return len_ori / 2;
    assert(false);
  }

  // i, i+1
  int length(int i, int j) {
    assert(j == i + 1);
    int len_ori = 2*a[2*i + 1] - 1;
    if (len_ori % 4 == 1) return len_ori / 2;
    if (len_ori % 4 == 3) return len_ori / 2 + 1;
    assert(false);
  }
};




void solve() {
    string s;
    cin >> s;
    int n = s.size();
    int l = 0, r = n - 1;
    int cnt = 0;
    while (l <= r) {
        if (s[l] == s[r]) {
            if (l == r) cnt++;
            else cnt += 2;
            l++;
            r--;
        }
        else break;
    }

    if (l > r) {
        cout << s << '\n';
        return;
    }
    string head = s.substr(0, l), tail = s.substr(r + 1, n - (r + 1));

    s = s.substr(l, r - l + 1);
    Manacher man(s);
    pii add = pii(0, -1);

    rep (i, s.size()) {
        int len = man.length(i);
        int ini = i - len / 2;
        int en = i + len / 2;
        if (ini == 0 or en == s.size() - 1) {
            chmax(add, pii(len, i));
        }
    }
    string t1 = s.substr(add.second - add.first / 2, add.first);

    add = pii(0, -1);
    rep (i, s.size() - 1) {
        int len = man.length(i, i + 1);
        int ini = i - (len / 2 - 1);
        int en = i + len / 2;
        if (ini == 0 or en == s.size() - 1) {
            chmax(add, pii(len, i));
        }
    }
    string t2;
    if (add.second >= 0) {
        t2 = s.substr(add.second - (add.first / 2 - 1), add.first);
    }
    string ans;
    if (t1.size() < t2.size()) {
        ans = head + t2 + tail;
    }
    else {
        ans = head + t1 + tail;
    }
    cout << ans << '\n';
}

signed main() {
    fio();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

}