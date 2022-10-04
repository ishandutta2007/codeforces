#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int ans = 0;
    for (int c = 0; c < 26; ++c) {
        vector <int> kek;
        for (int i = 0; i < n; ++i) {
            if (s[i] != c + 'a') continue;
            if (i && s[i] == s[i - 1]) ++kek.back();
            else kek.push_back(1);
        }
        int res = 0;
        for (auto x : kek) res += x / k;
        ans = max(ans, res);
    }
    cout << ans << '\n';
}