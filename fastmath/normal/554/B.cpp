#include <bits/stdc++.h>

using namespace std;

const int MAXN = 107;

int n;
bool a[MAXN][MAXN];

int get(int p) {
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        bool ch = 1;
        for (int j = 0; j < n; ++j) {
            ch &= (a[i][j] == a[p][j]);
        }   
        ans += ch;
    }   
    return ans;
}   

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            char c;
            cin >> c;
            a[i][j] = (c == '1');
        }   
    }   

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = max(ans, get(i));
    }   

    cout << ans << '\n';
    return 0;
}