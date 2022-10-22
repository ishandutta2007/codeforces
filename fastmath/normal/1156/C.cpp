#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 7;
int n, r;
int a[N];
bool check(int m) {
    for (int i = 0; i < m; ++i) {
        if (a[n - m + i] < a[i] + r) return 0;
    }   
    return 1;
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n >> r;
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);
    int l = 0;
    int r = n / 2 + 1;
    while (l < r - 1) {
        int m = (l + r) >> 1;
        if (check(m)) l = m;
        else r = m;
    }
    cout << l << '\n';
}