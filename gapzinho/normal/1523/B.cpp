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
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
      int x;
      cin >> x;
    }
    cout << n*3 << endl;
    for(int i = 1; i < n; i += 2) {
      cout << "2 " << i << ' ' << i+1 << endl;
      cout << "1 " << i << ' ' << i+1 << endl;
      cout << "2 " << i << ' ' << i+1 << endl;
      cout << "1 " << i << ' ' << i+1 << endl;
      cout << "2 " << i << ' ' << i+1 << endl;
      cout << "1 " << i << ' ' << i+1 << endl;
    }
  }
    
  return 0;
}