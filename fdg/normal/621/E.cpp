#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int mod = 1000000007;

vector<vector<int>> mat;

void add(int &r, int a) {
  r += a;
  if (r >= mod) r -= mod;
}

vector<vector<int>> mult(const vector<vector<int>> &a, const vector<vector<int>> &b) {
  int n = a.size();
  vector<vector<int>> ret = vector<vector<int>>(n, vector<int>(n, 0));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      for (int t = 0; t < n; ++t) {
        add(ret[i][j], 1LL * a[i][t] * b[t][j] % mod);
      }
    }
  }
  return ret;
}

vector<vector<int>> mPow(vector<vector<int>> a, int x) {
  int n = a.size();
  vector<vector<int>> ret = vector<vector<int>>(n, vector<int>(n, 0));
  for (int i = 0; i < n; ++i) ret[i][i] = 1;

  while (x > 0) {
    if (x & 1) ret = mult(ret, a);
    a = mult(a, a);
    x >>= 1;
  }
  return ret;
}

int main() {
  int n, b, k, x;
  scanf("%d%d%d%d", &n, &b, &k, &x);
  int cnt[10] = {0};
  for (int i = 0; i < n; ++i) {
    int d;
    scanf("%d", &d);
    cnt[d]++;
  }

  mat = vector<vector<int>>(x, vector<int>(x));
  for (int i = 0; i < x; ++i) {
    for (int d = 0; d < 10; ++d) {
      int ni = (i * 10 + d) % x;
      add(mat[i][ni], cnt[d]);
    }
  }

  // for (int i = 0; i < x; ++i) {
  //   for (int j = 0; j < x; ++j) {
  //     cout << mat[i][j] << "  ";
  //   }
  //   cout << endl;
  // }

  mat = mPow(mat, b);

  cout << mat[0][k] << endl;
  return 0;
}