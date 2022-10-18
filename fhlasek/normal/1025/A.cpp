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

int cnt[26];
char c[111111];

int main(int argc, char *argv[]) {
  int N;
  scanf("%d", &N);
  scanf("%s", c);
  REP(i, N) cnt[c[i] - 'a']++;
  bool good = N == 1;
  REP(i, 26) if (cnt[i] > 1) good = true;
  printf("%s\n", good ? "Yes" : "No");
  return 0;
}