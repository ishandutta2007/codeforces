#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector <int> cnt(26);
    for (int i = 0; i < n; ++i) ++cnt[s[i] - 'a'];

    auto check = [&] (string t) {
       bool fl = true;
       for (int i = 1; i < n; ++i) {
           fl &= (abs(t[i] - t[i - 1]) != 1);
       }
       return fl; 
    };

    string a;
    for (int i = 0; i < 26; i += 2) {
        for (int j = 0; j < cnt[i]; ++j) {
            a += char('a' + i);
        }
    }
    string c = a;
    reverse(c.begin(), c.end());
    string b;
    for (int i = 1; i < 26; i += 2) {
        for (int j = 0; j < cnt[i]; ++j) {
            b += char('a' + i);
        }
    }
    string d = b;
    reverse(d.begin(), d.end());

    string t = a + b;
    if (check(t)) {
        cout << t << '\n';
        return;
    }

    t = a + d;
    if (check(t)) {
        cout << t << '\n';
        return;
    }

    t = c + b;
    if (check(t)) {
        cout << t << '\n';
        return;
    }

    t = c + d;
    if (check(t)) {
        cout << t << '\n';
        return;
    }
    cout << "No answer\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while (t--) solve();
}