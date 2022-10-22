#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 7;

struct Kek {
    bool h[3];
    int cnt[3][4][4];
};  

Kek tree[MAXN << 2];
    
void relax(int v) {
    auto &t = tree[v];
    auto &l = tree[v * 2 + 1];
    auto &r = tree[v * 2 + 2];

    for (int i = 0; i < 3; ++i) {
        t.h[i] = l.h[i] | r.h[i];
    }
    
    for (int i = 0; i < 3; ++i) {
        for (int a = 0; a < 4; ++a) {
            for (int b = 0; b < 4; ++b) {
                t.cnt[i][a][b] = 0;
            }   
        }   
        int bad = (i + 2) % 3;
        int good = (i + 1) % 3;

        int mask = l.h[bad] + 2 * l.h[good];
        for (int a = 0; a < 4; ++a) {
            for (int b = 0; b < 4; ++b) {
                t.cnt[i][a | mask][b] += r.cnt[i][a][b];
            }
        }   

        mask = r.h[bad] + 2 * r.h[good];
        for (int a = 0; a < 4; ++a) {
            for (int b = 0; b < 4; ++b) {
                t.cnt[i][a][b | mask] += l.cnt[i][a][b];
            }   
        }   
    }   
}

int num(char t) {
    if (t == 'R') {
        return 0;
    }   
    else if (t == 'S') {
        return 1;
    }            
    else if (t == 'P') {
        return 2;
    }   
    exit(1);
}   

void upd(int v, int tl, int tr, int p, char t) {
    if (tl == tr) {
        for (int i = 0; i < 3; ++i) {
            tree[v].h[i] = 0;
            for (int a = 0; a < 4; ++a) {
                for (int b = 0; b < 4; ++b) {
                    tree[v].cnt[i][a][b] = 0;
                }   
            }   
        }   
        int n = num(t);
        tree[v].h[n] = 1;
        tree[v].cnt[n][0][0] = 1;
        return;
    }
    int tm = (tl + tr) >> 1;
    if (p <= tm) {
        upd(v * 2 + 1, tl, tm, p, t);
    }   
    else {
        upd(v * 2 + 2, tm + 1, tr, p, t);
    }   
    relax(v);
}   

int get() {
    int ans = 0;
    for (int i = 0; i < 3; ++i) {
        for (int a = 0; a < 4; ++a) {
            for (int b = 0; b < 4; ++b) {
                if (a != 1 && b != 1) {
                    ans += tree[0].cnt[i][a][b];
                }   
            }   
        }   
    }   
    return ans;
}   

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    #ifdef HOME
        freopen("input.txt", "r", stdin);
    #endif

    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    for (int i = 0; i < n; ++i) {
        upd(0, 0, n - 1, i, s[i]);
    }   
    cout << get() << '\n';
    for (int i = 0; i < q; ++i) {
        int p; char t;
        cin >> p >> t;
        --p;
        upd(0, 0, n - 1, p, t);
        cout << get() << '\n';
    }   

    return 0;
}