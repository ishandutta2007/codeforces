#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2")
#ifdef ONLINE_JUDGE
#pragma GCC target("tune=native")
#endif

#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  static constexpr uint32_t N = 5000;
  static constexpr uint32_t BITS = 64;
  static constexpr uint32_t BLOCKS = (N + BITS - 1) / BITS;

  uint32_t n;
  cin >> n;
  array<array<uint64_t, BLOCKS>, N> in, out;
  memset(&in, 0, sizeof in);
  memset(&out, 0, sizeof out);
  for(uint32_t i=0; i<n; i++) {
    string s;
    cin >> s;
    for(uint32_t j=0; j<n; j++) {
      if(s[j] == '1') {
        out[i][j / BITS] |= 1ull << j % BITS;
        in[j][i / BITS] |= 1ull << i % BITS;
      }
    }
  }

  for(uint32_t i = n-1; i != (uint32_t)-1; i--) {
    for(uint32_t j=0; j<i; j++) {
      if(!(out[i][j / BITS] & 1ull << j % BITS)) continue;
      for(uint32_t k=0; k*BITS<i; k++) {
        if(uint64_t it = out[j][k] & in[i][k]) {
          cout << i+1 << " " << j+1 << " " << k*BITS + __builtin_ctzll(it) + 1 << '\n';
          return 0;
        }
      }
    }
  }

  cout << -1 << '\n';

  return 0;
}