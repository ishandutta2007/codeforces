#include<bits/stdc++.h>
using namespace std;
const int MAXN = 4e5;
int N;
int C[MAXN], A[MAXN];
int vis[MAXN];
int R;

void dfs(int cur){
 if (vis[cur]==-1) {
  // this is the cycle
  int v = C[cur];
  for (int nxt = A[cur]; nxt != cur; nxt = A[nxt]) v = min(v, C[nxt]);
  R += v;
  return;
 } else if (vis[cur]) return;
 vis[cur]=-1;
 dfs(A[cur]);
 vis[cur]=1;
}
int main() {
cin >> N;for (int i = 0; i < N; i++) cin >> C[i];for (int i = 0; i < N; i++) cin >> A[i],A[i]--;
for (int i = 0; i < N; i++) dfs(i);
cout << R  << '\n';
}