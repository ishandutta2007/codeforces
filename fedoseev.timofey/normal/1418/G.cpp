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
typedef unsigned long long ull;

mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n;
  cin >> n;
  vector <int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    --a[i];
  }
  vector <ull> h(n);
  for (int i = 0; i < n; ++i) h[i] = rnd();
  vector <int> cnt(n);
  vector <ull> p(n + 1);
  ull ch = 0;
  for (int i = 0; i < n; ++i) {
    ch -= cnt[a[i]] * h[a[i]];
    cnt[a[i]] = (cnt[a[i]] + 1) % 3;
    ch += cnt[a[i]] * h[a[i]];
    p[i + 1] = ch;
  } 
  for (int i = 0; i < n; ++i) {
    cnt[i] = 0;
  }
  ll ans = 0;
  map <ull, int> have;
  ++have[0];
  int uk = 0;
  for (int i = 0; i < n; ++i) {
    ++cnt[a[i]];
    while (cnt[a[i]] > 3) {
      --have[p[uk]];
      --cnt[a[uk]];
      ++uk;
    }
    ans += have[p[i + 1]];
    ++have[p[i + 1]];
  }
  cout << ans << '\n';
}