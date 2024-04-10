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

const int N = 14;
const int K = 6;

ll L[1 << K][N];
ll R[1 << K][N];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n;
  cin >> n;
  vector <vector <int>> g(n, vector <int> (n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      char c;
      cin >> c;
      g[i][j] = c - '0';
    }
  }
  int l = n / 2;
  int r = n - l;
  vector <ll> ans(1 << (n - 1));
  for (int go = 0; go < (1 << n); ++go) {
    if (__builtin_popcount(go) != l) continue;
    for (int i = 0; i < (1 << K); ++i) {
      for (int j = 0; j < n; ++j) {
        L[i][j] = 0;
        R[i][j] = 0;
      }
    }
    vector <int> cl, cr;
    for (int i = 0; i < n; ++i) {
      if (go & (1 << i)) cl.push_back(i);
      else cr.push_back(i);
    }
    do {
      int mask = 0;
      for (int i = (int)cl.size() - 1; i > 0; --i) {
        mask = 2 * mask + g[cl[i]][cl[i - 1]];
      }
      ++L[mask][cl.back()];
    } while (next_permutation(cl.begin(), cl.end()));

    do {
      int mask = 0;
      for (int i = (int)cr.size() - 1; i > 0; --i) {
        mask = 2 * mask + g[cr[i]][cr[i - 1]];
      }
      ++R[mask][cr.front()];
    } while (next_permutation(cr.begin(), cr.end()));
    vector <pair <int, int>> whoL, whoR;
    for (int lmask = 0; lmask < (1 << (l - 1)); ++lmask) {
      for (int i = 0; i < n; ++i) {
        if (L[lmask][i]) {
          whoL.push_back({lmask, i});
        }
      }
    } 
    for (int rmask = 0; rmask < (1 << (r - 1)); ++rmask) {
      for (int i = 0; i < n; ++i) {
        if (R[rmask][i]) {
          whoR.push_back({rmask, i});
        }
      }
    }
    /*for (int lmask = 0; lmask < (1 << (l - 1)); ++lmask) {
      for (int gl : cl) {
        int cr = L[lmask][gl];
        if (cr == 0) continue;
        for (int rmask = 0; rmask < (1 << (r - 1)); ++rmask) {
          for (int gr : cr) {
            int bt = (g[gl][gr] << (l - 1));
            ans[(rmask << l) + bt + lmask] += (ll)cr * R[rmask][gr];
          }
        }
      }
    } */
    for (auto pl : whoL) {
      for (auto pr : whoR) {
        int gl = pl.second, gr = pr.second;
        int lmask = pl.first, rmask = pr.first;
        int bt = (g[gl][gr] << (l - 1));
        ans[(rmask << l) + bt + lmask] += (ll)L[lmask][gl] * R[rmask][gr];
      }
    }
  } 
  for (int i = 0; i < (1 << (n - 1)); ++i) { 
    cout << ans[i] << ' ';
  }
}