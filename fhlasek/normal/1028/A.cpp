/* Written by Filip Hlasek 2018 */
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

char line[1111];

int main(int argc, char *argv[]) {
  int sumN = 0, sumM = 0, N, M, total = 0;
  scanf("%d%d", &N, &M);
  REP(i, N) {
    scanf("%s", line);
    REP(j, M) if (line[j] == 'B') { sumN += i; sumM += j; total++; }
  }
  printf("%d %d\n", sumN / total + 1, sumM / total + 1);
  return 0;
}