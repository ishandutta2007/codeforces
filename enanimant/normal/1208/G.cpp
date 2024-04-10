// August 25, 2019
// https://codeforces.com/contest/1208/problem/G

/*
Submit the next morning.

The last problem is going to be impossible...
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


  int n, k;
  cin >> n >> k;
  if (k == 1) {
    cout << "3\n";
    return 0;
  }
  vector<int> phi(n + 1); // Euler's totient function
  iota(phi.begin(), phi.end(), 0);
  // use the identity phi[n] = sum(phi[d]) over d dividing n
  for (int i = 1; i <= n; i++) {
    for (int j = i + i; j <= n; j += i) {
      phi[j] -= phi[i];
    }
  }
  sort(phi.begin() + 1, phi.end());
  // we will always take an even-sided polygon for k >= 2 because
  // phi[n] >= 4 for all odd numbers n >= 5 (why?)
  cout << accumulate(phi.begin() + 1, phi.begin() + k + 3, 0LL) << '\n';


  return 0;
}