#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

vector <int> f(vector <int> a) {
    int k = a.size();
    for (int i = 0; i < k; ++i) {
        bool fnd = false;
        for (int j = 0; j < k; ++j) {
            if (a[j] == i) fnd = true;
        }
        if (fnd) continue;
        for (int j = 0; j < k; ++j) {
            if (a[j] == -1) {
                a[j] = i;
                break;
            }
        }
    }
    return a;
}

void solve() {
    int k;
    cin >> k;
    string s, a, b;
    cin >> s >> a >> b;
    if (a > b) {
        cout << "NO\n";
        return;
    }
    int n = s.size();
    vector <int> kek(k, -1);
    vector <int> used(k, 0);
    bool fl = true;
    for (int i = 0; i < n; ++i) {
        if (kek[s[i] - 'a'] == -1) {
            if (!used[a[i] - 'a']) {
                kek[s[i] - 'a'] = a[i] - 'a';
                used[a[i] - 'a'] = 1;
            }
            else {
                fl = false;
                break;
            }
        }
        else if (kek[s[i] - 'a'] != a[i] - 'a') {
            fl = false;
            break;
        }
    }
    if (fl) {
        cout << "YES\n";
        kek = f(kek);
        for (int i = 0; i < k; ++i) {
            cout << char(kek[i] + 'a');
        }
        cout << '\n';
        return;
    }
    kek.assign(k, -1);
    used.assign(k, 0);
    fl = true;
    for (int i = 0; i < n; ++i) {
        if (kek[s[i] - 'a'] == -1) {
            if (!used[b[i] - 'a']) {
                kek[s[i] - 'a'] = b[i] - 'a';
                used[b[i] - 'a'] = 1;
            }
            else {
                fl = false;
                break;
            }
        }
        else if (kek[s[i] - 'a'] != b[i] - 'a') {
            fl = false;
            break;
        }
    }
    if (fl) {
        cout << "YES\n";
        kek = f(kek);
        for (int i = 0; i < k; ++i) {
            cout << char(kek[i] + 'a');
        }
        cout << '\n';
        return;
    }


    kek.assign(k, -1);
    used.assign(k, 0);
    fl = false;

    for (int i = 0; i < n; ++i) {
        if (kek[s[i] - 'a'] != -1) {
            char c = char(kek[s[i] - 'a'] + 'a');
            if (c < a[i]) {
                break;
            }
            if (!fl && c > b[i]) {
                break;
            }
            if (c < b[i]) fl = 1;
            if (fl && c > a[i]) {
                cout << "YES\n";
                kek = f(kek);
                for (int i = 0; i < k; ++i) {
                    cout << char(kek[i] + 'a');
                }
                cout << '\n';
                return;
            }
        }
        else {
            if (fl) {
                for (int c = a[i] + 1; c < 'a' + k; ++c) {
                    if (!used[c - 'a']) {
                        kek[s[i] - 'a'] = c - 'a';
                        cout << "YES\n";
                        kek = f(kek);
                        for (int i = 0; i < k; ++i) {
                            cout << char(kek[i] + 'a');
                        }
                        cout << '\n';
                        return;
                    }
                }
                if (!used[a[i] - 'a']) {
                    kek[s[i] - 'a'] = a[i] - 'a';
                    used[a[i] - 'a'] = 1;
                }
                else {
                    break;
                }
            }
            else {
                if (a[i] == b[i]) {
                    if (used[a[i] - 'a']) {
                        break;
                    }
                    kek[s[i] - 'a'] = a[i] - 'a';
                    used[a[i] - 'a'] = 1;
                }
                else {
                    if (a[i] > b[i]) {
                        break;
                    }
                    for (int x = a[i] + 1; x < b[i]; ++x) {
                        if (!used[x - 'a']) {
                            kek[s[i] - 'a'] = x - 'a';
                            cout << "YES\n";
                            kek = f(kek);
                            for (int i = 0; i < k; ++i) {
                                cout << char(kek[i] + 'a');
                            }
                            cout << '\n';
                            return;
                        }
                    }
                    if (used[a[i] - 'a']) {
                        break;
                    }
                    kek[s[i] - 'a'] = a[i] - 'a';
                    used[a[i] - 'a'] = 1;
                    fl = true;
                }
            }
        }
    }
    kek.assign(k, -1);
    used.assign(k, 0);
    
    fl = false;

    for (int i = 0; i < n; ++i) {
        if (kek[s[i] - 'a'] != -1) {
            char c = char(kek[s[i] - 'a'] + 'a');
            if (c > b[i]) {
                break;
            }
            if (!fl && c < a[i]) {
                break;
            }
            if (c > a[i]) fl = 1;
            if (fl && c < b[i]) {
                cout << "YES\n";
                kek = f(kek);
                for (int i = 0; i < k; ++i) {
                    cout << char(kek[i] + 'a');
                }
                cout << '\n';
                return;
            }
        }
        else {
            if (fl) {
                for (int c = b[i] - 1; c >= 'a'; --c) {
                    if (!used[c - 'a']) {
                        kek[s[i] - 'a'] = c - 'a';
                        cout << "YES\n";
                        kek = f(kek);
                        for (int i = 0; i < k; ++i) {
                            cout << char(kek[i] + 'a');
                        }
                        cout << '\n';
                        return;
                    }
                }
                if (!used[b[i] - 'a']) {
                    kek[s[i] - 'a'] = b[i] - 'a';
                    used[b[i] - 'a'] = 1;
                }
                else {
                    break;
                }
            }
            else {
                if (a[i] == b[i]) {
                    if (used[a[i] - 'a']) {
                        break;
                    }
                    kek[s[i] - 'a'] = a[i] - 'a';
                    used[a[i] - 'a'] = 1;
                }
                else {
                    if (a[i] > b[i]) {
                        break;
                    }
                    for (int x = a[i] + 1; x < b[i]; ++x) {
                        if (!used[x - 'a']) {
                            kek[s[i] - 'a'] = x - 'a';
                            cout << "YES\n";
                            kek = f(kek);
                            for (int i = 0; i < k; ++i) {
                                cout << char(kek[i] + 'a');
                            }
                            cout << '\n';
                            return;
                        }
                    }
                    if (used[b[i] - 'a']) {
                        break;
                    }
                    kek[s[i] - 'a'] = b[i] - 'a';
                    used[b[i] - 'a'] = 1;
                    fl = true;
                }
            }
        }
    }
    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}