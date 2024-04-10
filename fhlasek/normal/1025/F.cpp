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

#define MAXN 2222
int N;
int X[MAXN], Y[MAXN], dx[MAXN], dy[MAXN];

bool cmp(int a, int b) {
  return (long long)dx[a] * dy[b] > (long long)dy[a] * dx[b];
}

int main(int argc, char *argv[]) {
  scanf("%d", &N);
  REP(i, N) scanf("%d%d", X + i, Y + i);

  long long ans = 0;
  REP(i, N) {

    // printf("I: %d %d\n", X[i], Y[i]);


    vector<int> above, bellow;
    REP(j, N) if (j != i) {
      dx[j] = X[j] - X[i];
      dy[j] = Y[j] - Y[i];
      if (dy[j] > 0 || (dy[j] == 0 && dx[j] > 0)) above.push_back(j);
      else bellow.push_back(j);
    }

    int A = above.size(), B = bellow.size();
    sort(above.begin(), above.end(), cmp);
    sort(bellow.begin(), bellow.end(), cmp);

    /*
    printf(" Above: "); REP(j, A) printf("[%d %d] ", X[above[j]], Y[above[j]]); printf("\n");
    printf(" Bellow: "); REP(j, B) printf("[%d %d] ", X[bellow[j]], Y[bellow[j]]); printf("\n");
    */

    int a = 0, b = 0;
    while (a < A || b < B) {
      int x;
      if (b == B || (a != A && !cmp(above[a], bellow[b]))) {
        a++;
        x = A - a + b;
      } else {
        b++;
        x = B - b + a;
      }
      int y = N - x - 2;
      ans += (long long)x * (x - 1) / 2 * y * (y - 1) / 2;
    }

  }

  cout << ans / 2 << endl;
  return 0;
}