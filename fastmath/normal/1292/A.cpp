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
const int N = 2e5 + 7;
bool ban[3][N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n, q;
    cin >> n >> q;
    int cnt = 0;
    while (q--) {
        int x, y;
        cin >> x >> y;
        if (ban[x][y]) {
            for (int i = -1; i <= 1; ++i) {
                int t = y + i;
                if (1 <= t && t <= n && ban[3 - x][t]) {
                    --cnt;
                }   
            }
        }
        else {
            for (int i = -1; i <= 1; ++i) {
                int t = y + i;
                if (1 <= t && t <= n && ban[3 - x][t]) {
                    ++cnt;
                }   
            }
        }   
        ban[x][y] ^= 1;
        if (cnt == 0)
            cout << "Yes\n";
        else
            cout << "No\n";
    }   
}