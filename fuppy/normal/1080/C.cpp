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
#define Sp(p) cout<<setprecision(15)<< fixed<<p;
int dx[4] = { 1,0, -1,0 }, dy[4] = { 0,1,0,-1 };
int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };
#define fio() cin.tie(0); ios::sync_with_stdio(false);
//#define mp make_pair

pair<pll, pll> search(pll xy1, pll xy2, pll xy3, pll xy4) {
  if (xy1.first > xy3.first) {
    swap(xy1, xy3);
    swap(xy2, xy4);
  }
  if (xy2.first < xy3.first || xy2.second < xy3.second || xy1.second > xy4.second) {
    return make_pair(pii(-1, -1), pii(-1, -1));
  }
  pii xy5, xy6;
  if (xy1.second <= xy3.second) {
    xy5.second = xy3.second;
  }
  else {
    xy5.second = xy1.second;
  }
  xy5.first = xy3.first;
  if (xy2.second <= xy4.second) {
    xy6.second = xy2.second;
  }
  else {
    xy6.second = xy4.second;
  }
  if (xy2.first <= xy4.first) {
    xy6.first = xy2.first;
  }
  else {
    xy6.first = xy4.first;
  }
  return make_pair(xy5, xy6);
}

pll get_wb(pll xy1, pll xy2) {
  if (xy1.first == xy2.first || xy1.second == xy2.second) {
    return pll(0, 0);
  }
  pll res = pll(0, 0);
  if (xy1.first % 2 != xy1.second % 2) {
    ll h = xy2.second - xy1.second;
    ll w = h / 2;
    ll b = h - w;
    res = pll(w, b);
    xy1.first++;
  }
  xy2 = xy2 - xy1;
  ll h = xy2.second, w = xy2.first;
  if (h % 2 == 0 && w % 2 == 0) {
    return res + pll(h*w / 2, h*w / 2);
  }
  else if (h % 2 == 1 && w % 2 == 1) {
    return res + pll(h*w / 2 + 1, h*w / 2);
  }
  else {
    return res + pll(h*w / 2, h*w / 2);
  }
}
    
ll area(pll xy1, pll xy2) {
  return (xy2.second - xy1.second) * (xy2.first - xy1.first);
}

int main() {
  fio();
  int q;
  cin >> q;
  while (q--) {
    ll h, w;
    cin >> h >> w;
    pll xy1, xy2;
    cin >> xy1.first >> xy1.second >> xy2.first  >> xy2.second;
    xy1.first--; xy1.second--;
    pll xy3, xy4;
    cin >> xy3.first >> xy3.second >> xy4.first >> xy4.second;
    xy3.first--; xy3.second--;
    auto res = search(xy1, xy2, xy3, xy4);
    pll xy5 = res.first, xy6 = res.second;
    /*
    DEBUG(xy1);DEBUG(xy2);
    DEBUG(xy3);DEBUG(xy4);
    DEBUG(xy5);DEBUG(xy6);
    //*/
    pll ans;
    /*
    DEBUG(get_wb(pll(0, 0), pll(w, h)));
    DEBUG(get_wb(xy1, xy2));
    DEBUG(get_wb(xy3, xy4));
    DEBUG(get_wb(xy5, xy6));
    //*/
    ans = get_wb(pll(0, 0), pll(w, h)) - get_wb(xy1, xy2) - get_wb(xy3, xy4) + get_wb(xy5, xy6);
    //DEBUG(ans);
    ans = ans + pll(area(xy1, xy2) - area(xy5, xy6), 0LL);
    //DEBUG(ans);
    ans = ans + pll(0LL, area(xy3, xy4));
    cout << ans.first << " " << ans.second << endl;
  }
  
}