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
  vi color(256, -1);
  color[0] = 0;
  int n, k;
  cin >> n >> k;
  vi a(n);
  rep(i, n) {
    cin >> a[i];
  }
  vi ans(n);
  rep (i, n) {
    //DEBUG(i);
    if (color[a[i]] != -1) {
      ans[i] = color[a[i]];
    }
    else {
      int idx = -1;
      for (int j = a[i] - 1; j >= max(0, a[i] - k + 1); j--) {
	if (color[j] != -1) {
	  idx = j;
	  break;
	}
      }
      //DEBUG(idx);
      if (idx == -1) {
	for (int j = a[i]; j >= max(0, a[i] - k + 1); j--) {
	  color[j] = a[i] - k + 1;
	}
      }
      else {
	int mi;
	int c = color[idx];
	for (int j = idx; j >= 0; j--) {
	  if (color[j] == c) {
	    mi = j;
	  }
	  else {
	    break;
	  }
	}
	//DEBUG(c);
	//DEBUG(mi);
	if (mi + k - 1 >= a[i]) {
	  for (int j = idx + 1; j <= a[i]; j++) {
	    color[j] = c;
	  }
	}
	else {
	  for (int j = a[i]; j >= idx + 1; j--) {
	    color[j] = idx + 1;
	  }
	}
      }
      ans[i] = color[a[i]];
    }
    //DEBUG_VEC(color);
  }
  //DEBUG_VEC(color);
  rep (i, n) {
    cout << ans[i] << " ";
  }
  cout << endl;
}