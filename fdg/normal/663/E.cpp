#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

char f[22][100002];

int solve(int p, int n, vector<int> v) {
  if (n == 0) {
    // cout << p << "  " << v.size() << endl;
    int ret = 0;
    for (int i = 0; i <= p; ++i) {
      ret += v[i] * min(i, p - i);
    }
    return ret;
  }


  int ans = 1e+9;
  // 0
  {
    vector<int> nv((p + 2) * (1<<(n - 1)));
    for (int i = 0; i <= p; ++i) {
      for (int mask = 0; mask < (1<<n); ++mask) {
        int ni = i + (mask & 1), nmask = mask >> 1;
        nv[ni * (1<<(n - 1)) + nmask] += v[i * (1<<n) + mask];
      }
    }
    ans = min(ans, solve(p + 1, n - 1, nv));
  }
  // 1
  {
    vector<int> nv((p + 2) * (1<<(n - 1)));
    for (int i = 0; i <= p; ++i) {
      for (int mask = 0; mask < (1<<n); ++mask) {
        int ni = i + ((mask & 1) == 0), nmask = mask >> 1;
        nv[ni * (1<<(n - 1)) + nmask] += v[i * (1<<n) + mask];
      }
    }
    ans = min(ans, solve(p + 1, n - 1, nv));
  }
  return ans;
}

int main() {
  int n, m;
  scanf("%d%d\n", &n, &m);
  for (int i = 0; i < n; ++i)
    gets(f[i]);

  int ans = n * m;

  int p = min(10, n); p = 0;
  for (int mask = 0; mask < (1<<p); ++mask) {
    vector<int> v((p + 1) * (1 << (n - p)));
    for (int j = 0; j < m; ++j) {
      int bit = 0, nmask = 0;
      for (int i = 0; i < n; ++i) {
        int val = (f[i][j] == '1') ^ ((mask >> i) & 1);
        if (i < p) bit += val;
        else nmask = nmask << 1 | val;
      }
      v[bit * (1 << (n - p)) + nmask]++;
    }
    ans = min(ans, solve(p, n - p, v));
  }
  cout << ans << endl;

  return 0;
}