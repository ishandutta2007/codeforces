#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

const int N = 128;

vector<vector<double>> mult(const vector<vector<double>> &a, const vector<vector<double>> &b) {
  vector<vector<double>> mat(N, vector<double>(N));
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      for (int t = 0; t < N; ++t) {
        mat[i][j] += a[i][t] * b[t][j];
      }
    }
  }
  return mat;
}

vector<vector<double>> mPow(vector<vector<double>> a, int x) {
  vector<vector<double>> mat(N, vector<double>(N));
  for (int i = 0; i < N; ++i) mat[i][i] = 1.0;
  while (x > 0) {
    if (x & 1) mat = mult(mat, a);
    a = mult(a, a);
    x >>= 1;
  }
  return mat;
}


int main() {
  ios::sync_with_stdio(false);
  int n, x;
  cin >> n >> x;

  vector<vector<double>> mat(N, vector<double>(N));
  for (int i = 0; i <= x; ++i) {
    double p;
    cin >> p;
    for (int j = 0; j < N; ++j) {
      mat[j][j ^ i] += p;
    }
  }

  vector<vector<double>> ret = mPow(mat, n);
  double s = 0;
  for (int i = 0; i < N; ++i) {
    s += ret[0][i];
  }
  double ans = 1.0 - ret[0][0];
  printf("%.10lf\n", ans / s);

  // for (int i = 0; i < N; ++i) {
  //   for (int j = 0; j < N; ++j) {
  //     cout << ret[i][j] << "  ";
  //   }
  //   cout << endl;
  // }

  return 0;
}