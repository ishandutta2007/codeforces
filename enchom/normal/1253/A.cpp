#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 1e5 + 10;
 
int n;
int a[N];
 
void solve() {
  cin >> n;
  bool bad = false;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    a[i] = x - a[i];
    if (a[i] < 0) {
      bad = true;
    }
  }
  if (bad)
  {
      puts("NO");
      return;
  }
  int l = 1, r = n;
  while (l <= n && a[l] == 0) ++l;
  while (r > 0 && a[r] == 0) --r;
  if (l > r) {
    puts("YES");
  } else {
    while (l < r && a[l] == a[r]) {
      --r;
    }
    puts(l == r ? "YES" : "NO");  
  }
}
 
int main() {
  ios::sync_with_stdio(false);  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) solve();
  return 0;
}