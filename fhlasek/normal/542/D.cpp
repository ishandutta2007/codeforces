/* Written by Filip Hlasek 2015 */
#include <cstdio>
#include <map>
#include <unordered_map>
#include <iostream>

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define REP(i,b) for(int i=0;i<(b);i++)

using namespace std;

bool is_prime(long long A) {
  if (A < 2) return false;
  for (long long d = 2; d * d <= A; ++d) if (A % d == 0) return false;
  return true;
}
#define MAXN 1111111
bool coprime[MAXN];

unordered_map<long long, long long> dp;

long long solve(long long A, long long last = 1) {
  if (A == 1) return 1;
  long long state = A * 100000000000007 + last;
  if (dp.count(state)) return dp[state];
  long long ans = (A - 1 > last) && is_prime(A - 1);
  for (long long p = last + 1; p * p <= A; ++p) if (!coprime[p]) {
    long long q = p;
    while (q + 1 <= A) {
      if (A % (q + 1) == 0) ans += solve(A / (q + 1), p);
      q *= p;
    }
  }
  return dp[state] = ans;
}
int main(int argc, char *argv[]) {
  FOR(i, 2, MAXN - 1) if (!coprime[i]) for (long long j = 2; i * j < MAXN; ++j) coprime[i * j] = true;
  long long A;
  cin >> A;
  cout << solve(A) << endl;
  return 0;
}