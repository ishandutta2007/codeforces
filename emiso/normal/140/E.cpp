#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, m, p, l[1000100], dp[5050][5050], ways[5050][5050], arr[5050], fat[5050];
ll sum = 1;

int main() {;
    scanf("%d %d %d", &n, &m, &p);
    for(int i = 1; i <= n; i++) scanf("%d", &l[i]);

    fat[0] = 1;
    for(ll i = 1; i < 5050; i++)
        fat[i] = i * fat[i-1] % p;

    arr[0] = 1;
    for(ll i = 1; i < 5050; i++)
        arr[i] = (m-i+1) * arr[i-1] % p;

    ways[0][0] = 1;
    for(ll c = 1; c <= 5000; c++)
        for(int i = 1; i <= 5000; i++)
            ways[c][i] = ((c-1) * ways[c][i-1] + ways[c-1][i-1]) % p;

    for(int I = 1, i = 1; I <= n; I++, i ^= 1) {
        for(int j = 1; j <= min(l[I], m); j++) {
            dp[i][j] = (sum - dp[i^1][j] + p) * arr[j] % p * ways[j][l[I]] % p;
            dp[i][j] += 1LL * dp[i^1][j] * (arr[j] - fat[j] + p) % p * ways[j][l[I]] % p;
            if(dp[i][j] >= p) dp[i][j] -= p;
        }

        for(int j = 1; j <= min(l[I-1], m); j++) {
            dp[i^1][j] = 0;
        }

        sum = 0;
        for(int j = 1; j <= min(l[I], m); j++) {
            sum += dp[i][j];
            if(sum >= p) sum -= p;
        }
    }

    printf("%lld\n", sum);
    return 0;
}