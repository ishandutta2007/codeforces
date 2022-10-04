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
    string t;
    cin >> t;
    int cnt = 0;
    for (auto c : t) {
        if (c == 'a') ++cnt;
    }
    int n = t.size();
    if ((n - cnt) % 2 == 1) {
        cout << ":(\n";
        return 0;
    }
    int m = (n - cnt) / 2;
    string s = t.substr(0, m + cnt);
    string s1;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] != 'a') s1 += s[i];
    }
    if (s + s1 == t) {
        cout << s << '\n';
    }
    else {
        cout << ":(\n";
    }
}