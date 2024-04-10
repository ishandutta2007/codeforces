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
const int N = 107;
int s[N], d[N], c[N], ans[N];
bool op[N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
        cin >> s[i] >> d[i] >> c[i];
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j)
            op[j] |= s[j] == i;

        int nd = -1;
        for (int j = 1; j <= m; ++j) {
            if (d[j] == i) {
                nd = j;
            }   
        }

        if (nd != -1) {
            if (c[nd]) {
                cout << "-1\n";
                exit(0);
            }   
            ans[i] = m + 1;
            continue;
        }   

        int l = -1;
        for (int j = 1; j <= m; ++j) 
            if (op[j] && c[j] && (l == -1 || d[j] < d[l]))
                l = j;
        if (l != -1) {
            ans[i] = l;
            --c[l];
        }
    }   
    for (int i = 1; i <= n; ++i)
        cout << ans[i] << ' ';
    cout << endl;
}