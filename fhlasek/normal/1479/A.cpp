/* Written by Filip Hlasek 2021 */
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
#define REP(i, b) for (int i = 0; i < (b); i++)

using namespace std;

int N;

int get_element(int n) {
  if (n < 1 || n > N) return N + 1;
  printf("? %d\n", n);
  fflush(stdout);
  int ans;
  scanf("%d", &ans);
  return ans;
}

int main(int argc, char* argv[]) {
  scanf("%d", &N);
  int l = 1, r = N;
  while (l < r) {
    int m = (l + r) / 2;
    if (get_element(m) < get_element(m + 1)) {
      r = m;
    } else {
      l = m + 1;
    }
  }
  printf("! %d\n", l);

  return 0;
}