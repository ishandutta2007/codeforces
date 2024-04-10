#include <bits/stdc++.h>

using namespace std;

const int MAXN = 107;
const int INF = 1e9 + 7;

int n;
bool a[MAXN];

signed main() {
    #ifdef HOME 
        freopen("input.txt", "r", stdin);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    
    int ans = 0;
    int i = 1;
    while (i + 1 < n) {
        if (a[i] == 0 && a[i - 1] && a[i + 1]) {
            a[i + 1] = 0;
            ++ans;
        }   
        ++i;
    }   

    cout << ans << '\n';
    return 0;
}