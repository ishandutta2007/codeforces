#include <bits/stdc++.h>

using namespace std;

#define int long long

int get(int n) {
    string s = to_string(n);
    int ans = 0;
    for (char c : s) ans += (c - '0');
    return ans;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int a = 0;
    while (a * 10 + 9 <= n) {
        a = a * 10 + 9;
    }
    int b = n - a;
    cout << get(a) + get(b) << '\n';

    return 0;
}