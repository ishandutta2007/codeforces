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
const int N = 707;
int n;
int a[N];
bool dl[N][N], dr[N][N], g[N][N];
bool get(int l, int r, int i) {
    return dr[l][i] && dl[i][r];
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            g[i][j] = __gcd(a[i], a[j]) > 1;
    for (int l = n; l; --l) {
        dl[l][l] = dr[l][l] = 1;
        for (int r = l + 1; r <= n; ++r) {
            for (int i = l + 1; i <= r; ++i) 
                dl[l][r] |= g[l][i] && get(l + 1, r, i);
            for (int i = l; i < r; ++i)
                dr[l][r] |= g[i][r] && get(l, r - 1, i);
        }   
    }   
    for (int i = 1; i <= n; ++i) {
        if (get(1, n, i)) {
            cout << "Yes\n";
            exit(0);
        }   
    }   
    cout << "No\n";
}