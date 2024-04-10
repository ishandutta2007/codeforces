#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m;
char s[3000][3005];
int le[3000][3000], ri[3000][3000];
int fen[3000];
vector<int> cl[3000];
vector<int> gcl;

void fenAdd(int pos) {
    for (; pos < n; pos |= pos + 1) {
        ++fen[pos];
    }
}

void fenSub(int pos) {
    for (; pos < n; pos |= pos + 1) {
        --fen[pos];
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
    //freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    REP(i, n) scanf("%s", s[i]);
    REP(i, n) REP(j, m) if (s[i][j] == 'z') {
        if (j && s[i][j - 1] == 'z') le[i][j] = le[i][j - 1];
        else le[i][j] = j;
    }
    REP(i, n) for (int j = m - 1; j >= 0; --j) if (s[i][j] == 'z') {
        if (j < m - 1 && s[i][j + 1] == 'z') ri[i][j] = ri[i][j + 1];
        else ri[i][j] = j;
    }
    LL ans = 0;
    REP(col, m + n - 1) {
        int tot = min(col + 1, n);
        for (int i = max(0, col + 1 - m); i < tot; ++i) if (s[i][col - i] == 'z') {
            fenAdd(n - 1 - i);
            cl[le[i][col - i]].pb(n - 1 - i);
            gcl.pb(le[i][col - i]);
            ans += fenGet(min(n - 1 - i + ri[i][col - i] - col + i, n - 1));
            for (int x : cl[col - i]) {
                fenSub(x);
            }
            cl[col - i].clear();
        } else {
            for (int x : gcl) {
                for (int y : cl[x]) {
                    fenSub(y);
                }
                cl[x].clear();
            }
            gcl.clear();
        }
        for (int x : gcl) {
            for (int y : cl[x]) {
                fenSub(y);
            }
            cl[x].clear();
        }
        gcl.clear();
    }
    cout << ans << endl;
    return 0;
}