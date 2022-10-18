/* Written by Filip Hlasek 2013 */
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

int get(int K) {
  switch(K) {
    case 1: return 1;
    case 2: return 2;
    case 3: return 9;
    case 4: return 64;
    case 5: return 625;
    case 6: return 7776;
    case 7: return 117649;
    case 8: return 2097152;
  }
  return 0;
}

int main(int argc, char *argv[]){
  int N, K; 
  scanf("%d%d", &N, &K);
  int ans = 1;
  REP(i, N-K) ans = ((long long)ans * (N-K)) % MOD;
  ans = ((long long)ans * get(K)) % MOD;
  printf("%d\n", ans);
  return 0;
}