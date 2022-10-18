/* Written by Filip Hlasek 2015 */
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,b) for(int i=0;i<(b);i++)

using namespace std;

#define MAXN 111111
int N, Q;
int H[MAXN];

int sS[MAXN], sP[MAXN], S;

int main(int argc, char *argv[]) {
  scanf("%d%d", &N, &Q);
  REP(i, N) scanf("%d", H + i);
  while (Q--) {
    int L, R;
    scanf("%d%d", &L, &R);
    L--; R--;
    long long tmp = 0;
    long long sum = 0;

    S = 1;
    sS[0] = 1000000000;
    sP[0] = L;
    FOR(i, L + 1, R) {
      int diff = abs(H[i] - H[i - 1]);
      tmp += diff;
      while (diff > sS[S - 1]) {
        // printf("change: %d %d\n", diff - sS[S - 1], sP[S - 1] - sP[S - 2]);
        tmp += (long long)(diff - sS[S - 1]) * (sP[S - 1] - sP[S - 2]);
        S--;
      }
      sS[S] = diff; sP[S] = i; S++;
      sum += tmp;
    }

    cout << sum << endl;
  }

  return 0;
}