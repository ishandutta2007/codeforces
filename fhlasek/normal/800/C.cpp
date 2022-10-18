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

inline long long gcd(long long a, long long b) { return b ? gcd(b, a%b) : a; }

long long ext_gcd(long long a, long long b, long long &alpha, long long &beta) {
  // alpha * a + beta * b = gcd(a, b)
  if(!b) { alpha = 1; beta = 0; return a; }
  long long ans = ext_gcd(b, a%b, beta, alpha);
  beta -= alpha * (a / b);
  return ans;
}

#define MAXN 222222
int N, M;
map<int, vector<int> > d;
bool nok[MAXN];

vector<int> divisor;
int dp[MAXN], Prev[MAXN];

int main(int argc, char *argv[]) {
  scanf("%d%d", &N, &M);
  REP(i, N) {
    int c;
    scanf("%d", &c);
    nok[c] = true;
  }
  REP(i, M) if (!nok[i]) {
    int g = gcd(i, M);
    if (g == 0) g = M;
    d[g].push_back(i);
  }
  for (map<int, vector<int> >::iterator it = d.begin(); it != d.end(); ++it) {
    divisor.push_back(it->first);
  }
  reverse(divisor.begin(), divisor.end());
  int D = divisor.size();
  REP(i, D) {
    int cur = d[divisor[i]].size();
    dp[i] = cur;
    Prev[i] = -1;
    REP(j, i) if (divisor[j] % divisor[i] == 0) {
      if (dp[j] + cur > dp[i]) {
        dp[i] = dp[j] + cur;
        Prev[i] = j;
      }
    }
  }
  int m = 0;
  REP(i, D) if (dp[i] > dp[m]) m = i;
  vector<int> ans;
  while (m != -1) {
    vector<int> &other = d[divisor[m]];
    REP(j, (int)other.size()) {
      ans.push_back(other[j]);
    }
    m = Prev[m];
  }
  printf("%d\n", (int)ans.size());
  REP(i, (int)ans.size()) {
    if (!i) {
      printf("%d", ans[i]);
    } else {
      // alpha * a + beta * b = gcd(a, b)
      long long alpha, beta;
      int g = ext_gcd((long long)ans[i - 1], (long long)M, alpha, beta);
      alpha %= M;
      if (alpha < 0) alpha += M;
      printf(" %d", (int)(((long long)alpha * ans[i] / g) % M));
    }
  }
  printf("\n");

  return 0;
}