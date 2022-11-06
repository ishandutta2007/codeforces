#include <bits/stdc++.h>
using namespace std;

// #define int long long
// #define double long double

typedef long long ll;
#define endl '\n'

typedef pair<int, int> ii;
typedef pair<ii, int> iii;

const int ms = 5e5+5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9+7;

int n;
int a[ms];
int b[ms];
 
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie();

  int t;
  cin >> t;
  while(t--) {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    for(int i = 0; i < n; i++) {
      if(i == 0) a[i] = inf;
      else a[i] = a[i-1]+1;
      if(s[i] == '1') a[i] = 0;
    }
    for(int i = n-1; i >= 0; i--) {
      if(i == n-1) b[i] = inf;
      else b[i] = b[i+1]+1;
      if(s[i] == '1') b[i] = 0;
    }
    for(int i = 0; i < n; i++) {
      if(s[i] == '1') cout << '1';
      else {
        // cout << endl << a[i] << ' ' << b[i] << endl;
        if(a[i] != b[i] && min(a[i], b[i]) <= m) cout << '1';
        else cout << '0';
      }
    }
    cout << endl;
  }
    
  return 0;
}