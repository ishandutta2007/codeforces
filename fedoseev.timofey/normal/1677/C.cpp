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
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      --a[i];
    }
    for (int i = 0; i < n; ++i) {
      cin >> b[i];
      --b[i];
    }
    vector<int> pos(n);
    for (int i = 0; i < n; ++i) {
      pos[a[i]] = i;
    }
    vector<int> go(n);
    for (int i = 0; i < n; ++i) go[i] = pos[b[i]];
    vector<int> used(n);
    int odd_cnt = 0;
    for (int i = 0; i < n; ++i) {
      if (!used[i]) {
        int len = 0;
        int uk = i;
        while (!used[uk]) {
          used[uk] = 1;
          ++len;
          uk = go[uk];
        }
        if (len % 2 == 1) {
          ++odd_cnt;
        }
      }
    }
    long long ans = 0;
    for (int i = 0; i < (n - odd_cnt) / 2; ++i) {
      ans += 2 * (n - i);
      ans -= 2 * (i + 1);
    }
    cout << ans << '\n';
  }
}