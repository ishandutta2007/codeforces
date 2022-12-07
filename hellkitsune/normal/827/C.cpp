#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

mt19937 mt(time(0));

int n, q;
char s[100005];
int fen[4][11][10][100000];

void fenInc(int *fen, int ind) {
    for (; ind < n; ind |= ind + 1) {
        ++fen[ind];
    }
}

void fenDec(int *fen, int ind) {
    for (; ind < n; ind |= ind + 1) {
        --fen[ind];
    }
}

inline int fenGet(int *fen, int ind) {
    int res = 0;
    for (; ind >= 0; ind = (ind & (ind + 1)) - 1) {
        res += fen[ind];
    }
    return res;
}

int fenGet(int *fen, int from, int to) {
    return fenGet(fen, to) - fenGet(fen, from - 1);
}

map<char, int> ma;

char t[15];

int main() {
    ma['A'] = 0;
    ma['T'] = 1;
    ma['G'] = 2;
    ma['C'] = 3;
    scanf("%s%d", s, &q);
    n = strlen(s);
    forn(i, n) {
        int c = ma[s[i]];
        for (int j = 1; j <= 10; ++j) {
            fenInc(fen[c][j][i % j], i);
        }
    }
    forn(_, q) {
        int qt;
        scanf("%d", &qt);
        if (qt == 1) {
            int ind;
            char cc;
            scanf("%d %c", &ind, &cc), --ind;
            int c = ma[cc];
            int oldC = ma[s[ind]];
            s[ind] = cc;
            for (int j = 1; j <= 10; ++j) {
                fenDec(fen[oldC][j][ind % j], ind);
                fenInc(fen[c][j][ind % j], ind);
            }
        } else {
            int from, to;
            scanf("%d%d%s", &from, &to, t), --from, --to;
            int len = strlen(t);
            int ans = 0;
            forn(i, len) {
                int c = ma[t[i]];
                ans += fenGet(fen[c][len][(from + i) % len], from, to);
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}