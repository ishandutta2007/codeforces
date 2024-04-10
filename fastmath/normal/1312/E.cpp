#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcount
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC
const int N = 507;
int x[N][N], a[N];
bool dp[N][N];
int pref[N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i) {
        dp[i][i] = 1;
        x[i][i] = a[i];
    }   
    for (int l = n; l; --l) {
        for (int r = l + 1; r <= n; ++r) {
            for (int i = l; i < r; ++i) {
                if (dp[l][i] && dp[i + 1][r] && x[l][i] == x[i + 1][r]) {
                    dp[l][r] = 1;
                    x[l][r] = x[l][i] + 1;
                }   
            }   
        }   
    }       
    for (int i = 1; i <= n; ++i) {
        pref[i] = N;
        for (int len = 1; len <= i; ++len) {
            if (dp[i - len + 1][i])
                pref[i] = min(pref[i], pref[i - len] + 1);
        }   
    }
    cout << pref[n] << endl;
}