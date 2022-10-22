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
const int inf = 1000000001;
const ll INF = 1e18;
#define MOD 1000000007
#define mod 1000000009
#define pi 3.14159265358979323846
#define Sp(p) cout<<setprecision(15)<<fixed<<p<<endl;
int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };

int main(){
  int n, m;
  cin >> n >> m;
  vi a(n), b(m);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }

  int asum = 0, bsum = 0;
  int i = 0, j = 0;
  int cnt = 0;
  while (i < n || j < m) {
    //cout << i << " " << j << " " << asum << " " << bsum << " " << cnt << endl;
    if (i == n) {
      bsum += b[j++];
    }
    else if (j == m) {
      asum += a[i++];
    }
    else {
      if (asum < bsum) {
	asum += a[i++];
      }
      else {
	bsum += b[j++];
      }
    }
    if (asum == bsum) {
      cnt++;
      asum = bsum = 0;
    }
  }
  cout << cnt << endl;
   
}