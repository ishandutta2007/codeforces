// July 26, 2019
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
  long long moves = 0;
  for (int i = n - 2; i >= 0; i--) {
    if (a[i] >= a[i + 1]) {
      a[i]--;
      if (a[i] < 0) {
        moves++;
      }
      moves++;
    }
  }
  if (moves > 1) {
    cout << "cslnb\n";
    return 0;
  }
  for (int i = 0; i < n; i++) {
    moves += a[i] - i;
  }
  cout << (moves & 1 ? "sjfnb" : "cslnb") << '\n';


  return 0;
}