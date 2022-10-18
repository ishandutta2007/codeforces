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

int K;
char ans[MAX_NEEDLE];

int main(int argc, char *argv[]) {
  scanf("%d%d", &N, &K);
  scanf("%s", needle);
  failure();
  FOR(i, 1, N) {
    int l = i - fail[i];
    // printf("i: %d l: %d\n", i, l);
    int left = 1, right = N;
    while (left < right) {
      int middle = (left + right) / 2;
      if (i > (long long)(K + 1) * middle * l) left = middle + 1;
      else right = middle;
    }
    if (i / ((long long)left * l) >= K) ans[i - 1] = '1';
    else ans[i - 1] = '0';
  }
  ans[N] = '\0';
  printf("%s\n", ans);
  return 0;
}