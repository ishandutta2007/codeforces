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

int N;

int getNumber(int pos) {
  printf("? %d\n", pos % N + 1);
  fflush(stdout);
  int ans;
  scanf("%d", &ans);
  return ans;
}

int main(int argc, char *argv[]) {
  scanf("%d", &N);
  if (N % 4) {
    printf("! -1\n");
    return 0;
  }
  int A = 0, B = N / 2;
  int a = getNumber(A), b = getNumber(B), c = b, d = a;

  if (a == b) {
    printf("! %d\n", A + 1);
    return 0;
  }

  while (true) {
    int MAB = (A + B) / 2, mab = getNumber(MAB);
    int MCD = MAB + N / 2, mcd = getNumber(MCD);
    if (mab == mcd) {
      printf("! %d\n", MAB + 1);
      return 0;
    }
    if ((a < c) != (mab < mcd)) {
      B = MAB; b = mab; d = mcd;
    } else {
      A = MAB; a = mab; c = mcd;
    }
  }

  return 0;
}