#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    int n;
    cin >> n;
    while (n % 3 == 0) n /= 3;
    cout << (n + 2) / 3 << '\n';

}