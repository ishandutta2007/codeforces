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

#define MAXN 1111
int X[MAXN], N;

bool valid(int k) {
  REP(i, N) if (X[i] != X[i % k]) return false;
  return true;
}

int main(int argc, char *argv[]) {
  int last = 0;
  scanf("%d", &N);
  REP(i, N) {
    int A;
    scanf("%d", &A);
    X[i] = A - last;
    last = A;
  }
  vector<int> ans;
  FOR(k, 1, N) if (valid(k)) ans.push_back(k);

  printf("%d\n", (int)ans.size());
  REP(i, ans.size()) {
    if (i) printf(" ");
    printf("%d", ans[i]);
  }
  printf("\n");
  return 0;
}