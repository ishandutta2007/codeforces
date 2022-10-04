#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int dist(char a, char b) {
    int x = a - 'A';
    int y = b - 'A';
    int res = abs(x - y);
    res = min(res, 26 - res);
    return res;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 1e9;
    for (int i = 0; i + 4 <= n; ++i) {
        ans = min(ans, dist(s[i], 'A') + dist(s[i + 1], 'C') + dist(s[i + 2], 'T') + dist(s[i + 3], 'G'));
    }
    cout << ans << '\n';
}