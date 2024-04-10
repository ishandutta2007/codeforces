#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    #ifdef HOME
        freopen("input.txt", "r", stdin);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a, b, f, k;
    cin >> a >> b >> f >> k;

    if (f > b) {
        cout << "-1\n";
        exit(0);
    }   

    if (a - f > b) {
        cout << "-1\n";
        exit(0);
    }   

    if (k >= 2 && 2 * (a - f) > b) {
        cout << "-1\n";
        exit(0);
    }   

    if (k >= 3 && 2 * f > b) {
        cout << "-1\n";
        exit(0);
    }   

    int curr = b;
    int cnt = 0;
    int ans = 0;
    while (1) {
        if ((cnt + 1 != k && a + (a - f) > curr) || (cnt + 1 == k && curr < a)) {
            ++ans;
            curr = b - (a - f);
        }
        else {
            curr -= a;
        }   
        ++cnt;
        if (cnt == k) {
            break;
        }   

        if ((cnt + 1 != k && a + f > curr) || (cnt + 1 == k && curr < a)) {
            ++ans;
            curr = b - f;
        }
        else {
            curr -= a;
        }   
        ++cnt;
        if (cnt == k) {
            break;
        }   
    }   

    cout << ans << '\n';
    return 0;
}