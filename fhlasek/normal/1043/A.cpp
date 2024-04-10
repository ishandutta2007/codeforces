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

int main(int argc, char *argv[]) {
  int N, sumA = 0, K = 0;
  scanf("%d", &N);
  REP(i, N) {
    int A;
    scanf("%d", &A);
    sumA += A;
    K = max(K, A);
  }
  printf("%d\n", max(K, 2 * sumA / N + 1));
  return 0;
}