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

#define MAXN 111111
int A[MAXN];
int N;

int main(int argc, char* argv[]) {
  scanf("%d", &N);
  REP(i, N) scanf("%d", A + i);
  int last = 0, before = 0;
  int ans = 0;
  REP(i, N) {
    // printf("i: %d A[i]: %d before: %d last: %d\n", i, A[i], before, last);
    if (A[i] == before) {
      if (A[i] == last) continue;
      else { ans++; last = A[i]; }
    } else {
      ans++;
      if (A[i] == last) { before = last; }
      else {
        if (last != before) before = 0;
        last = A[i];
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}