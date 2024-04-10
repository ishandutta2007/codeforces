/* Written by Filip Hlasek 2015 */
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

int main(int argc, char *argv[]) {
  int N, K;
  scanf("%d%d", &N, &K);
  int cnt0 = 0, cnt1 = 0;
  REP(i, N) {
    int a;
    scanf("%d", &a);
    if (a % 2) cnt1++; else cnt0++;
  }
  if (N == K) {
    if (cnt1 % 2 == 0) printf("Daenerys\n");
    else               printf("Stannis\n");
    return 0;
  }
  if ((N - K) % 2 == 0) {
    if (K % 2 && (N - K) / 2 >= cnt0) printf("Stannis\n");
    else                              printf("Daenerys\n");
  }
  else {
    if ((K % 2 == 0 && (N - K) / 2 >= cnt0) || (N - K) / 2 >= cnt1) printf("Daenerys\n");
    else                     printf("Stannis\n");
  }
  return 0;
}