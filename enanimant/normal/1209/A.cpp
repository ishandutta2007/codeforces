// September 14, 2019
//

/*

*/


#include <bits/stdc++.h>

using namespace std;


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif


  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  vector<bool> mark(n, false);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (mark[i]) {
      continue;
    }
    mark[i] = true;
    ans++;
    for (int j = i + 1; j < n; j++) {
      if (a[j] % a[i] == 0) {
        mark[j] = true;
      }
    }
  }
  cout << ans << '\n';


  return 0;
}