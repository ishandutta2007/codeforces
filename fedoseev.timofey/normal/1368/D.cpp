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

using namespace std;

typedef long long ll;

const int K = 20;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n;
  cin >> n;
  vector <int> a(n);
  vector <int> cnt(K);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    for (int j = 0; j < K; ++j) {
      if (a[i] & (1 << j)) {
        ++cnt[j];
      }
    }
  }
  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    int x = 0;
    for (int j = K - 1; j >= 0; --j) {
      if (cnt[j] > 0) {
        x |= (1 << j);
        --cnt[j];
      }
    }
    ans += (ll)x * x;
  }
  cout << ans << '\n';
}