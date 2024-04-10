#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAXK 30
#define MAXD 60

using namespace std;

typedef long long lint;

const lint mod = 1e9 + 7;

int K;
struct res_t {
  int many[MAXK][MAXK];
  int inside[MAXK];
  bool exist[MAXK];

  res_t() {
    memset(many, 0, sizeof(many));
    memset(inside, 0, sizeof(inside));
    memset(exist, 0, sizeof(exist));
  }

  res_t(res_t &copy, int rotate) {
    for (int i = 0; i < K; i++) {
      exist[(i+rotate)%K] = copy.exist[i];
      inside[(i+rotate)%K] = copy.inside[i];

      for (int j = 0; j < K; j++)
	many[(i+rotate)%K][(j+rotate)%K] = copy.many[i][j];
    }
  }

  res_t(const res_t &a, const res_t &b) {
    for (int i = 0; i < K; i++) {
      exist[i] = a.exist[i] || b.exist[i];

      inside[i] = a.inside[i];
      if (!a.exist[i])
	inside[i] = (inside[i] + b.inside[i]) % mod;
      for (int j = 0; j < K; j++) {
	inside[i] = (inside[i] + (lint)a.many[i][j] * b.inside[j]) % mod;

	many[i][j] = 0;
	if (!b.exist[j])
	  many[i][j] = a.many[i][j];
	if (!a.exist[i])
	  many[i][j] = (many[i][j] + b.many[i][j]) % mod;
	for (int m = 0; m < K; m++)
	  many[i][j] = (many[i][j] + (lint)a.many[i][m] * b.many[m][j]) % mod;
      }
    }
  }
} retpk[MAXD];
int digits[MAXD];

int main() {
  lint n;

  cin >> n >> K;
  
  int nd = 0;
  for (lint x = n; x; x /= K)
    digits[nd++] = x % K;
  
  retpk[0].exist[0] = true;
  retpk[0].inside[0] = 1;
  for (int j = 0; j < K; j++)
    retpk[0].many[0][j] = 1;

  for (int pk = 1; pk < nd; pk++) {
    retpk[pk] = retpk[pk-1];
    for (int v = 1; v < K; v++)
      retpk[pk] = res_t(retpk[pk], res_t(retpk[pk-1], v));
  }

  res_t result;
  int sum = 0;

  for (int d = nd-1; d >= 0; d--) {
    for (int v = 0; v < digits[d]; v++)
      result = res_t(result, res_t(retpk[d], (sum + v) % K));
    sum += digits[d];
  }

  int result_sum = 1;
  for (int i = 0; i < K; i++)
    result_sum = (result_sum + result.inside[i]) % mod;

  cout << result_sum << endl;

  return 0;
}