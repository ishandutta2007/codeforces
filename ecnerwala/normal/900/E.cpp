#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5;
int N;
char S[MAXN];
int M;

int best[MAXN];
int cost[MAXN];
int matchA[MAXN];
int matchB[MAXN];
int numQ[MAXN];

int main() {
ios_base::sync_with_stdio(0);
cin >> N >> S >> M;
matchA[N] = 0;
matchB[N] = 0;
numQ[N] = 0;
for (int i = N-1; i >= 0; i--) {
if (S[i] == '?') matchA[i] = matchB[i+1]+1, matchB[i] = matchA[i+1]+1;
else if (S[i] == 'a') matchA[i] = matchB[i+1]+1, matchB[i] = 0;
else if (S[i] == 'b') matchB[i] = matchA[i+1]+1, matchA[i] = 0;
else assert(false);
numQ[i] = numQ[i+1] + (S[i] == '?');
}
for (int i = 0; i <= N-M; i++) {
numQ[i] -= numQ[i+M];
}
int cb = 0;
int res = 0;
for (int i = N; i >= 0; i--) {
if (best[i] > cb) cb = best[i], res = cost[i];
if (best[i] == cb && cost[i] < res) res = cost[i];
if (i < M) continue;
if (matchA[i-M] >= M) best[i-M] = cb + 1, cost[i-M] = res + numQ[i-M];
}
cout << res << '\n';
}