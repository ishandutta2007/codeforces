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

int main(int argc, char *argv[]){
  int N, K, unrated = 0;
  long long sum =  0;
  scanf("%d%d", &N, &K);
  REP(i, N) {
    int a;
    scanf("%d", &a);
    if(sum - (long long)(i - unrated) * (N - i - 1) * a < K) {
      unrated++;
      printf("%d\n", i + 1);
    }
    else sum += (long long)(i - unrated) * a;
  }
  return 0;
}