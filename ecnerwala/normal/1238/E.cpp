#include<bits/stdc++.h>
using namespace std;

const int MAXM = 20;
const int MAXN = 1.1e5;
int N, M;
string S;

int cnt[MAXM][MAXM];

int dp[1<<MAXM];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N >> M;
    cin >> S;
    for (int i = 0; i+1 < N; i++) cnt[S[i]-'a'][S[i+1]-'a']++;
    
    for (int m = 0; m < (1<<M); m++) {
        dp[m] = int(1e9);
    }
    dp[0] = 0;
    for (int m = 0; m < (1 << M); m++) {
        for (int a = 0; a < M; a++) {
            for (int b = 0; b < M; b++) {
                if (bool(m&(1<<a)) != bool(m&(1<<b))) {
                    dp[m] += cnt[a][b];
                }
            }
        }
        for (int i = 0; i < M; i++) {
            if (m & (1<<i)) continue;
            dp[m|(1<<i)] = min(dp[m|(1<<i)], dp[m]);
        }
    }
    cout << dp[(1<<M)-1] << '\n';
}