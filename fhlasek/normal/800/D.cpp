/* Written by Filip Hlasek 2017 */
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <iostream>

#define FOR(i, a, b)   for (int i = (a); i <= (b); i++)
#define FORD(i, a, b)  for (int i = (a); i >= (b); i--)
#define REP(i, b)      for (int i =  0 ; i <  (b); i++)

using namespace std;

#define MOD 1000000007

int power(int base, long long exponent) {
  int result = 1, m = base;
  while (exponent) {
    if (exponent & 1) result = ((long long)result * m) % MOD;
    m = ((long long)m * m) % MOD;
    exponent /= 2;
  }
  return result;
}

#define MAXN 1000000
int cnt[MAXN];
int ans[MAXN];
int sumans[MAXN];
int sum[MAXN];
int sum2[MAXN];

int d[6];

int Add[64];
int Sign[64];

int main(int argc, char *argv[]) {
  int N;
  scanf("%d", &N);
  while (N--) {
    int A;
    scanf("%d", &A);
    cnt[A]++;
    sum[A] = (sum[A] + A) % MOD;
    sum2[A] = (sum2[A] + (long long)A * A) % MOD;
  }
  REP(mask, 1 << 6) {
    int cur = 1;
    Sign[mask] = 1;
    REP(j, 6) {
      if (mask & (1 << j)) {
        Add[mask] += cur;
        Sign[mask] *= -1;
      }
      cur *= 10;
    }
  }
  long long total = 0;
  FORD(i, 999999, 0) {
    int n = i;
    REP(j, 6) { d[j] = n % 10; n /= 10; }
    reverse(d, d + 6);
    int mask9 = 0;
    REP(j, 6) mask9 = mask9 * 2 + (d[j] == 9);
    REP(mask, 1 << 6) if (!(mask9 & mask)) {
      n = i + Add[mask];
      if (mask) {
        cnt[i] -= Sign[mask] * cnt[n];
        sum[i] = ((sum[i] - Sign[mask] * sum[n]) % MOD + MOD) % MOD;
        sum2[i] = ((sum2[i] - Sign[mask] * sum2[n]) % MOD + MOD) % MOD;
        ans[i] = ((ans[i] + Sign[mask] * sumans[n]) % MOD + MOD) % MOD;
        sumans[i] = ((sumans[i] - Sign[mask] * sumans[n]) % MOD + MOD) % MOD;
      }
    }
    if (cnt[i]) {
      ans[i] = (ans[i] + (long long)power(2, cnt[i] - 1) * sum2[i]) % MOD;
    }
    if (cnt[i] > 1) {
      int sumpair = (((long long)sum[i] * sum[i] - sum2[i]) % MOD + MOD) % MOD;
      ans[i] = (ans[i] + (long long)power(2, cnt[i] - 2) * sumpair) % MOD;
    }
    sumans[i] = (sumans[i] + ans[i]) % MOD;
    total ^= (long long)ans[i] * i;
    /*
    if (ans[i]) {
      int sumpair = ((long long)sum[i] * sum[i] - sum2[i]) % MOD;
      printf(
        "i: %d cnt: %d sum: %d sum2: %d sumpair: %d ans: %d\n",
        i, cnt[i], sum[i], sum2[i], sumpair, ans[i]
      );
    }
    */
  }
  cout << total << endl;
  return 0;
}