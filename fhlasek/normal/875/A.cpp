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
  int N;
  scanf("%d", &N);
  vector<int> ans;
  FOR(X, max(1, N - 100), N) {
    int x = X;
    int sum = X;
    while (x) { sum += x % 10; x /= 10; }
    if (sum == N) ans.push_back(X);
  }
  printf("%d\n", (int)ans.size());
  REP(i, ans.size()) printf("%d\n", ans[i]);
  return 0;
}