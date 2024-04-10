// August 19, 2020
// https://codeforces.com/problemset/problem/1370/D

/*

*/


#include <bits/stdc++.h>

using namespace std;


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif
  
  
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int low = 0, high = (int) 1e9;
  while (low < high) {
    int mid = (low + high) >> 1;
    bool ok = false;
    {
      int x = 0, y = 0;
      int need = (k + 1) / 2;
      for (int i = 0; i < n - (k % 2 == 0); i++) {
        if (a[i] <= mid) {
          x++;
          swap(x, y);
        } else {
          x = y = max(x, y);
        }
      }
      if (x >= need || y >= need) {
        ok = true;
      }
    }
    {
      int x = 0, y = 0;
      int need = k / 2;
      for (int i = 1; i < n - (k % 2 == 1); i++) {
        if (a[i] <= mid) {
          x++;
          swap(x, y);
        } else {
          x = y = max(x, y);
        }
      }
      if (x >= need || y >= need) {
        ok = true;
      }
    }
    if (ok) {
      high = mid;
    } else {
      low = mid + 1;
    }
  }
  cout << low << '\n';
  
  
  return 0;
}