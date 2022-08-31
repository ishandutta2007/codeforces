//Awwawa! Dis cold yis ratten buy Pikachu!
#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>
#define mod 998244353
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
ll ksm(ll a, ll b) {if (b == 0) return 1; ll ns = ksm(a, b >> 1); ns = ns * ns % mod; if (b & 1) ns = ns * a % mod; return ns;}
using namespace std;
const int maxn = 400005;
ll dp[maxn][2][2][2];
char s[maxn];
int main() {
    scanf("%s", s);
    int n = strlen(s);
    for (int i = n; i >= 0; i--) {
        int j[3];
        for (j[0] = 0; j[0] < 2; j[0]++)
            for (j[1] = 0; j[1] < 2; j[1]++)
                for (j[2] = 0; j[2] < 2; j[2]++) {
                    if (i == n) dp[i][j[0]][j[1]][j[2]] = 1;
                    else {
                        int l[3];
                        ll cur = 0;
                        int cs = s[i] - '0';
                        for (l[0] = 0; l[0] < 2; l[0]++) {
                            for (l[1] = 0; l[1] < 2; l[1]++) {
                                for (l[2] = 0; l[2] < 2; l[2]++) {
                                    int e[3] = {j[0], j[1], j[2]};
                                    int flag = 1;
                                    for (int k = 0; k < 3; k++) {
                                        if (!j[k]) {
                                            if (l[k] > cs) flag = 0;
                                            else if (l[k] < cs) e[k] = 1;
                                        }
                                    }
                                    if ((l[0] ^ l[1]) && (l[0] ^ l[2])) flag = 0;
                                    if (!flag) continue;
                                    cur += dp[i + 1][e[0]][e[1]][e[2]];
                                    cur %= mod;
                                }
                            }
                        }
                        cur %= mod;
                        dp[i][j[0]][j[1]][j[2]] = cur;
                    }
                }
    }
    ll cres = 0;
    for (int i = 0; i < n; i++)
        cres = cres * 2 + s[i] - '0', cres %= mod;
    cres += 1;
    cres %= mod;
    ll tot = cres * cres % mod * cres % mod;
    tot -= 3 * dp[0][0][0][0];
    tot += 3 * cres % mod * cres;
    tot -= cres;
    tot %= mod;
    if (tot < 0) tot += mod;
    cout << tot << endl;
    // (a, a, b)
    return (0 - 0); //<3
}