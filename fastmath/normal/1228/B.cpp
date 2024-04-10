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
const int MOD = 1000 * 1000 * 1000 + 7, N = 1007;
int t[N][N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) t[i][j] = 2;
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        int x; cin >> x;
        for (int j = 1; j <= x; ++j) {
            if (t[i][j] == 0) {
                cout << "0\n";
                exit(0);
            }
            t[i][j] = 1;                                    
        }   
        if (x != m) {
            if (t[i][x + 1] == 1) {
                cout << "0\n"; exit(0);
            }   
            t[i][x + 1] = 0;
        }   
    }   
    for (int j = 1; j <= m; ++j) {
        int x; cin >> x;
        for (int i = 1; i <= x; ++i) {
            if (t[i][j] == 0) {
                cout << "0\n";
                exit(0);
            }
            t[i][j] = 1;                                    
        }   
        if (x != n) {
            if (t[x + 1][j] == 1) {
                cout << "0\n"; exit(0);
            }   
            t[x + 1][j] = 0;
        }   
    }
    int ans = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (t[i][j] == 2) {
                ans <<= 1;
                ans %= MOD;
            }   
        }   
    }   
    cout << ans << '\n';
}