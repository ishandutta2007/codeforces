#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define int ll

const int N = (int) 5e5 + 7;
const int M = (int) 1e9 + 7;
int n;
int a[N];
int has[100];
int nu[100];
int sum[N];

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    for (int i = 0; i < 100; i++) {
      has[i] = 0;
    }
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      for (int j = 0; j <= 60; j++) {
        if ((1LL << j) & a[i]) {
          has[j]++;
        }
      }
    }
    for (int i = 0; i < 100; i++) {
      nu[i] = n - has[i];
      int x = (1LL << i) % M;
      nu[i] = nu[i] * x % M;
    }
    for (int j = 1; j <= n; j++) {
      sum[j] = 0;
      for (int b2 = 0; b2 <= 60; b2++) {
        if (a[j] & (1LL << b2)) {
          sum[j] = (sum[j] + nu[b2]) % M;
        }
      }
    }
    int ret = 0;
    for (int b1 = 0; b1 <= 60; b1++) {
      vector<int> idx;
      for (int i = 1; i <= n; i++) {
        if (a[i] & (1LL << b1)) {
          idx.push_back(i);
        }
      }
      int sol = 0;
      for (int b2 = 0; b2 <= 60; b2++) {
        int x = (1LL << b2) % M;
        int cnt = 0;
        cnt = (cnt + (int) idx.size() * has[b2]) % M;
        sol = (sol + x * cnt) % M;
      }
      for (auto &j : idx) {
        sol += sum[j];
        sol %= M;
      }
      int x = (1LL << b1) % M;
      sol = sol * has[b1] % M;
      ret = (ret + sol * x) % M;
    }
    cout << ret << "\n";
  }

}