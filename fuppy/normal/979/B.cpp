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


int main() {
  ll n;
  cin >> n;
  vs s(3);
  rep (i, 3) {
    cin >> s[i];
  }
  vl ma(3);
  rep (i, 3) {
    vl num(54, 0);
    rep (j, s[i].size()) {
      if (s[i][j] >= 'A' && s[i][j] <= 'Z') {
        num[s[i][j] - 'A']++;
      }
      else {
        num[(int)(s[i][j] - 'a') + 26]++;
      }
    }
    rep (j, 54) {
      ma[i] = max(ma[i], num[j]);
    }
  }
  rep (i, 3) {
    if (n == 1 && ma[i] == s[i].size()) {
      ma[i] = ma[i] - 1;
    }
    else {
      ma[i] = min(ma[i] + n, (ll)s[i].size());
    }
  }
  if (ma[0] > ma[1] && ma[0] > ma[2]) {
    cout << "Kuro" << endl;
  }
  else if (ma[1] > ma[0] && ma[1] > ma[2]) {
    cout << "Shiro" << endl;
  }
  else if (ma[2] > ma[0] && ma[2] > ma[1]) {
    cout << "Katie" << endl;
  }
  else {
    cout << "Draw" << endl;
  }
}