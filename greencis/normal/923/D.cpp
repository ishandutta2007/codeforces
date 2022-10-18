#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

struct entry {
    int L, R, cntb, enda;
} t1[400005], t2[400005];

string s, t;
int slen, tlen;

inline entry combine(const entry& a, const entry& b) {
    if (a.L == -1)
        return b;
    if (b.L == -1)
        return a;
    return {a.L, b.R, a.cntb + b.cntb, b.enda + (b.R - b.L + 1 == b.enda ? a.enda : 0)};
}

void build1(int v, int tl, int tr) {
    if (tl == tr)
        t1[v] = {tl, tr, s[tl] == 'B', s[tl] == 'A'};
    else {
        int tm = (tl + tr) >> 1;
        build1(v << 1, tl, tm);
        build1(v << 1 ^ 1, tm + 1, tr);
        t1[v] = combine(t1[v << 1], t1[v << 1 ^ 1]);
    }
}

void build2(int v, int tl, int tr) {
    if (tl == tr)
        t2[v] = {tl, tr, t[tl] == 'B', t[tl] == 'A'};
    else {
        int tm = (tl + tr) >> 1;
        build2(v << 1, tl, tm);
        build2(v << 1 ^ 1, tm + 1, tr);
        t2[v] = combine(t2[v << 1], t2[v << 1 ^ 1]);
    }
}

entry get1(int v, int tl, int tr, int l, int r) {
    if (l > r) return {-1, -1, -1, -1};
    if (l == tl && r == tr)
        return t1[v];
    int tm = (tl + tr) >> 1;
    return combine(get1(v << 1, tl, tm, l, min(r, tm)), get1(v << 1 ^ 1, tm + 1, tr, max(l, tm + 1), r));
}

entry get2(int v, int tl, int tr, int l, int r) {
    if (l > r) return {-1, -1, -1, -1};
    if (l == tl && r == tr)
        return t2[v];
    int tm = (tl + tr) >> 1;
    return combine(get2(v << 1, tl, tm, l, min(r, tm)), get2(v << 1 ^ 1, tm + 1, tr, max(l, tm + 1), r));
}

char anss[100005];
int ansi;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> s >> t;
    for (int i = 0; s[i]; ++i)
        if (s[i] == 'C')
            s[i] = 'B';
    for (int i = 0; t[i]; ++i)
        if (t[i] == 'C')
            t[i] = 'B';
    slen = s.size();
    tlen = t.size();
    build1(1, 0, slen - 1);
    build2(1, 0, tlen - 1);
    int q;
    cin >> q;
    while (q--) {
        int xa, ya, xb, yb;
        cin >> xa >> ya >> xb >> yb;
        --xa; --ya; --xb; --yb;
        entry A = get1(1, 0, slen - 1, xa, ya);
        entry B = get2(1, 0, tlen - 1, xb, yb);
        char ans = '0';
        if (A.cntb > B.cntb || (A.cntb - B.cntb) % 2 != 0 || A.enda < B.enda)
            ans = '0';
        else if (A.cntb == B.cntb) {
            if ((B.enda - A.enda) % 3 == 0)
                ans = '1';
            else
                ans = '0';
        } else if (A.enda == A.R - A.L + 1) {
            if (B.enda < A.enda)
                ans = '1';
            else
                ans = '0';
        } else
            ans = '1';
        anss[ansi++] = ans;
    }
    cout << anss << endl;
}