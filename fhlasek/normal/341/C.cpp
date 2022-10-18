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
#define REP(i,b) for(int i=0;i<b;i++)

using namespace std;

#define MAXC 111111
#define MOD 1000000007
int fac[MAXC],ifac[MAXC];

int power(int base, long long exponent){
  int result = 1, m = base;
  while(exponent){
    if(exponent&1) result = ((long long)result*m)%MOD;
    m = ((long long)m*m)%MOD;
    exponent /= 2;
  }
  return result;
}

int c(int n, int k){ return (((long long)fac[n]*ifac[k])%MOD*ifac[n-k])%MOD; }

#define MAXN 111111
int N, a[MAXN];

int main(int argc, char *argv[]){

  fac[0] = 1;
  REP(i,MAXC) fac[i+1] = ((long long)fac[i]*(i+1))%MOD;
  ifac[MAXC-1] = power(fac[MAXC-1],MOD-2);
  FORD(i,MAXC-2,0) ifac[i] = ((long long)ifac[i+1]*(i+1))%MOD;

	scanf("%d", &N);
	REP(i, N) scanf("%d", a+i);

	int possible_fixed = 0;
	REP(i, N) {
		bool available = true, empty = (a[i] == -1);
		REP(j, N) if(a[j] == i + 1) available = false;
		possible_fixed += (available && empty);
	}
	int K = possible_fixed, M = 0;
	REP(i, N) M += (a[i] == -1);

	int ans = 0;
	REP(i, K+1) ans = (ans + (i % 2 ? -1 : 1) * (long long)fac[M-i] * c(K, i)) % MOD;

	if(ans < 0) ans += MOD;
	printf("%d\n", ans);

  return 0;
}