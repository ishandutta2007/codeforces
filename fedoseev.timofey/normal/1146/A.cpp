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
    string s;
    cin >> s;
    int n = s.size();
    int cnt = 0;
    for (auto c : s) {
        if (c == 'a') {
            ++cnt;
        }
    }
    cout << min(n, 2 * cnt - 1) << '\n';
}