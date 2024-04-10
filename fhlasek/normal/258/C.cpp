/* Written by Filip Hlasek 2012 */
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstring>

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,b) for(int i=0;i<(b);i++)

using namespace std;

#define MOD 1000000007
#define MAXN 111111
int N, a[MAXN], Div[1111], D, Less[MAXN];

int power(int base, long long exponent){
  int result = 1, m = base;
  while(exponent){
    if(exponent&1) result = ((long long)result*m)%MOD;
    m = ((long long)m*m)%MOD;
    exponent /= 2;
  }
  return result;
}

int main(int argc, char *argv[]){
  scanf("%d", &N);
  REP(i, N) scanf("%d", a + i);
  REP(i, N) Less[a[i]+1]++;
  REP(i, MAXN-2) Less[i+1] += Less[i];
  int ans = 0;
  FOR(lcm, 1, 100000){
    D = 0;
    for(int i = 1; i * i <= lcm; i++) if(lcm % i == 0){
      Div[D++] = i;
      if(i * i != lcm) Div[D++] = lcm / i;
    }
    sort(Div, Div + D);
    int tmp1 = 1, tmp2 = 1;
    REP(i, D-1) tmp1 = ((long long)tmp1 * power(i + 1, Less[Div[i+1]] - Less[Div[i]])) % MOD;
    tmp1 = ((long long)tmp1 * power(D, N - Less[Div[D-1]])) % MOD;
    D--;
    REP(i, D-1) tmp2 = ((long long)tmp2 * power(i + 1, Less[Div[i+1]] - Less[Div[i]])) % MOD;
    tmp2 = ((long long)tmp2 * power(D, N - Less[Div[D-1]])) % MOD;
    ans = (ans + tmp1 - tmp2) % MOD;
  }
  if(ans < 0) ans += MOD;
  printf("%d\n", ans);
  return 0;
}