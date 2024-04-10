#include <bits/stdc++.h>
using namespace std;

typedef __uint128_t i128;

istream &operator >> (istream &is, i128 &n) {
    string s;
    is >> s, n = 0;
    for (char c : s) n = n * 10 + c - '0';
    return is;
}

ostream &operator << (ostream &os, i128 &n) {
    string s;
    while (n) s.push_back(n % 10 + '0'), n /= 10;
    return reverse(s.begin(), s.end()), os << s;
}

const int maxn = 1010;
int T, n, m;
i128 a[maxn], b[maxn];
bool del1[maxn], del2[maxn];
i128 t1[maxn][maxn << 2], t2[maxn][maxn << 2];

#define mid ((l + r) >> 1)
#define ls (k << 1)
#define rs (k << 1 | 1)
void build(i128 *t, int k, int l, int r, i128 v, i128 *a) {
    if (l == r) { t[k] = v / __gcd(v, a[l]); return; }
    build(t, ls, l, mid, v, a), build(t, rs, mid + 1, r, v, a);
    t[k] = __gcd(t[ls], t[rs]);
}

void upd(i128 *t, int k, int l, int r, int p) {
    if (l == r) { t[k] = 0; return; }
    mid >= p ? upd(t, ls, l, mid, p) : upd(t, rs, mid + 1, r, p);
    t[k] = __gcd(t[ls], t[rs]);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i <= m; i++) {
            cin >> b[i];
        }
        for (int i = 1; i <= n; i++) {
            build(t1[i], 1, 1, m, a[i], b);
        }
        for (int i = 1; i <= m; i++) {
            build(t2[i], 1, 1, n, b[i], a);
        }
        memset(del1, 0, sizeof(del1));
        memset(del2, 0, sizeof(del2));
        while (1) {
            for (int i = 1; i <= n; i++) if (!del1[i] && t1[i][1] ^ 1) {
                for (int j = 1; j <= m; j++) {
                    if (!del2[j]) upd(t2[j], 1, 1, n, i);
                }
                del1[i] = 1; goto nxt;
            }
            for (int i = 1; i <= m; i++) if (!del2[i] && t2[i][1] ^ 1) {
                for (int j = 1; j <= n; j++) {
                    if (!del1[j]) upd(t1[j], 1, 1, m, i);
                }
                del2[i] = 1; goto nxt;
            }
            break;
        nxt:;
        }
        if (count(del1 + 1, del1 + n + 1, 0)) {
            cout << "YES\n" << count(del1 + 1, del1 + n + 1, 0) << " " <<
                count(del2 + 1, del2 + m + 1, 0) << "\n";
            for (int i = 1; i <= n; i++) {
                if (!del1[i]) cout << a[i] << " ";
            }
            cout << "\n";
            for (int i = 1; i <= m; i++) {
                if (!del2[i]) cout << b[i] << " ";
            }
            cout << "\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}