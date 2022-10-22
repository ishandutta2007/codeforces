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
  int n;
  cin >> n;
  vi a(n);
  rep (i, n) {
    cin >> a[i];
  }
  for (int i = 2; i <= 10000; i++) {
    int temp = i*i;
    rep (j, n) {
      while (a[j] % temp == 0 && a[j] != 0) {
	a[j] /= temp;
      }
    }
  }

  vector<pair<int, bool> > num(n);
  vi ans(n);
  rep (i, n) {
    num[i].first = 1;
    if (a[i] == 0) {
      num[i].second = true;
    }
    else {
      num[i].second = false;
    }
    ans[0]++;
    bool flag = false;
    for (int j = i - 1; j >= 0; j--) {
      if (a[i] == a[j] || a[i] == 0) {
	flag = true;
      }
      if (!flag && !num[j].second) {
	num[j].first++;
      }
      if (num[j].second == true) {
	if (a[i] != 0) {
	  num[j].second = false;
	}
      }
      ans[num[j].first - 1]++;
    }
  }
  rep (i, n) {
    cout << ans[i] << " ";
  }
  cout << endl;
}