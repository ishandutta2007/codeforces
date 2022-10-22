#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 7;
int r[N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);            
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> r[i]; --r[i];
    }   
    int ptr = 0;
    int ans = 0;
    while (ptr < n) {
        ++ans;
        int nr = r[ptr];
        int i = ptr;
        while (i < nr) {
            ++i;
            nr = max(nr, r[i]);
        }   
        ptr = i + 1;
    }
    cout << ans << '\n';
}