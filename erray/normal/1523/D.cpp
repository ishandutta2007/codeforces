// author: erray
#include <bits/stdc++.h>
 
using namespace std;

mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m, p;
  cin >> n >> m >> p;
  vector<long long> a(n);
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < m; ++j) {
      if (s[j] == '1') {
        a[i] += (1LL << j);
      }
    }
  }

  int best = 0;
  long long ans = 0;
  for (int it = 0; it < 100; ++it) {
    int me = uniform_int_distribution(0, n - 1)(rng);
    vector<int> bit;
    for (int i = 0; i < m; ++i) {
      if ((a[me] >> i) & 1) {
        bit.push_back(i);
      }
    }
    int size = int(bit.size());
    const int MASK = (1 << size);
    vector<int> dp(MASK);
    for (int i = 0; i < n; ++i) {
      int in = 0;
      for (int j = 0; j < size; ++j) {
        if ((a[i] >> bit[j]) & 1) {
          in += (1 << j);
        }
      } 
      ++dp[in];
    } 
   
    for (int i = 0; i < size; ++i) {
      for (int mask = 0; mask < MASK; ++mask) {
        if (mask & (1 << i)) {
          dp[mask ^ (1 << i)] += dp[mask];
        }
      }
    }

    for (int i = 0; i < MASK; ++i) {
      if (dp[i] >= (n + 1) / 2 && __builtin_popcount(i) > best) {
        best = __builtin_popcount(i);
        long long new_ans = 0;
        for (int j = 0; j < size; ++j) {
          if ((i >> j) & 1) {
            new_ans += 1LL << bit[j];
          }
        }
        swap(ans, new_ans);
      }
    }
  }

  for (int i = 0; i < m; ++i) {
    cout << ((ans >> i) & 1);
  }
}