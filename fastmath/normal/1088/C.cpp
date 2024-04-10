#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 2007;
const int MOD = 1000 * 1000;

int mod(int n) {
    return (n % MOD + MOD) % MOD;
}   

int want[MAXN];
int a[MAXN];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }   

    for (int i = 0; i < n; ++i) {
        want[i] = mod(i - a[i]);
    }  

    cout << n + 1 << '\n';
    for (int i = n - 1; i >= 0; --i) {
        cout << 1 << ' ' << i + 1 << ' ' << mod(want[i] - want[i + 1]) << '\n';
    }
    cout << 2 << ' ' << n << ' ' << MOD << '\n';

    return 0;
}