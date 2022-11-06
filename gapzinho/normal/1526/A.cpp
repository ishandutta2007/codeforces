#include <bits/stdc++.h>
using namespace std;

#define int long long
// #define double long double

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;

const int ms = 2e5+5;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;


int a[ms];

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie();
    int t;
    cin >> t;
    while(t--) {
      int n;
      cin >> n;
      for(int i = 0; i < n+n; i++) {
        cin>> a[i];
      }
      sort(a, a+n+n);
      for(int i = 0; i < n; i++) {
        cout << a[i] << ' ' << a[n+n-i-1] << ' ';
      }
      cout << '\n';
    }

    return 0;
}