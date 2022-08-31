#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 20;
int N;
int A[MAXN][2];

const int MAXV = 2 * MAXN;
int V;
int D[MAXV];
int par[MAXV];
int c[MAXV]; // 0 is a tree, 1 is a cycle, 2 is more
int getpar(int a) { return par[a] == -1 ? a : (par[a] = getpar(par[a])); }
void merge(int a, int b) {
 a = getpar(a), b = getpar(b);
 if (a != b) {
  if (a < b) swap(a,b);
  assert(a > b);
  par[b] = a;
  c[a] += c[b] - 1;
 }
 c[a] ++;
}

int main() {
 ios_base::sync_with_stdio(0);
 cin >> N;
 for (int i = 0; i < N; i++) cin >> A[i][0] >> A[i][1], D[V++] = A[i][0], D[V++] = A[i][1];
 sort(D, D + V);
 V = unique(D, D + V) - D;
 for (int i = 0; i < N; i++) A[i][0] = lower_bound(D, D+V, A[i][0]) - D;
 for (int i = 0; i < N; i++) A[i][1] = lower_bound(D, D+V, A[i][1]) - D;
 memset(par, -1, sizeof(par));
 for (int i = 0; i < N; i++) merge(A[i][0], A[i][1]);
 int cost = 0;
 for (int i = 0; i < V; i++) {
  if (par[i] == -1 && c[i] > 1) { cout << -1 << '\n'; return 0; }
 }
 int res = 0;
 for (int i = 0; i < V; i++) {
  if (par[i] != -1 || c[i] == 1) res = D[i];
 }
 cout << res << '\n';
}