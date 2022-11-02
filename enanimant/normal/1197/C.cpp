// July 22, 2019
//

/*

*/


#include <bits/stdc++.h>

using namespace std;


int n, k;
vector<int> a;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif


  cin >> n >> k;
  a.resize(n);
  vector<int> d;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (i > 0) {
      d.push_back(a[i] - a[i - 1]);
    }
  }
  sort(d.begin(), d.end());
  long long ans = 0;
  for (int i = 0; i < n - k; i++) {
    ans += d[i];
  }
  cout << ans << '\n';


  return 0;
}