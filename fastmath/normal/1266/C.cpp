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
#define lb lower_bound
#define ub upper_bound
#define Time (double)clock()/CLOCKS_PER_SEC
const int N = 507;
int n, m;
int r[N], c[N], ans[N][N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n >> m;
    if (n == 1 && m == 1) {
        cout << "0\n";
        exit(0);
    }   
    int ptr = 1;
    if (n < m) {
        for (int i = 1; i <= n; ++i)
            r[i] = ptr++;
        for (int i = 1; i <= m; ++i)
            c[i] = ptr++;
    }
    else {
        for (int i = 1; i <= m; ++i)
            c[i] = ptr++;
        for (int i = 1; i <= n; ++i)
            r[i] = ptr++;
    }   
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j)
            cout << r[i] * c[j] << ' ';
        cout << '\n';
    }
}