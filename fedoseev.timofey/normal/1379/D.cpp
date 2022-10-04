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

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n, h, m, k;
  cin >> n >> h >> m >> k;
  vector <ll> tm(n);
  vector <int> rem;
  int mod = m / 2;
  for (int i = 0; i < n; ++i) {
    int hh, mm;
    cin >> hh >> mm;
    tm[i] = (ll)hh * m + mm;
    rem.push_back(tm[i] % mod);
  }
  sort(rem.begin(), rem.end());
  int ans = n + 1, ans_t = -1;
  vector <int> who;
  auto check = [&] (int t, bool fl) {
    int r = t;
    int l = t - k; 
    int kill;
    if (l >= 0) {
      ++l;
      --r;
      kill = 0;
      if (l <= r) {
        kill = upper_bound(rem.begin(), rem.end(), r) - lower_bound(rem.begin(), rem.end(), l);
        if (fl) {
          for (int i = 0; i < n; ++i) {
            if (l <= (tm[i] % mod) && (tm[i] % mod) <= r) {
              who.push_back(i);
            }
          }
        }
      }
    } else {
      int l = t;
      int r = t - k + mod;
      kill = n;
      if (l <= r) {
        kill = n - (upper_bound(rem.begin(), rem.end(), r) - lower_bound(rem.begin(), rem.end(), l));
        if (fl) {
          for (int i = 0; i < n; ++i) {
            if (l <= (tm[i] % mod) && (tm[i] % mod) <= r);
            else who.push_back(i);
          }
        }
      } else {
        if (fl) {
          for (int i = 0; i < n; ++i) who.push_back(i);
        }
      }
    }
    if (kill < ans) {
      ans = kill;
      ans_t = t;
    }
  };
  for (int i = 0; i < n; ++i) {
    int cr = tm[i] % mod;
    check((cr - k + mod) % mod, 0);
    check((cr + k + mod) % mod, 0);
  }
  cout << ans << ' ' << ans_t << '\n';
  check(ans_t, 1);
  for (int x : who) cout << x + 1 << ' '; 
}