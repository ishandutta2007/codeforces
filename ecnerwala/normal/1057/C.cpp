#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int N, S, K;
int R[60];
char C[60];
int mem[60][3000];
int dp(int n, int k) {
  assert(k > 0);
  k -= R[n];
  if (k <= 0) return 0;
  if (mem[n][k]) return mem[n][k];
  int v = INF;
  for (int i = 1; i <= N; i++) {
    if (C[i] == C[n] || R[i] <= R[n]) continue;
    v = min(dp(i, k) + abs(i-n), v);
  }
  return mem[n][k] = v;
}

int main() {
  cin >> N >> S >> K;
  for (int i = 1; i <= N; i++) cin >> R[i];
  cin >> (C+1);
  int v = INF;
  for (int i = 1; i <= N; i++) {
    v = min(dp(i, K) + abs(i-S), v);
  }
  if (v == INF) v = -1;
  cout << v << '\n';
}