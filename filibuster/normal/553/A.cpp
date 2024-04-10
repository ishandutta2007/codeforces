#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 1000 + 13;

/*

*/

int sum(int a, int b) {
    int res = a + b;

    if(res >= M)
        res -= M;

    return res;
}

int pow2(int n, int k) {
    if(k == 0)
        return 1;

    int pw = pow2(n, k / 2);
    if(k & 1)
        return pw * 1ll * pw % M * n % M;
    else
        return pw * 1ll * pw % M;
}

int a[N], s[N], p[N];
int dp[N];
int C[N][N];



int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);
    C[0][0] = 1;
    C[1][0] = C[1][1] = 1;
    for(int i = 0; i < N; i++) {
        C[i][0] = C[i][i] = 1;
//        cout << i << endl;
        for(int j = 1; j < i; j++) {
            C[i][j] = sum(C[i - 1][j], C[i - 1][j - 1]);
        }
    }
//    p[0] = 1;
//    for(int i = 1; i < N; i++)
//        p[i] = p[i - 1] * 1ll * i % M;

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    s[0] = 0;
    for(int i = 1; i <= n; i++)
        s[i] = s[i - 1] + a[i - 1];

    dp[0] = 1;
    for(int i = 1; i < n; i++) {
        dp[i] = dp[i - 1] * 1ll * C[s[i] + a[i] - 1][s[i]] % M;
//        cout << i << ' ' << dp[i] << endl;
    }

    cout << dp[n - 1] << endl;
}