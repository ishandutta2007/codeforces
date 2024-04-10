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

const int N = 1007;

ll A[N];
ll P[N];

mt19937 rnd(123);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int tt = 1;
  while (tt--) {
    int n;
    #ifndef LOCAL
    cin >> n;
    #else
    n = rnd() % 5 + 1;
    for (int i = 0; i < n; ++i) A[i] = rnd() % 10;
    for (int i = 0; i < n; ++i) {
      P[i] = 0;
      for (int j = 0; j < n; ++j) {
        if (i != j) P[i] |= A[j];
      }
    }
    #endif
    const int K = 13;
    vector <ll> ans(K);
    
    auto ask = [&] (vector <int> who) {
      #ifndef LOCAL
      cout << "? " << who.size() << ' ';
      for (int x : who) cout << x << ' ';
      cout << endl;
      ll res;
      cin >> res;
      return res;
      #else
      ll res = 0;
      for (int id : who) res |= A[id - 1];
      return res;
      #endif
    };

    vector <int> mask(n);
    int uk = 0;
    for (int ms = 0; ms < (1 << 13); ++ms) {
      if (__builtin_popcount(ms) == 6) {
        if (uk < n) mask[uk++] = ms;
      }
    }

    for (int b = 0; b < K; ++b) {
      vector <int> who;
      for (int i = 0; i < n; ++i) {
        if (mask[i] & (1 << b)) {
          who.push_back(i + 1);
        }
      }
      if (!who.empty()) ans[b] = ask(who);
    }
    vector <ll> p(n);
    for (int b = 0; b < 63; ++b) {
      bool fnd = false;
      for (int i = 0; i < n; ++i) {
        bool ok = true;
        for (int j = 0; j < K; ++j) {
          if (mask[i] & (1 << j)) ok &= ((ans[j] >> b) & 1);
          else ok &= !((ans[j] >> b) & 1);
        }
        if (ok) {
          for (int j = 0; j < n; ++j) {
            if (j != i) p[j] |= ((ll)1 << b);
          }
          fnd = true;
        }
      }
      if (!fnd) {
        bool hv = false;
        for (int j = 0; j < K; ++j) {
          if ((ans[j] >> b) & 1) hv = true;
        }
        if (hv) {
          for (int i = 0; i < n; ++i) p[i] |= ((ll)1 << b);
        }
      }
    }
    #ifndef LOCAL
    cout << "! ";
    for (int i = 0; i < n; ++i) cout << p[i] << ' ';
    cout << endl;
    #else
    bool good = true;
    for (int i = 0; i < n; ++i) good &= (p[i] == P[i]);
    if (!good) {
      for (int i = 0; i < n; ++i) cout << A[i] << ' ';
      cout << endl;
      for (int i = 0; i < n; ++i) cout << P[i] << ' ';
      cout << endl;
      for (int i = 0; i < n; ++i) cout << p[i] << ' ';
      cout << endl;
      cout << ans[0] << endl;
      assert(false);
    }
    #endif
  }
}