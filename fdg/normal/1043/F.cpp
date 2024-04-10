#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <chrono>
#include <random>
#include <memory.h>

using namespace std;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

vector<int> v;
vector<vector<int>> divs;

set<int> f;

bool hasNew(int pos, const vector<int>& div, int val) {
  if (f.count(val)) return false;

  if (pos == div.size()) return true;

  if (!hasNew(pos + 1, div, val))
    return false;

  return hasNew(pos + 1, div, val * div[pos]);
}

vector<pair<int, int>> red;

int dp[65][65];

void upd(int &a, int r) {
  if (a == -1 || a > r) a = r;
}

int go(int num, int ind) {
  // cout << "NUM: " << num << endl;
  set<int> cand;
  for (pair<int, int> x : red) {
    // cout << "X: " << x.first << endl;
    cand.insert(gcd(x.first, num));
  }

  vector<int> arr;
  for (int x : cand) {
    int mask = 0;
    for (int i = 0; i < divs[ind].size(); ++i) {
      if (x % divs[ind][i] == 0) {
        // cout << "div: " << divs[ind][i] << endl;
        mask |= 1 << i;
      }
    }
    arr.push_back(mask);
    // cout << "MASK:  " << mask << endl;
  }

  memset(dp, -1, sizeof(dp));
  int bits = divs[ind].size();
  int MASK = (1 << bits) - 1; 
  dp[0][MASK] = 0;
  for (int i = 0; i < arr.size(); ++i) {
    for (int mask = 0; mask <= MASK; ++mask) {
      if (dp[i][mask] == -1) continue;
      upd(dp[i + 1][mask], dp[i][mask]);
      upd(dp[i + 1][mask & arr[i]], dp[i][mask] + 1);
    }
  }
  return dp[arr.size()][0] != -1 ? dp[arr.size()][0] : 1e+9;
}

int main() {
  clock_t start = clock();

  int n;
  scanf("%d", &n);
  v.resize(n);
  divs.resize(n);

  int g = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &v[i]);
    g = gcd(v[i], g);

    if (v[i] == 1) {
      cout << 1 << endl;
      return 0;
    }
  }

  if (g != 1) {
    cout << -1 << endl;
    return 0;
  }

  sort(v.begin(), v.end());
  for (int i = 0; i < n; ++i) {
    int x = v[i];
    for (int j = 2; j * j <= x; ++j) {
      if (x % j == 0) {
        divs[i].push_back(j);
        x /= j;
        while (x % j == 0) x /= j;
      }
    }
    if (x > 1) divs[i].push_back(x);
  }

  for (int i = 0; i < n; ++i) {
    if (hasNew(0, divs[i], 1)) {
      int x = 1;
      for (int d : divs[i]) x *= d;
      f.insert(x);
      red.push_back({x, i});
    }
  }

  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

  shuffle(red.begin(), red.end(), rng);


  int ans = n, pos = 0;
  while (clock() - start < 2.9 * CLOCKS_PER_SEC) {
    // cout << go(red[pos], pos) + 1 << endl;
    ans = min(ans, go(red[pos].first, red[pos].second) + 1);
    ++pos;
    if (ans == 2 || pos >= red.size()) break;
  }
  cout << ans << endl;

  return 0;
}