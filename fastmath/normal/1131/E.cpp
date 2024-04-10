#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 7;
const int C = 26;
const int INF = 1e9 + 7;
string a[N];
struct Ansier {
    bool splash;
    int ans[C];
    int l, r;
    char lc, rc;
    Ansier() {
        splash = 0;
        for (int i = 0; i < C; ++i) ans[i] = 0;
        l = r = 0;
        lc = rc = 0;
    }   
};  
Ansier a1[N];
Ansier get(string s) {
    Ansier a;

    bool ch = 1;
    for (int i = 0; i + 1 < (int)s.size(); ++i) {
        ch &= s[i] == s[i + 1];
    }   

    int n = s.size();

    for (int c = 0; c < C; ++c) {
        char w = c + 'a';
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == w) {
                ++cnt;
                a.ans[c] = max(a.ans[c], cnt);
            }   
            else {
                cnt = 0;
            }   
        }   
    }   

    if (ch) {
        a.splash = 1;
        a.lc = a.rc = s[0];
        a.l = a.r = s.size();
    }
    else {
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] != s[0]) break;
            ++cnt;
        }   
        a.l = cnt;
        a.lc = s[0];

        cnt = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] != s[n - 1]) break;
            ++cnt;
        }   
        a.r = cnt;
        a.rc = s[n - 1];
    }   
    return a;
}   
Ansier merge(Ansier a, Ansier b) {
    Ansier t;
    if (a.splash && b.splash && a.lc == b.lc) {
        t.splash = 1;
        t.lc = t.rc = a.lc;
        t.l = t.r = t.ans[a.lc - 'a'] = a.l + b.l * (a.l + 1);
        return t;
    }
    for (int i = 0; i < C; ++i) {
        t.ans[i] = b.ans[i];
        if (a.ans[i]) {
            t.ans[i] = max(t.ans[i], 1ll);
        }   
    }   
    t.lc = b.lc; t.rc = b.rc;
    if (b.splash) {
        if (a.lc == b.lc) {
            t.l = a.l + b.l * (a.l + 1);
        }
        else {
            t.l = b.l;
        }   
        if (a.rc == b.rc) {
            t.r = a.r + b.r * (a.r + 1);
        }
        else {
            t.r = b.r;
        }   
    }
    else {
        t.l = b.l;
        t.r = b.r;
    }   
    for (int c = 0; c < C; ++c) {
        char w = c + 'a';
        if (b.splash) {
            if (b.lc == w) {
                t.ans[c] = max(t.ans[c], a.ans[c] + b.l * (a.ans[c] + 1));
            }
        }
        else {
            if (b.lc == w && b.rc == w) {
                if (a.ans[c]) {
                    t.ans[c] = max(t.ans[c], b.l + b.r + 1);
                }
            }   
            else if (b.lc == w) {
                if (a.ans[c]) {
                    t.ans[c] = max(t.ans[c], b.l + 1);
                }   
            }
            else if (b.rc == w) {
                if (a.ans[c]) {
                    t.ans[c] = max(t.ans[c], b.r + 1);
                }   
            }   
        }   
    }   
    return t;
}   

void print(Ansier a) {
    #ifdef HOME
    if (a.splash) {
        cout << "splash\n";
        cout << a.l << ' ' << a.lc << '\n';

        for (int i = 0; i < C; ++i) {
            if (a.ans[i]) cout << "ans " << (char)('a' + i) << ' ' << a.ans[i] << '\n';
        }   

        cout << '\n';
    }
    else {
        cout << "not splash\n";
        cout << a.lc << ' ' << a.l << '\n';
        cout << a.rc << ' ' << a.r << '\n';

        for (int i = 0; i < C; ++i) {
            if (a.ans[i]) cout << "ans " << (char)('a' + i) << ' ' << a.ans[i] << '\n';
        }   

        cout << '\n';
    }   
    #endif
}   

signed main() {
    #ifdef HOME
        freopen("input.txt", "r", stdin);
    #else 
        ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) {
        a1[i] = get(a[i]);
    }   
    Ansier c = a1[0];

    print(c);

    for (int i = 1; i < n; ++i) {
        c = merge(c, a1[i]);

        print(c);
    }   
    int ans = 0;
    for (int i = 0; i < C; ++i) ans = max(ans, c.ans[i]);
    cout << ans << '\n';
}