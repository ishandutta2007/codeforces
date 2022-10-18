#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define REP(i, n) for(int i=0;i<(n);i++)
#define FOR(i, a, b) for(int i=(a);i<=(b);i++)
#define FORD(i, a, b) for(int i=(a);i>=(b);i--)

using namespace std;

#define MAX_NEEDLE 1111111
int N; //lenght of the needle
char needle[MAX_NEEDLE];
int fail[MAX_NEEDLE];

void failure() { //precomputes the failure function
  int k;
  fail[0] = -1;
  FOR(i, 1, N) {
    for (k = fail[i - 1]; k >= 0 && needle[k] != needle[i - 1]; k = fail[k]) ;
    fail[i] = k + 1;
  }
}

#define MAX_TEXT 1111111
int T; //lenght of the text
char text[MAX_TEXT];

#define MOD 1000000007
int dp[MAX_TEXT];
void add(int x, int val) {
  if (x <= 0) return;
  while (x <= T) {
    dp[x] = (dp[x] + val) % MOD;
    x += x & -x;
  }
}
int get(int x) {
  int ans = 0;
  while (x > 0) {
    ans = (ans + dp[x]) % MOD;
    x -= x & -x;
  }
  return ans;
}

void kmp() {
  int i = 0, j = 0;
  int pos = -1;
  int too_old = 0;
  while (i < T) {
    while (j >= 0 && text[i] != needle[j]) j = fail[j];
    i++; j++;
    if (j == N) {
      int val = ((long long)too_old * (i - N - pos)) % MOD;
      while (pos < i - N) {
        val = (val + 1 + (long long)(i - N - pos) * get(pos + 1)) % MOD;
        too_old = (too_old + get(pos + 1)) % MOD;
        pos++;
      }
      add(i, val);
      // string matched - needle ends in i (last symbol at i - 1) => starts in i - N
      j = fail[j];
    }
  }
}

int main() {
  scanf("%s", text);
  T = strlen(text);
  scanf("%s", needle);
  N = strlen(needle);
  failure();
  kmp();
  int ans = 0;
  REP(i, T + 1) ans = (ans + get(i)) % MOD;
  printf("%d\n", ans);
  return 0;
}