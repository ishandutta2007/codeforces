#include <bits/stdc++.h>

using namespace std;

bool solve() {
    int n;
    cin >> n;
    vector<string> a(n);
    for (auto &s : a) cin >> s;

    for (auto s : a) {
        if (s == string(s.rbegin(), s.rend())) return true;
    }
    reverse(a.begin(), a.end());

    set<string> ms;
    for (auto s : a) {
        if (string r(s.rbegin() + 1, s.rend()); ms.count(r)) return true;
        if (string r(s.rbegin(), s.rend()); ms.count(r)) return true;
        for (char c = 'a'; c <= 'z'; c++) {
            string t = s + c;
            if (string r(t.rbegin(), t.rend()); ms.count(r)) return true;
        }

        ms.insert(s);
    }

    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        cout << (solve() ? "yEs" : "nO") << '\n';
    }
}