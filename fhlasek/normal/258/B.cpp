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
#define PEP(i,b) for(i=0;i<(b);i++)

using namespace std;

#define MOD 1000000007

int cnt[11];

#define MAXC 111111
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

int var(int n, int k){ int ans = 1; REP(i, k) ans = ((long long)ans * (n - i)) % MOD; return ans; }

int main(int argc, char *argv[]){

  fac[0] = 1;
  REP(i,MAXC) fac[i+1] = ((long long)fac[i]*(i+1))%MOD;
  ifac[MAXC-1] = power(fac[MAXC-1],MOD-2);
  FORD(i,MAXC-2,0) ifac[i] = ((long long)ifac[i+1]*(i+1))%MOD;

  int M; 
  scanf("%d", &M);
  int m = 1000000000, l = 0;
  REP(step, 10){
    int n = M / m;
    REP(i, n){
      if(i == 4 || i == 7) l++;
      int rem = 9 - step;
      FOR(i, 0, rem) cnt[l + i] = (cnt[l + i] + (long long)c(rem, i) * power(2, i) * power(8, rem-i)) % MOD;
      if(i == 4 || i == 7) l--;
    }
    if(n == 4 || n == 7) l++;
    M -= n * m;
    m /= 10;
  }
  cnt[0]--;
  cnt[l]++;
  int a[7], _cnt[10];
  int ans = 0;
  FOR(first, 1, 9) if(cnt[first]){
    PEP(a[0], first) PEP(a[1], first) PEP(a[2], first) PEP(a[3], first) PEP(a[4], first) PEP(a[5], first){
      int sum = 0;
      REP(i, 6) sum += a[i];
      if(sum >= first) continue;
      REP(i, first) _cnt[i] = 0;
      REP(i, 6) _cnt[a[i]]++;
      bool ok = true;
      REP(i, first) if(_cnt[i] > cnt[i]){ ok = false; break; }
      if(!ok) continue;
      int tmp = 1;
      REP(i, first) tmp = ((long long)tmp * var(cnt[i], _cnt[i])) % MOD;
      ans = (ans + (long long)cnt[first] * tmp) % MOD;
    }
  }
  printf("%d\n", ans);
  return 0;
}