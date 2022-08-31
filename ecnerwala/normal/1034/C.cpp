#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int MAXN = 1.1e6;
int N;
ll A[MAXN];
int P[MAXN];
int C[MAXN];
int T[MAXN];
ll dp[MAXN];

int main() {
  ios_base::sync_with_stdio(0);
  cin >> N;
  for (int i = 0; i < N; i++) cin >> A[i];
  for (int i = 1; i < N; i++) cin >> P[i];
  for (int i = N-1; i > 0; i--) A[P[i]-1] += A[i];
  for (int i = 0; i < N; i++) {
    ll d = A[0]/__gcd(A[0], A[i]);
    if (d <= N) C[d] ++;
  }
  dp[1]++;
  for (int d = 1; d <= N; d++) {
    for (int i = d; i <= N; i += d) T[i] += C[d];
    if (T[d]==d) {
      ll v = dp[d]%(ll(1e9)+7);
      for (int i = 0; i <= N; i += d) dp[i] += v;
    }
  }
  cout << dp[0] << '\n';
}