#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5001;
int n, k;
int a[N];
bool used[N][N];
int ans[N];
int cnt[N];
void col(int i, int c) {
    ans[i] = c;
    used[c][a[i]] = 1;
    cnt[c]++;
}   
signed main() {
    #ifdef HOME
        freopen("input.txt", "r", stdin);
    #else
        ios_base::sync_with_stdio(false);
        cin.tie(0);
    #endif
    
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i){
        bool ch = 0;
        for (int c = 0; c < k; ++c) {
            ch |= !used[c][a[i]];
        }   
        if (!ch) {
            cout << "NO\n";
            exit(0);
        }   
        bool f = 0;
        for (int c = 0; c < k; ++c) {
            if (!used[c][a[i]] && !cnt[c]) {
                f = 1;
                col(i, c);
                break;
            }   
        }   
        if (!f) {
            for (int c = 0; c < k; ++c) {
                if (!used[c][a[i]]) {
                    col(i, c);
                    break;
                }   
            }   
        }   
    }   
    cout << "YES\n";
    for (int i = 0; i < n; ++i) cout << ans[i] + 1 << ' ';
    cout << '\n';
    #ifdef HOME
        cout << "TIME: " << (double)clock() / CLOCKS_PER_SEC << '\n';  
    #endif
}