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

const int md = 998244353;

template <typename T>
class fenwick {
  public:
  vector<T> fenw;
  int n;
  fenwick(int _n) : n(_n) {
    fenw.resize(n);
  }
  void modify(int x, T v) {
    while (x < n) {
      fenw[x] += v;
      x |= (x + 1);
    }
  }
  T get(int x) {
    T v{};
    while (x >= 0) {
      v += fenw[x];
      x = (x & (x + 1)) - 1;
    }
    return v;
  }
};

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
    vector <int> b(n);
    for (int i = 0; i < n; ++i) cin >> b[i];
    if (n == 1) {
      cout << "1\n";
      continue;
    }
    if (n == 2) {
      int ans = 1;
      if (b[0] > b[1]) ++ans;
      if (b[1] > b[0]) ++ans;
      cout << ans << '\n';
      continue;
    }
    ll ans = 0;
    for (int tk_f = 0; tk_f <= 1; ++tk_f) {
      for (int tk_l = 0; tk_l <= 1; ++tk_l) {
        vector <int> a = b;
        ll extra_p = 0, extra_c = 0;
        if (tk_f) {
          extra_p += a.front();
          a.erase(a.begin());
        }
        if (tk_l) {
          extra_c = a.back();
          a.pop_back();
        }
        int n = a.size();

        vector <ll> pref(n + 1);
        for (int i = 0; i < n; ++i) {
          pref[i + 1] = pref[i] + a[i];
        }

        vector <ll> delta(n + 1);
        for (int i = 2; i <= n; ++i) {
          delta[i] = delta[i - 2] + a[i - 1] - a[i - 2];
        }

        vector <ll> cm;
        for (int i = 0; i <= n; ++i) {
          cm.push_back(extra_c + pref[i] - delta[i]);
        }
        sort(cm.begin(), cm.end());
        cm.resize(unique(cm.begin(), cm.end()) - cm.begin());
        vector <fenwick <int>> calc(2, fenwick <int> ((int)cm.size()));
        for (int j = 0; j <= n; ++j) {
          int id = lower_bound(cm.begin(), cm.end(), extra_c + pref[j] - delta[j]) - cm.begin();
          if (tk_f && j <= 1) {
          } else {
            calc[j % 2].modify(id, 1);
          }
          id = lower_bound(cm.begin(), cm.end(), pref[n] - pref[j] - delta[j] + extra_p) - cm.begin() - 1;
          if (tk_l && n - j <= 1) {
          } else if (id >= 0) {
            ans += calc[j % 2].get(id);
          }
        }

        /*for (int i = 0; i <= n; ++i) {
          for (int j = i; j <= n; j += 2) {
            if (tk_f && i <= 1) continue;
            if (tk_l && n - j <= 1) continue;
            if (extra_c + pref[i] - delta[i] < pref[n] - pref[j] - delta[j] + extra_p) {
              ++ans;
            }
          }
        }*/
      }
    }    
    {
      vector <ll> pref(n + 1);
      for (int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + b[i];
      }

      for (int cnt = 2; cnt + 1 < n; ++cnt) {
        if (pref[cnt] > pref[n] - pref[cnt]) {
          ++ans;
        }
      }
    }
    cout << ans % md << '\n';
  }
}