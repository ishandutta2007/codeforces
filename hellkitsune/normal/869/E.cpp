#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef unsigned long long LL;
typedef pair<int, int> PII;

int n, m, q;
LL fen[2500][2500];

void fenAdd(int x, int Y, LL val) {
    for (; x < n; x |= x + 1) {
        for (int y = Y; y < m; y |= y + 1) {
            fen[x][y] ^= val;
        }
    }
}

LL fenGet(int x, int Y) {
    LL res = 0;
    for (; x >= 0; x = (x & (x + 1)) - 1) {
        for (int y = Y; y >= 0; y = (y & (y + 1)) - 1) {
            res ^= fen[x][y];
        }
    }
    return res;
}

inline void fenAdd(int x, int y, int xx, int yy, LL val) {
    fenAdd(xx + 1, yy + 1, val);
    fenAdd(x, yy + 1, val);
    fenAdd(xx + 1, y, val);
    fenAdd(x, y, val);
}

mt19937_64 mt(time(0));
map<pair<PII, PII>, LL> ma;

int main() {
    scanf("%d%d%d", &n, &m, &q);
    forn(i, q) {
        int qt, r1, c1, r2, c2;
        scanf("%d%d%d%d%d", &qt, &r1, &c1, &r2, &c2);
        --r1, --c1, --r2, --c2;
        if (qt == 1) {
            LL val = mt();
            ma[mp(mp(r1, c1), mp(r2, c2))] = val;
            fenAdd(r1, c1, r2, c2, val);
        } else if (qt == 2) {
            LL val = ma[mp(mp(r1, c1), mp(r2, c2))];
            fenAdd(r1, c1, r2, c2, val);
        } else {
            LL val1 = fenGet(r1, c1);
            LL val2 = fenGet(r2, c2);
            if (val1 == val2) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        }
    }
    return 0;
}