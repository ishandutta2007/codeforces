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

int main(int argc, char *argv[]){
  int N, a, K, cnt, ans = 0; 
  scanf("%d%d", &N, &K);
  while(N--){
    scanf("%d", &a);
    cnt = 0;
    while(a){ if(a % 10 == 4 || a % 10 == 7) cnt++; a /= 10; }
    if(cnt <= K) ans++;
  }
  printf("%d\n", ans);
  return 0;
}