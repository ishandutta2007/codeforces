#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
typedef pair<int, int> ii;
 
const int ms = 2e6+5;
const int inf = 1e18;
const int mod = 998244353;

int fat[ms];

main() {
  cin.tie(0); ios::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  int ans = 0;
  fat[0] = 1;
  for(int i = 1; i <= n; i++) {
    fat[i] = (fat[i-1] * i) % m;
  }
  for(int i = 1; i <= n; i++) {
    int start = (n-i+1) * (n-i+1) % m;
    ans = (ans + (start * fat[n-i] % m) * fat[i] % m) % m;
  }
  cout << ans << '\n';
}