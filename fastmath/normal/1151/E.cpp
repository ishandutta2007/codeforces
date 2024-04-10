#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 7;
int n;
int a[N];
int get(int a, int b) {
    if (a == b) return 0;
    if (b < a) swap(a, b);
    return a * (b - a) + (b - a) * (n - b + 1);
}   
int get(int x) {
    return x * (n - x + 1);
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);                                        
    #endif
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    int ans = 0;
    for (int i = 0; i < n - 1; ++i) {
        ans += get(a[i], a[i + 1]);
    }   
    ans += get(a[0]);
    ans += get(a[n - 1]);
    cout << ans / 2 << '\n';
}