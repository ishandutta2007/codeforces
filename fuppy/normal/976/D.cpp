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

vector<pii> ans;

void solve(vi d) {
  if (d.empty()) {
    return;
  }
  if (d.size() == 1) {
    int num = d[0] + 1;
    rep (i, num) {
      for (int j = i + 1; j < num; j++) {
	ans.push_back(pii(i, j));
      }
    }
    return;
  }
  int num = d.back() + 1;
  vi d2(d.size() - 2);
  rep(i, d2.size()) {
    d2[i] = d[i + 1] - d[0];
  }
  int before = d.back() + 1 - d[0];
  solve(d2);
  for (int i = before; i < num; i++) {
    for (int j = 0; j < i; j++) {
      if (i == j) {
	continue;
      }
      ans.push_back(pii(i, j));
    }
  }
  return;
}

int main() {
  int n;
  cin >> n;
  vi d(n);
  rep (i, n) {
    cin >> d[i];
  }
  solve(d);
  cout << ans.size() << endl;
  rep (i, ans.size()) {
    cout << ans[i].first + 1 << " " << ans[i].second + 1 << endl;
  }
}