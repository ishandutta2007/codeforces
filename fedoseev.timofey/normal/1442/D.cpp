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
  int n, k;
  cin >> n >> k;
  vector <vector <int>> a(n);
  vector <ll> sm(n);
  for (int i = 0; i < n; ++i) {
    int t;
    cin >> t;
    a[i].resize(t);
    ll sum = 0;
    for (int j = 0; j < t; ++j) {
      cin >> a[i][j];
      sum += a[i][j];
    }
    sm[i] = sum;
  }
  vector <vector <ll>> pref(n + 1, vector <ll> (k + 1));
  vector <vector <ll>> suf(n + 1, vector <ll> (k + 1));
  vector <vector <int>> p(n + 1, vector <int> (k + 1, 0));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= k; ++j) {
      if (pref[i][j] > pref[i + 1][j]) {
        pref[i + 1][j] = pref[i][j];
        p[i + 1][j] = 0;
      }
      if (j + a[i].size() <= k) {
        if (pref[i][j] + sm[i] > pref[i + 1][j + a[i].size()]) {
          pref[i + 1][j + a[i].size()] = pref[i][j] + sm[i];
          p[i + 1][j + a[i].size()] = 1;
        }
      }
    }
  }
  for (int i = n - 1; i >= 0; --i) {
    for (int j = 0; j <= k; ++j) {
      suf[i][j] = max(suf[i][j], suf[i + 1][j]);
      if (j + a[i].size() <= k) {
        suf[i][j + a[i].size()] = max(suf[i][j + (int)a[i].size()], suf[i + 1][j] + sm[i]);
      }
    }
  }
  vector <vector <bool>> tk(k + 1, vector <bool> (n)); 
  for (int w = 0; w <= k; ++w) {
    int cw = w;
    for (int i = n - 1; i >= 0; --i) {
      if (p[i + 1][cw]) {
        tk[w][i] = 1;
        cw -= (int)a[i].size();
      }
    }
  }   
  for (int i = 0; i <= n; ++i) {
    for (int j = 1; j <= k; ++j) {
      pref[i][j] = max(pref[i][j], pref[i][j - 1]);
      suf[i][j] = max(suf[i][j], suf[i][j - 1]);
    }
  }
  ll ans = pref[n][k];
  for (int i = 0; i < n; ++i) {
    ll go = 0;
    for (int j = 0; j < min((int)a[i].size(), k); ++j) {
      go += a[i][j];
      int rem = k - (j + 1); 
      if (!tk[rem][i]) ans = max(ans, go + pref[n][rem]);
      else {
        for (int other = 0; other <= rem; ++other) {
          ans = max(ans, go + pref[i][other] + suf[i + 1][rem - other]);
        }
      }
    }
  }
  cout << ans << '\n';
}