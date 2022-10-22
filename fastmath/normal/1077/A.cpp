#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    #ifdef HOME 
        freopen("input.txt", "r", stdin);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int a, b, k;
        cin >> a >> b >> k;
        cout << a * ((k + 1) / 2) - b * (k / 2) << '\n';
    }   

    return 0;
}