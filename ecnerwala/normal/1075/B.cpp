#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = 1e18;
const int MAXN = 2e5;
const int MAXM = 2e5;
int N, M;
ll X[MAXN+MAXM];
ll T[MAXN+MAXM];
ll prv[MAXN+MAXM];
ll nxt[MAXN+MAXM];
int A[MAXN+MAXM];

int main() {
  ios_base::sync_with_stdio(0); cin >> N >> M;
for (int i = 0; i < N+M; i++) cin >> X[i];
for (int i = 0; i < N+M; i++) cin >> T[i];
for (int i = 0, v = -1; i < N+M; i++) v = prv[i] = (T[i] ? i : v);
for (int i = N+M-1, v = N+M; i >= 0; i--) v = nxt[i] = (T[i] ? i : v);
for (int i = 0; i < N + M; i++) {
  if (T[i]) continue;
  if (prv[i] != -1 && (nxt[i] == N+M || X[i]-X[prv[i]] <= X[nxt[i]]-X[i])) A[prv[i]]++;
  else A[nxt[i]]++;
}
for (int i = 0; i < N+M; i++) {
  if (T[i]) cout << A[i] << '\n';
}

}