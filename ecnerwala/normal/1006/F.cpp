#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 40;
const int MAXM = 40;
int N,M;
ll K;
ll A[MAXN][MAXM];
unordered_map<ll, int> mid[MAXN];

int main() {
cin >> N >> M >> K;
for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) cin >> A[i][j];
N--,M--;
A[0][0] ^= K; K = 0;
if (!N && !M) {
cout << (A[0][0] == 0) << '\n';
return 0;
}
A[N][M] ^= A[0][0]; A[0][0]=0;
for (int i = 0; i < (1<<N); i++) {
if (__builtin_popcount(i) > M) continue;
int x = 0, y = 0;
ll v = 0;
for (int k=0; k < N; k++) {
if (i & (1 << k)) y++; else x++;
v ^= A[x][y];
}
mid[x][v] ++;
}
ll res = 0;
for (int i = 0; i < (1<<M); i++) {
if (__builtin_popcount(i) > N) continue;
int x=N, y =M;
ll v = 0;
for (int k = 0; k < M; k++) {
v ^= A[x][y];
if (i & (1 << k)) x--; else y--;
}
res += mid[x][v];
}
cout << res << '\n';
}