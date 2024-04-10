#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, delta;
int x[100000], vv[100000], v[100000];
int ord[100000], nord[100000], inv[100000];

inline bool cmp(const int &lhs, const int &rhs) {
    if ((LL)x[lhs] * v[rhs] != (LL)x[rhs] * v[lhs]) {
        return (LL)x[lhs] * v[rhs] < (LL)x[rhs] * v[lhs];
    }
    return (LL)x[lhs] * vv[rhs] > (LL)x[rhs] * vv[lhs];
}

inline bool ncmp(const int &lhs, const int &rhs) {
    if ((LL)x[lhs] * vv[rhs] != (LL)x[rhs] * vv[lhs]) {
        return (LL)x[lhs] * vv[rhs] < (LL)x[rhs] * vv[lhs];
    }
    return (LL)x[lhs] * v[rhs] > (LL)x[rhs] * v[lhs];
}

int fen[100000];

void fenAdd(int pos) {
    for (; pos < n; pos |= pos + 1) {
        ++fen[pos];
    }
}

int fenGet(int pos) {
    int res = 0;
    for (; pos >= 0; pos = (pos & (pos + 1)) - 1) {
        res += fen[pos];
    }
    return res;
}

int main() {
    scanf("%d%d", &n, &delta);
    forn(i, n) {
        scanf("%d%d", x + i, v + i);
        vv[i] = abs(v[i] + delta);
        v[i] = abs(v[i] - delta);
        x[i] = abs(x[i]);
    }
    forn(i, n) ord[i] = nord[i] = i;
    sort(ord, ord + n, cmp);
    sort(nord, nord + n, ncmp);

    if (delta == 0) {
        LL ans = 0;
        for (int beg = 0; beg < n; ) {
            int end = beg + 1;
            while (end < n) {
                int lhs = ord[beg];
                int rhs = ord[end];
                if ((LL)x[lhs] * v[rhs] != (LL)x[rhs] * v[lhs]) {
                    break;
                }
                ++end;
            }
            ans += (LL)(end - beg) * (end - beg - 1) / 2;
            beg = end;
        }
        cout << ans << endl;
        return 0;
    }

    forn(i, n) inv[ord[i]] = i;
    forn(i, n) nord[i] = inv[nord[i]];
    LL ans = 0;
    for (int i = n - 1; i >= 0; --i) {
        ans += fenGet(nord[i]);
        fenAdd(nord[i]);
    }
    cout << ans << endl;
    return 0;
}