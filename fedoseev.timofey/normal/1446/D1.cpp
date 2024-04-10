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
  int n;
  cin >> n;
  vector <int> a(n);
  vector <int> cnt(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    --a[i];
    ++cnt[a[i]];
  }
  int mx = 0;
  for (int i = 0; i < n; ++i) mx = max(mx, cnt[i]);
  int who = -1;
  for (int i = 0; i < n; ++i) {
    if (cnt[i] == mx) {
      if (who != -1) {
        cout << n << '\n';
        return 0;
      }
      who = i;
    }
  }
  int ans = 0;
  for (int x = 0; x < min(n, 100); ++x) {
    if (x == who) continue;
    vector <int> pref_bal(n + 1), suf_bal(n + 1);
    for (int i = 0; i < n; ++i) {
      pref_bal[i + 1] = pref_bal[i];
      if (a[i] == x) --pref_bal[i + 1];
      if (a[i] == who) ++pref_bal[i + 1];
    }
    for (int i = n - 1; i >= 0; --i) {
      suf_bal[i] = suf_bal[i + 1];
      if (a[i] == x) --suf_bal[i];
      if (a[i] == who) ++suf_bal[i];
    }
    vector <int> fst(n, n);
    vector <int> lst(n, -1); 
    for (int i = 0; i <= n; ++i) {
      if (pref_bal[i] >= 0) {
        fst[pref_bal[i]] = min(fst[pref_bal[i]], i);
      }
    } 
    for (int i = 0; i <= n; ++i) {
      if (suf_bal[i] >= 0) {
        lst[suf_bal[i]] = max(lst[suf_bal[i]], i);
      }
    } 
    int need = cnt[who] - cnt[x];
    for (int i = 0; i <= need; ++i) {
      ans = max(ans, lst[i] - fst[need - i]);
    }
  }
  cout << ans << '\n';
}