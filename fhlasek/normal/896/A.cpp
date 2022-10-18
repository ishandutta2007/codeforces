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

char f0[] = "What are you doing at the end of the world? Are you busy? Will you save us?";
char f1[] = "What are you doing while sending \"\"? Are you busy? Will you send \"\"?";

char part1[] = "What are you doing while sending \"";
char part2[] = "\"? Are you busy? Will you send \"";
char part3[] = "\"?";

int F0, F1, P1, P2, P3;

#define MAXN 111111
long long L[MAXN];
#define INF 1000000000000000001LL

char solve(int N, long long K) {
  if (K >= L[N]) return '.';
  if (N == 0) return f0[K];
  if (K < P1) return part1[K];
  K -= P1;
  if (K < L[N - 1]) return solve(N - 1, K);
  K -= L[N - 1];
  if (K < P2) return part2[K];
  K -= P2;
  if (K < L[N - 1]) return solve(N - 1, K);
  K -= L[N - 1];
  return part3[K];
}

int main(int argc, char *argv[]) {

  F0 = strlen(f0); F1 = strlen(f1);
  P1 = strlen(part1); P2 = strlen(part2); P3 = strlen(part3);

  L[0] = F0;
  REP(i, MAXN - 1) {
    L[i + 1] = 2 * L[i] + F1;
    L[i + 1] = min(L[i + 1], INF);
  }
  int Q;
  scanf("%d", &Q);
  while (Q--) {
    int N;
    long long K;
    cin >> N >> K;
    printf("%c", solve(N, K - 1));
  }
  printf("\n");
  return 0;
}