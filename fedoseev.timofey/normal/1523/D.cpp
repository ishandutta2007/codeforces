#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <iomanip>
#include <functional>
#include <cassert>
#include <bitset>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
 
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n, m, p;
  cin >> n >> m >> p;
  vector <ll> a(n);
  for (int i = 0; i < n; ++i) {
    ll x = 0;
    for (int j = 0; j < m; ++j) {
      char c;
      cin >> c;
      if (c == '1') x |= (1LL << j);
    }
    a[i] = x;
  }
  mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
  ll ans = 0;
  for (int it = 0; it < 50; ++it) {
    int id = rnd() % n;
    vector <int> bits;
    for (int j = 0; j < m; ++j) {
      if ((a[id] >> j) & 1) {
        bits.push_back(j);
      }
    }
    int p = bits.size();
    vector <int> cnt(1 << p);
    for (int i = 0; i < n; ++i) {
      int cur = 0;
      for (int j = 0; j < (int)bits.size(); ++j) {
        if ((a[i] >> bits[j]) & 1) {
          cur |= (1 << j);
        }
      }
      ++cnt[cur];
    }
    for (int b = 0; b < p; ++b) {
      for (int mask = 0; mask < (1 << p); ++mask) {
        if (!(mask & (1 << b)) )cnt[mask] += cnt[mask | (1 << b)];
      }
    }
    for (int mask = 0; mask < (1 << p); ++mask) {
      if (2 * cnt[mask] >= n && __builtin_popcountll(mask) > __builtin_popcountll(ans)) {
        ans = 0;
        for (int i = 0; i < p; ++i) {
          if (mask & (1 << i)) ans |= (1LL << bits[i]);
        }
      }
    }
  }
  for (int i = 0; i < m; ++i) {
    if (ans & (1LL << i)) {
      cout << '1';
    } else {
      cout << '0';
    }
  }
}