#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using pii = pair<int, int>;

char s[1001001];
int t[1 << 21];

inline int combine(int a, int b) {
    if (a % 2 == 0)
        return a + b;
    return a - b;
}

void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = s[tl] == '0' ? -1 : 1;
    } else {
        int tm = (tl + tr) >> 1;
        build(2 * v, tl, tm);
        build(2 * v + 1, tm + 1, tr);
        t[v] = combine(t[2 * v], t[2 * v + 1]);
    }
}

int get(int v, int tl, int tr, int l, int r) {
    if (l == tl && r == tr)
        return t[v];
    int tm = (tl + tr) >> 1;
    if (r <= tm)
        return get(2 * v, tl, tm, l, r);
    if (l > tm)
        return get(2 * v + 1, tm + 1, tr, l, r);
    return combine(get(2 * v, tl, tm, l, tm),
                   get(2 * v + 1, tm + 1, tr, tm + 1, r));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int ttt;
    cin >> ttt;
    while (ttt--) {
        int q;
        cin >> s >> q;
        int n = strlen(s);
        for (int i = 0; i < n; ++i)
            s[i] = s[i] == '(' || s[i] == ')' ? '0' : '1';
        build(1, 0, n - 1);
        while (q--) {
            int l, r;
            cin >> l >> r;
            --l; --r;
            int ans = get(1, 0, n - 1, l, r);
            cout << abs(ans) / 2 << '\n';
        }
    }
}