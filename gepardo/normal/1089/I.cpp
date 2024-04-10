#include <bits/stdc++.h>
using namespace std;
const int maxN = 405;
typedef long long ll;
int dp[maxN][maxN];
int fact[maxN];
int f[maxN];
int cnk[maxN][maxN];
int tst;
int mod;
int n;
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int sub(int a, int b) {
    int s = a - b;
    if (s < 0) s += mod;
    return s;
}
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
void solve() {
    cin >> n;
}
int main() {
    cin >> tst >> mod;
    cnk[0][0] = 1;
    fact[0] = 1;
    int lim = 400;
    for (int i = 1; i <= lim; i++) {
        fact[i] = mult(fact[i - 1], i);
        cnk[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            cnk[i][j] = sum(cnk[i - 1][j], cnk[i - 1][j - 1]);
        }
    }
    dp[0][0] = 1;
    for (int cnt = 0; cnt <= lim; cnt++) {
        for (int s = 0; s <= lim; s++) {
            for (int add = 1; add <= lim; add++) {
                if (s + add <= lim) {
                    dp[cnt + 1][s + add] = sum(dp[cnt + 1][s + add], mult(dp[cnt][s], fact[add]));
                }
            }
        }
    }
    for (int i = 3; i <= lim; i++) {
        f[i] = fact[i];
        for (int j = 3; j < i; j++) {
            f[i] = sub(f[i], mult(f[j], dp[j][i]));
        }
        int q = 0;
        for (int k = 1; k <= i + 1; k++) {
            //cout << dp[k + 1][i - k] << " " << k << endl;
            if (k & 1) {
                q = sum(q, dp[k + 1][i]);
            }
            else {
                q = sub(q, dp[k + 1][i]);
            }
        }
        q = mult(q, 2);
        f[i] = sub(f[i], q);
        //cout << f[i] << " " << i << " " << q << endl;
    }
    for (int i = 1; i <= tst; i++) {
        int n;
        cin >> n;
        if (n <= 2) cout << n << '\n';
        else cout << f[n] << '\n';
    }
    return 0;
}