#include <bits/stdc++.h>
using namespace std;

// #define int long long
// #define double long double

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;

const int ms = 1e4+5;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;


int n;
int a[ms];
vector<int> x = {11, 111, 1111};


int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie();
    int t;
    cin >> t;
    a[0] = 1;
    for(int i = 1; i < ms; i++) {
      for(int k : x) {
        if(i >= k && a[i-k]) a[i] = 1;
      }
    }
    while(t--) {
        cin >> n;
        if(n >= ms) {
          cout << "YES\n";
        } else {
          if(a[n]) cout << "YES\n";
          else cout << "NO\n";
        }
    }
    return 0;
}