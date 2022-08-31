#include<bits/stdc++.h>
using namespace std;

int main() {
int N; cin >> N;
string S; cin >> S; S = '\0' + S + '\0';
N = int(S.size());
vector<bool> dp(N * N);
for (int i = 0; i+1 < N; i++) {
dp[i*N+(i+1)] = true;
}
for (int l = 2; l < N; l++) {
for (int i = 0, j = l; j < N; i++, j++) {
for (int k = i+1; k <= j-1; k++) {
if ((S[i] == S[k]-1 || S[j] == S[k]-1) && dp[i*N+k] && dp[k*N+j]) dp[i*N+j] = true;
}
}
}
vector<int> dist(N);
for (int i = 0; i < N; i++) {
for (int j = i+1; j < N; j++) {
if (dp[i*N+j]) dist[j] = max(dist[j], dist[i] + j-i-1);
}
}
cout << dist[N-1] << '\n';
}