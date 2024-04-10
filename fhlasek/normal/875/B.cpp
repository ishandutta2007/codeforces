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

#define MAXN 333333
bool done[MAXN];

int main(int argc, char *argv[]) {
  int N;
  scanf("%d", &N);
  int pt = N;
  printf("1");
  REP(i, N) {
    int a;
    scanf("%d", &a);
    done[a] = true;
    while (done[pt]) pt--;
    printf(" %d", (i + 2) - (N - pt));
  }
  printf("\n");
  return 0;
}