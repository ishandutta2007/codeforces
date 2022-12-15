#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <cmath>
#include <list>
#include <iomanip>
#include <set>
#include <map>
#include <sstream>
#include <fstream>
#include <iterator>

using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define RFOR(i,b,a) for (int i = (b)-1; i >= (a); i--)
#define ITER(it,a) for (__typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define FILL(a,value) memset(a, value, sizeof(a))

#define SZ(a) (int)a.size()
#define ALL(a) a.begin(), a.end()
#define PB push_back
#define MP make_pair
#define x first
#define y second

typedef unsigned long long LL;
typedef vector<int> VI;
typedef pair<LL, LL> PII;
typedef pair<double, double> PDD;

const double PI = acos(-1.0);
const int MOD = 998244353;
const LL LINF = MOD * (LL)MOD;

/*int n, k;
LL ans = 0;
LL ans2 = 1;
const int MX = 4194304;
int mx[2*MX];
int pos[300007];

int mval(int l, int r) {
  int res = 0;
  while (l < r) {
    if (l%2 == 1) {res = max(res, mx[l]); l++;}
    if (r%2 == 0) {res = max(res, mx[r]), r--;}
    l /= 2;
    r /= 2;
  }
  return res;
}

int XXX = MX;
int main()
{
  cin >> n;
  FOR (i,0,n) {cin >> mx[i+MX]; pos[mx[i+MX]] = i+MX;}
  RFOR (i, MX, 1) mx[i] = max(mx[2*i], mx[2*i+1]);
  FOR (i,0,n) {
    // cout << mx[1]<<" ";
    int x; cin >> x;
    int res = mval(MX, MX+x-1);
    int from;
    if (res != 0) from = pos[res];
    else { while (mx[XXX] == 0) XXX++; from = XXX; }
    cout << from-XXX << endl;
    mx[from] = 0;
    while (from > 1) {
      from /= 2;
      mx[from] = max(mx[from*2], mx[from*2+1]);
    }
  }
  return 0;
}*/

string S;
int t;

int main() {
  cin >> t;
  FOR (i,0,t)
  {
    cin >> S;
    string ans = "";

    int l = 0, r = S.size() - 1;
    while (l < r && S[l] == S[r]) {
      ans += S[l];
      l++; r--;
    }
    if (l >= r) {
      cout << ans;
      if (l == r) cout << S[l];
      reverse(ans.begin(), ans.end());
      cout << ans << "\n";
      continue;
    }
    string s = "", X1 = "", X2 = "";
    int n = r-l+1;
    FOR (i,l,r+1) s += S[i];

    vector<int> d1 (n);
    l=0, r=-1;
    for (int i=0; i<n; ++i) {
      int k = i>r ? 1 : min (d1[l+r-i], r-i+1);
      while (i+k < n && i-k >= 0 && s[i+k] == s[i-k])  ++k;
      d1[i] = k;
      if (i+k-1 > r)
        l = i-k+1,  r = i+k-1;
    }
    vector<int> d2 (n);
    l=0, r=-1;
    for (int i=0; i<n; ++i) {
      int k = i>r ? 0 : min (d2[l+r-i+1], r-i+1);
      while (i+k < n && i-k-1 >= 0 && s[i+k] == s[i-k-1])  ++k;
      d2[i] = k;
      if (i+k-1 > r)
        l = i-k,  r = i+k-1;
    }

    int f = 0;
    FOR (i,0,n) if (d1[i]-1 == i) f = 2*i+1;
    FOR (i,0,n) if (d2[i] == i && 2*i > f) f = 2*i;
    //cout << f << endl;
    FOR (i,0,f) X1 += s[i];

    //FOR (i,0,n) cout << d1[i]<<" ";
    //cout << "|"; FOR (i,0,n) cout << d2[i]<<" "; cout << endl;

    f = 0;
    FOR (i,0,n) d2[i] = 0;
    reverse(d1.begin(), d1.end());
    reverse(s.begin(), s.end());
    l=0, r=-1;
    for (int i=0; i<n; ++i) {
      int k = i>r ? 0 : min (d2[l+r-i+1], r-i+1);
      while (i+k < n && i-k-1 >= 0 && s[i+k] == s[i-k-1])  ++k;
      d2[i] = k;
      if (i+k-1 > r)
        l = i-k,  r = i+k-1;
    }

    FOR (i,0,n) if (d1[i]-1 == i) f = 2*i+1;
    FOR (i,0,n) if (d2[i] == i && 2*i > f) f = 2*i;
    //cout << f << endl;
    FOR (i,0,f) X2 += s[i];

    //cout << "*" <<ans;
    cout << ans;
    if (X1.length() >= X2.length()) cout << X1; else cout << X2;
    reverse(ans.begin(), ans.end());
    cout << ans << "\n";
  }
  return 0;
}