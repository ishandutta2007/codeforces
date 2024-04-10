#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int mn[100005], mx[100005];

int main() {
  ios::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;

  memset(mn, -1, sizeof(mn));
  memset(mx, -1, sizeof(mx));

  for (int i = 0; i < k; ++i) {
    int a;
    cin >> a;

    if (mn[a] == -1) mn[a] = mx[a] = i;
    else {
      mn[a] = min(mn[a], i);
      mx[a] = max(mx[a], i);
    }
  }

  int ans = 0;

  for (int x = 1; x <= n; ++x) {
    if (mn[x] == -1) {
      ans++;
      if (x - 1 >= 1) ++ans;
      if (x + 1 <= n) ++ans;
    } else {
      if (x - 1 >= 1 && (mx[x - 1] == -1 || mx[x - 1] <= mn[x])) ++ans; 
      if (x + 1 <= n && (mx[x + 1] == -1 || mx[x + 1] <= mn[x])) ++ans; 
    }
  }

  cout << ans << endl;
  return 0;
}