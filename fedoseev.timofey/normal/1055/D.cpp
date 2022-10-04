#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int get_first(string a, string b) {
    string s = a;
    s += '$';
    s += b;
    s += '%';
    int n = s.size();
    vector <int> z(n);
    z[0] = n;
    int l = 0, r = 0;
    for (int i = 1; i < n; ++i) {
        z[i] = max(0, min(z[i - l], r - i));
        while (s[i + z[i]] == s[z[i]]) ++z[i];
        if (i + z[i] > r) {
            r = i + z[i];
            l = i;
        }
    }
    for (int i = a.size() + 1; i < n; ++i) {
        if (z[i] == a.size()) {
            return i - (int)a.size() - 1;
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    vector <string> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector <string> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    vector <int> ok(n);
    for (int i = 0; i < n; ++i) ok[i] = (a[i] == b[i]);
    string mem = "";
    string kek = "";
    int lf = -1, rt = -1;
    int who = -1;
    vector <int> l(n);
    vector <int> r(n);
    for (int i = 0; i < n; ++i) {
        if (!ok[i]) {
            int fi = 1e9, ls = -1e9;
            for (int j = 0; j < a[i].size(); ++j) {
                if (a[i][j] != b[i][j]) {
                    fi = min(fi, j);
                    ls = max(ls, j);
                }
            }
            l[i] = fi;
            r[i] = ls;
        }
    }

    vector <int> idx;
    for (int i = 0; i < n; ++i) {
        if (!ok[i]) idx.push_back(i);
    }
    for (int j = 1; j < idx.size(); ++j) {
        int i = idx[j];
        int k = idx[j - 1];
        if (a[i].substr(l[i], r[i] - l[i] + 1) != a[k].substr(l[k], r[k] - l[k] + 1)) {
            cout << "NO\n";
            return 0;
        }
        if (b[i].substr(l[i], r[i] - l[i] + 1) != b[k].substr(l[k], r[k] - l[k] + 1)) {
            cout << "NO\n";
            return 0;
        }
    }
    while (true) {
        char c;
        bool bad = false;
        for (int i : idx) {
            if (l[i] == 0) {
                bad = true;
                break;
            }
            c = a[i][l[i] - 1];
        }
        if (bad) break;
        for (int i : idx) {
            if (c != a[i][l[i] - 1]) {
                bad = true;
                break;
            }
        }
        if (bad) break;
        for (int i : idx) {
            --l[i];
        }
    }
    while (true) {
        char c;
        bool bad = false;
        for (int i : idx) {
            if (r[i] == (int)a[i].size() - 1) {
                bad = true;
                break;
            }   
            c = a[i][r[i] + 1];
        }
        if (bad) break;
        for (int i : idx) {
            if (c != a[i][r[i] + 1]) {
                bad = true;
                break;
            }
        }
        if (bad) break;
        for (int i : idx) {
            ++r[i];
        }
    }
    int i0 = idx[0];
    mem = a[i0].substr(l[i0], r[i0] - l[i0] + 1);
    kek = b[i0].substr(l[i0], r[i0] - l[i0] + 1);
    for (int i = 0; i < n; ++i) {
        int x = get_first(mem, a[i]);
        if (ok[i] && x != -1) {
            cout << "NO\n";
            return 0;
        }
        if (!ok[i] && x == -1) {
            cout << "NO\n";
            return 0;
        }
        if (ok[i]) continue;
        for (int j = 0; j < mem.size(); ++j) {
            if (x + j >= (int)a[i].size() || mem[j] != a[i][x + j]) {
                cout << "NO\n";
                return 0;
            }
            a[i][x + j] = kek[j];
        }
        if (a[i] != b[i]) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    cout << mem << '\n' << kek << '\n';
}