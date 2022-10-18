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

long long K;
int A0, B0;
int A[3][3], B[3][3];

int score(int a, int b) {
  a++; b++;
  if (a == b) return 0;
  if (a == 1 && b == 2) return 2;
  if (a == 1 && b == 3) return 1;
  if (a == 2 && b == 1) return 1;
  if (a == 2 && b == 3) return 2;
  if (a == 3 && b == 1) return 2;
  if (a == 3 && b == 2) return 1;
  return -1;
}

void update(int &A0, int &B0) {
  int na = A[A0][B0];
  B0 = B[A0][B0] - 1;
  A0 = na - 1;
}

long long last[3][3];

long long ans[3];

int main(int argc, char *argv[]) {
  cin >> K >> A0 >> B0;
  A0--; B0--;

  REP(i, 3) REP(j, 3) scanf("%d", &A[i][j]);
  REP(i, 3) REP(j, 3) scanf("%d", &B[i][j]);

  REP(i, 3) REP(j, 3) last[i][j] = -1;

  long long step = 0;
  while (step < K) {
    if (last[A0][B0] != -1) {
      int gap = step - last[A0][B0];
      long long rep = (K - step) / gap;
      REP(i, gap) {
        ans[score(A0, B0)] += rep;
        update(A0, B0);
      }
      step += rep * gap;
      while (step < K) {
        ans[score(A0, B0)]++;
        update(A0, B0);
        step++;
      }
      break;
    } else {
      last[A0][B0] = step;
      ans[score(A0, B0)]++;
      update(A0, B0);
      step++;
    }
  }
  cout << ans[1] << " " << ans[2] << endl;
  return 0;
}