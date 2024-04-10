#include <bits/stdc++.h>

using namespace std;
 
#define DEBUG(x) cout<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cout<<#v<<":";for(int i=0;i<v.size();i++) cout<<" "<<v[i]; cout<<endl
 
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
#define fi first
#define se second
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
#define in(x, a, b) a <= x && x < b
const int inf = 1000000001;
const ll INF = 2e18;
const ll MOD = 1000000007;
//const ll mod = 1000000009;
const double pi = 3.14159265358979323846;
#define Sp(p) cout<<setprecision(15)<< fixed<<p <<endl;
int dx[4] = { 1,0, -1,0 }, dy[4] = { 0,1,0,-1 };
int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };

bool cmp(pair<pll, int> a, pair<pll, int> b) {
  if (a.first.first != b.first.first) {
    return a.first.first < b.first.first;
  }
  else if (a.first.second != b.first.second) {
    return a.first.second > b.first.second;
  }
  else {
    return a.second < b.second;
  }
}

int main() {
  int n;
  cin >> n;
  vector<pair<pll, int> > a(n);
  rep (i, n) {
    cin >> a[i].first.first >> a[i].first.second;
    a[i].second = i;
  }
  sort(all(a), cmp);
  int i0 = -1;
  ll ma = -1;
  vector<pll> ans;
  rep (i, n) {
    if (a[i].first.second <= ma) {
      cout << a[i].second + 1 << " " << a[i0].second + 1 << endl;
      return 0;
    }
    ma = a[i].first.second;
    i0 = i;
  }
  cout << -1 << " " << -1 << endl;
}