#include<bits/stdc++.h>

using namespace std;


int N, L, K, A[200];
double P[200];

double dp[201][201][401];
bool memo[201][201][401];

double rec(int idx, int win, int bag) {
  bag = min(bag, 400);
  win = max(win, 0);
  if(idx == N) {
    if(win == 0 && bag >= 200) return 1.0;
    return 0.0;
  }
  if(exchange(memo[idx][win][bag], true)) return dp[idx][win][bag];
  double ret = 0.0;
  ret = max(ret, rec(idx + 1, win - 1, bag + (~A[idx] ? A[idx] : -1)) * P[idx] + rec(idx + 1, win, bag) * (1.0 - P[idx]));
  return dp[idx][win][bag] = ret;
}

int main() {
  cin >> N >> L >> K;
  for(int i = 0; i < N; i++) {
    cin >> P[i];
    P[i] /= 100.0;
  }
  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }
  cout << fixed << setprecision(10) << rec(0, L, 200 + K) << endl;
}