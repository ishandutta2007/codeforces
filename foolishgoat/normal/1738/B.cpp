#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> s(n);
  for (int i = n-k; i < n; ++i) {
    cin >> s[i];
  }

  if (k == 1) {
    cout << "YES\n";
    return;
  }
  vector<int> a(n);
  for (int i = n-k+1; i < n; ++i) {
    a[i] = s[i] - s[i-1];
    if (i > n-k+1) {
      if (a[i] < a[i-1]) {
        cout << "NO\n";
        return;
      }
    }
  }
  long long last = a[n-k+1];
  long long sum = s[n-k];
  long long cnt = n-k+1;
  if (cnt * last < sum) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc = 1;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}