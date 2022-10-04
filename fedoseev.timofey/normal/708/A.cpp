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
    string t = s;
    int uk = 0;
    while (uk < n && s[uk] == 'a') ++uk;
    if (uk == n) {
        t[n - 1] = 'z';
    } else {
        for (int i = uk; i < n; ++i) {
            if (s[i] == 'a') break;
            --t[i];
        }
    }
    cout << t << '\n';
}