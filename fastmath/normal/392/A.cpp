#include<bits/stdc++.h>
using namespace std;                         
#define int long long
int n;
bool in(int x, int y) {
    return x * x + y * y <= n * n;
}   
bool check(int x, int y) {
    return !in(x + 1, y) || !in(x, y + 1);
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n;
    if (n == 0) {
        cout << "1\n";
    }   
    else if (n == 1) {
        cout << "4\n";
    }   
    else {
        int ans = 0, ptr = 0;
        for (int i = n; i >= 1; --i) {
            while (in(i, ptr + 1)) ++ptr;
            int l = ptr;
            while (l && check(i, l - 1)) --l;
            ans += ptr - l + 1;
        }   
        cout << ans * 4 << '\n';
    }
}