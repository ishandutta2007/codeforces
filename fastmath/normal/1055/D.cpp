#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 3007;

string a[MAXN], b[MAXN];

int l[MAXN], r[MAXN];

mt19937 rnd(time(0));

int MOD = -1;

const int BASE = 129;

const int MN = 1e9;
const int ADD = 1e6 + 7;

bool check(int n) {
    for (int d = 2; d * d <= n; ++d) {
        if (n % d == 0) return 0;
    }   
    return 1;
}   

void gen() {
    while (1) {
        MOD = MN + rnd() % ADD;
        if (check(MOD)) break;
    }   
}

int mod(int n) {
    return (n % MOD + MOD) % MOD;
}

int n;
int pw[MAXN];
vector <int> h[MAXN];

void calc() {
    pw[0] = 1;
    for (int i = 1; i < MAXN; ++i) pw[i] = mod(pw[i - 1] * BASE);
    for (int i = 0; i < n; ++i) {
        h[i].push_back(0);
        for (int j = 0; j < (int)a[i].size(); ++j) {
            h[i].push_back(mod(h[i].back() * BASE + a[i][j]));
        }   
    }   
}

int geth(int i, int l, int r) {
    return mod(h[i][r + 1] - h[i][l] * pw[r - l + 1]);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    
    gen();
    calc();

    for (int i = 0; i < n; ++i) {
        l[i] = MAXN;
        r[i] = -MAXN;
        for (int t = 0; t < (int)a[i].size(); ++t) {
            if (a[i][t] != b[i][t]) {
                l[i] = min(l[i], t);
                r[i] = max(r[i], t);
            }   
        }
    }   

    string s, t;
    for (int i = 0; i < n; ++i) {
        if (l[i] <= r[i]) {
            for (int j = l[i]; j <= r[i]; ++j) {
                s += a[i][j];
                t += b[i][j];
            }
            break;  
        }   
    }   
    
    for (int i = 0; i < n; ++i) {
        if (l[i] <= r[i]) {
            if (r[i] - l[i] + 1 != s.size()) {
                cout << "NO\n";
                exit(0);
            }   
            for (int j = 0; j < (int)s.size(); ++j) {
                if (s[j] != a[i][l[i] + j]) {
                    cout << "NO\n";
                    exit(0);
                }   
                if (t[j] != b[i][l[i] + j]) {
                    cout << "NO\n";
                    exit(0);
                }   
            }   
        }   
    }   
    
    while (1) {
        bool ch = 1;
        char c = 0;
        for (int i = 0; i < n; ++i) {
            if (l[i] <= r[i]) {
                if (l[i] == 0) {
                    ch = 0;
                }
                else {
                    if (!c) c = a[i][l[i] - 1];
                    else if (c != a[i][l[i] - 1]) ch = 0;
                }   
            }   
        }   
        if (!ch) break;
        for (int i = 0; i < n; ++i) {
            if (l[i] <= r[i]) --l[i];
        }   
    }

    while (1) {
        bool ch = 1;
        char c = 0;
        for (int i = 0; i < n; ++i) {
            if (l[i] <= r[i]) {
                if (r[i] == a[i].size() - 1) {
                    ch = 0;
                }   
                else {
                    if (!c) c = a[i][r[i] + 1];
                    else if (c != a[i][r[i] + 1]) ch = 0;
                }   
            }   
        }   
        if (!ch) break;
        for (int i = 0; i < n; ++i) {
            if (l[i] <= r[i]) ++r[i];
        }   
    }   

    s.clear();
    t.clear();
    for (int i = 0; i < n; ++i) {
        if (l[i] <= r[i]) {
            for (int j = l[i]; j <= r[i]; ++j) {
                s += a[i][j];
                t += b[i][j];
            }
            break;  
        }   
    }   

    int w = 0;
    for (char c : s) w = mod(w * BASE + c);

    for (int i = 0; i < n; ++i) {
        if (l[i] <= r[i]) {
            for (int j = 0; j < l[i]; ++j) {
                if (w == geth(i, j, j + s.size() - 1)) {
                    cout << "NO\n";
                    exit(0);
                }   
            }   
        }
        else {
            for (int j = 0; j + s.size() - 1 < (int)a[i].size(); ++j) {
                if (w == geth(i, j, j + s.size() - 1)) {
                    cout << "NO\n";
                    exit(0);
                }   
            }   
        }
    }   

    cout << "YES\n";
    cout << s << '\n';
    cout << t << '\n';

    return 0;
}