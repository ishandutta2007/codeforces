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

#define MAXN 7777
int N;
int K[2], S[2][MAXN];

#define COMPUTING -1
#define WIN 3
#define LOOP 2
#define LOOSE 1

int out[2][MAXN];
/*
int dp[2][MAXN];

int evaluate(int v, bool player) {
  if (!v) return LOOSE;
  if (dp[player][v]) return dp[player][v];
  dp[player][v] = COMPUTING;
  bool all_win = true;
  REP(i, K[player]) {
    int val = evaluate((v + S[player][i]) % N, !player);
    if (val == LOOSE) return dp[player][v] = WIN;
    if (val != WIN) all_win = false;
  }
  if (all_win) return dp[player][v] = LOOSE;
  dp[player][v] = LOOP;
  int best = WIN;
  REP(i, K[player]) {

    best = min(best, evaluate((v + S[player][i]) % N, !player));
  }
  return dp[player][v] = 4 - best;
}
*/

int ans[2][MAXN];
queue<int> qv, qplayer;
void solve(int v, int player) {
  REP(i, K[!player]) {
    int w = (v - S[!player][i] + N) % N;
    if (ans[!player][w] == LOOP) {
      if (ans[player][v] == LOOSE) {
        ans[!player][w] = WIN;
        qv.push(w);
        qplayer.push(!player);
      }
      else {
        out[!player][w]--;
        if (out[!player][w] == 0) {
          // printf("v: %d player: %d ans: %d\n", v, player, ans[player][v]);
          // printf("w: %d player: %d %d\n", w, !player, ans[player][v]);
          ans[!player][w] = LOOSE;
          qv.push(w);
          qplayer.push(!player);
        }
      }
    }
  }
}

int main(int argc, char *argv[]) {
  scanf("%d", &N);
  REP(player, 2) {
    scanf("%d", K + player);
    REP(i, K[player]) scanf("%d", S[player] + i);
  }

  REP(player, 2) {
    REP(i, N) {
      out[player][i] = K[player];
      ans[player][i] = LOOP;
    }
  }

  ans[0][0] = ans[1][0] = LOOSE;
  solve(0, 0);
  solve(0, 1);
  while (!qv.empty()) {
    int v = qv.front(); qv.pop();
    int player = qplayer.front(); qplayer.pop();
    solve(v, player);
  }

  REP(player, 2) {
    FOR(i, 1, N - 1) {
      if (i > 1) printf(" ");
      int val = ans[player][i];
      if (val == WIN) printf("Win");
      if (val == LOOP) printf("Loop");
      if (val == LOOSE) printf("Lose");
    }
    printf("\n");
  }

  return 0;
}