/* Written by Filip Hlasek 2017 */
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
#include <ctime>

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,b) for(int i=0;i<(b);i++)

using namespace std;

#define MAXN 1111111

int N, K;
int P[MAXN];
bool done[MAXN];

int C = 0;
int cycle[MAXN];

bool possible[MAXN];

bool partition(int K) {
  int start = time(NULL);
  possible[0] = true;
  int M = 0;
  REP(i, C) {
    if (i % 20 == 0 && time(NULL) != start) break;
    if (possible[K]) return true;
    int c = cycle[i];
    if (c > K) break;
    FORD(j, M, 0) if (possible[j]) possible[j + cycle[i]] = true;
    M = min(M + c, K - c);
  }
  if (possible[K]) return true;
  int _K = K;
  FORD(i, C - 1, 0) if (cycle[i] <= K) K -= cycle[i];
  if (!K) return true;
  REP(tmp, 10) {
    K = _K;
    random_shuffle(cycle, cycle + C);
    FORD(i, C - 1, 0) if (cycle[i] <= K) K -= cycle[i];
    if (!K) return true;
  }
  return false;
}

int main(int argc, char *argv[]) {
  scanf("%d%d", &N, &K);
  REP(i, N) { scanf("%d", P + i); P[i]--; }
  REP(i, N) if (!done[i]) {
    int x = P[i];
    int l = 1;
    done[i] = true;
    while (x != i) {
      l++;
      done[x] = true;
      x = P[x];
    }
    cycle[C++] = l;
  }

  sort(cycle, cycle + C);

  int m = partition(min(K, N - K)) ? K : K + 1, M = 0;
  REP(i, C) {
    int a = min(K, cycle[i] / 2);
    K -= a;
    M += 2 * a;
  }
  M += K;
  M = min(M, N);

  printf("%d %d\n", m, M);

  return 0;
}