#include <bits/stdc++.h>

using namespace std;

const int LG = 20;
const int N = 2e5 + 5;

long long gcd(long long a, long long b) {
  return a ? gcd(b % a, a) : b;
}

long long sp[LG][N];

long long get(int l, int r) {
  int len = r - l + 1;
  int lg = 31 - __builtin_clz(len);
  return gcd(sp[lg][l], sp[lg][r - (1 << lg) + 1]);
}

int testcase() {
  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int m = n-1;
  for (int i = 0; i < m; ++i) {
    sp[0][i] = abs(a[i+1] - a[i]);
  }
  for (int i = 0; i + 1 < LG; ++i) {
    int len = 1 << (i + 1);
    if (len > m) break;
    int half = 1 << i;
    for (int j = 0; j + len <= m; ++j) {
      sp[i + 1][j] = gcd(sp[i][j], sp[i][j + half]);
    }
  }
  int ans = 1;
  for (int i = 0; i < m; ++i) {
    if (sp[0][i] <= 1) continue;
    int low = i, hig = m - 1;
    while (low < hig) {
      int mid = (low + hig + 1) >> 1;
      if (get(i, mid) > 1) {
        low = mid;
      } else {
        hig = mid - 1;
      }
    }
    ans = max(ans, low - i + 2);
  }
  cout << ans << '\n';
  return 0;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc = 1;
  cin >> tc;
  while (tc--) {
    testcase();
  }
  return 0;
}