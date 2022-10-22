#include "bits/stdc++.h"
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
#define pll pair<ll, ll>
#define pis pair<int,string>
#define psi pair<string,int>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rep1(i, n) for (int i = 1; i <= n; i++)
const int inf = 1000000001;
const ll INF = 1e18;
const ll MOD = 1000000007;
const double pi = 3.14159265358979323846;
#define Sp(p) cout<<setprecision(15)<<fixed<<p<<endl;
int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };

vector<map<ll, ll> > a(100010);

int main() {
  int n, m;
  cin >> n >> m;
  ll ans = 0;
  rep (i, n) {
    a[i][-1] = 0;
  }
  
  rep (i, m) {
    //DEBUG(i);
    ll u, v, w;
    cin >> u >> v >> w;
    u--; v--;
    ll num;
    auto itr = a[u].lower_bound(w);
    itr--;
    num = itr->second + 1;
    ans = max(ans, num);
    // DEBUG(num);
    if (a[v].empty()) {
      a[v][w] = num;
      continue;
    }
    itr = a[v].lower_bound(w + 1);
    itr--;
    if (itr->second >= num) {
      continue;
    }
    else {
      a[v][w] = num;
      while (true) {
	auto itr = a[v].lower_bound(w + 1);
	if (itr == a[v].end()) break;
	if (itr->second > num) break;
	a[v].erase(itr);
      }
    }
  }
  
  cout << ans << endl;
}