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

int main(int argc, char *argv[]) {
  int K;
  scanf("%d", &K);
  if (!K) printf("a");
  char c = 'a';
  while (K) {
    int cnt = 0;
    while (cnt * (cnt + 1) / 2 <= K) cnt++;
    K -= cnt * (cnt - 1) / 2;
    REP(i, cnt) printf("%c", c);
    c++;
  }
  printf("\n");
  return 0;
}