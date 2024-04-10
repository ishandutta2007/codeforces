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
const int N = 1007;
bool ans[N][N];
int c[N], cnt[N], ptr = 1;
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < N; ++j) cnt[j] = 0;
        for (int j = 0; j < n + 1; ++j) ++cnt[c[j]];
        int x; cin >> x;
        int color = -1;
        for (int j = 0; j < N; ++j) {
            if (cnt[j] > 1) {
                color = j;
                break;
            }   
        }   
        if (color == -1) {
            for (int j = 0; j < x; ++j) ans[j][i] = 1;
            continue;
        }   
        vector <int> p;
        for (int j = 0; j < n + 1; ++j) 
            if (c[j] == color) 
                p.app(j);
        ans[p[0]][i] = 0;
        ans[p[1]][i] = 1;
        --x;
        for (int j = 0; j < n + 1; ++j) {
            if (j == p[0] || j == p[1]) continue;
            else if (x) { ans[j][i] = 1; --x; }
        }   
        for (int j = 0; j < n + 1; ++j) 
            if (c[j] == color && ans[j][i]) 
                c[j] = ptr;
        ++ptr;
    }
    cout << n + 1 << '\n';
    for (int i = 0; i < n + 1; ++i) {
        for (int j = 0; j < n; ++j) 
            cout << ans[i][j];
        cout << '\n';
    }   
}