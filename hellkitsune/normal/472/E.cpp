#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); ++e)
typedef long long LL;
typedef pair<int, int> PII;

int n, m;
int s[31][31], t[31][31], tmp[31];
int cnt[901] = {};
vector<PII> ans;
int posi, posj;

inline void go(int di, int dj) {
    ans.pb(mp(posi + di, posj + dj));
    swap(s[posi][posj], s[posi + di][posj + dj]);
    posi += di;
    posj += dj;
}

void solve(int sti, int stj) {
    ans.pb(mp(sti, stj));
    posi = sti, posj = stj;
    if (posi == 1) go(1, 0);
    if (posj == 1) go(0, 1);
    for (int i = n; i >= 3; --i) for (int j = m; j >= 1; --j) {
        int ii = i, jj = j;
        while (s[ii][jj] != t[i][j] || (ii == posi && jj == posj)) {
            --jj;
            if (jj == 0) jj = m, --ii;
        }
        if (ii == i && jj == j) continue;
        if (posj == jj) {
            if (posj == 1) go(-1, 1);
            else go(-1, -1);
        }
        while (posi < ii) go(1, 0);
        while (posi > ii) go(-1, 0);
        while (posj < jj - 1) go(0, 1);
        while (posj > jj + 1) go(0, -1);
        if (posi == 1) {
            go(1, jj - posj);
            go(-1, 0); ++ii;
            if (posj == 1) go(1, 1);
            else go(1, -1);
        }
        if (posj > jj && jj > 1) {
            go(-1, -1);
            go(1, -1);
        }
        while (jj > 2) {
            go(0, 1);
            --jj;
            go(-1, -1);
            go(1, -1);
        }
        if (jj == 2) {
            go(0, 1);
            --jj;
        }
        while (ii < i) {
            go(1, -1);
            go(-1, 0); ++ii;
            if (ii != i || jj != j) {
                go(1, 1);
            }
        }
        while (jj < j) {
            go(0, -1); ++jj;
            if (jj != j) {
                go(-1, 1);
                go(1, 1);
            }
        }
    }
    for (int j = m; j >= 3; --j) for (int i = 1; i <= 2; ++i) {
        while (posj >= j) go(0, -1);
        if (s[i][j] == t[i][j]) continue;
        if (s[3 - i][j] == t[i][j] && i == 1) {
            if (abs(posj - j) <= 1) {
                go(1 - posi, j - posj);
                go(1, 0);
                continue;
            }
            if (posi == 2) go(-1, 0);
            while (posj < j) go(0, 1);
            while (posj > j) go(0, -1);
            go(1, 0);
            continue;
        }
        int ii = i, jj = j;
        while (s[ii][jj] != t[i][j] || (ii == posi && jj == posj)) {
            ++ii;
            if (ii == 3) ii = 1, --jj;
        }
        if (ii == posi) {
            if (posi == 2) go(-1, 0);
            else go(1, 0);
        }
        while (posj < jj) go(0, 1);
        while (posj > jj) go(0, -1);
        if (ii != i) {
            go(ii - posi, 0);
            ii = 3 - ii;
        }
        if (jj == j) continue;
        go(ii - posi, 1);
        if (posi == 1) {
            go(0, -1); ++jj;
            while (jj < j) {
                go(1, 1);
                go(-1, 1);
                go(0, -1); ++jj;
            }
        } else {
            go(0, -1); ++jj;
            while (jj < j) {
                go(-1, 1);
                go(1, 1);
                go(0, -1); ++jj;
            }
        }
    }
    while (posi > 1) go(-1, 0);
    while (posj > 1) go(0, -1);
    if (s[1][2] != t[1][2]) {
        go(0, 1);
        if (s[2][1] == t[1][2]) go(1, -1), go(-1, 0);
        else go(1, 0), go(-1, -1);
    }
    if (s[2][1] != t[2][1]) {
        go(1, 0);
        go(0, 1);
        go(-1, -1);
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) {
        scanf("%d", s[i] + j);
        ++cnt[s[i][j]];
    }
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) {
        scanf("%d", t[i] + j);
        --cnt[t[i][j]];
    }
    for (int i = 1; i <= 900; ++i) if (cnt[i] != 0) {
        printf("-1\n");
        return 0;
    }
    if (n == 1) {
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j < i; ++j) {
                for (int k = 1; k <= m; ++k) tmp[k] = s[1][k];
                for (int k = i - 1; k >= j; --k)
                    swap(tmp[k], tmp[k + 1]);
                bool flag = true;
                for (int k = 1; k <= m; ++k) if (tmp[k] != t[1][k]) {
                    flag = false;
                    break;
                }
                if (flag) {
                    cout << i - j << '\n';
                    cout << 1 << ' ' << i << '\n';
                    for (int k = i - 1; k >= j; --k)
                        cout << 1 << ' ' << k << '\n';
                    return 0;
                }
            }
            for (int j = i + 1; j <= m; ++j) {
                for (int k = 1; k <= m; ++k) tmp[k] = s[1][k];
                for (int k = i + 1; k <= j; ++k)
                    swap(tmp[k], tmp[k - 1]);
                bool flag = true;
                for (int k = 1; k <= m; ++k) if (tmp[k] != t[1][k]) {
                    flag = false;
                    break;
                }
                if (flag) {
                    cout << j - i << '\n';
                    cout << 1 << ' ' << i << '\n';
                    for (int k = i + 1; k <= j; ++k)
                        cout << 1 << ' ' << k << '\n';
                    return 0;
                }
            }
        }
        cout << "-1\n";
        return 0;
    }
    if (m == 1) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j < i; ++j) {
                for (int k = 1; k <= n; ++k) tmp[k] = s[k][1];
                for (int k = i - 1; k >= j; --k)
                    swap(tmp[k], tmp[k + 1]);
                bool flag = true;
                for (int k = 1; k <= n; ++k) if (tmp[k] != t[k][1]) {
                    flag = false;
                    break;
                }
                if (flag) {
                    cout << i - j << '\n';
                    cout << i << ' ' << 1 << '\n';
                    for (int k = i - 1; k >= j; --k)
                        cout << k << ' ' << 1 << '\n';
                    return 0;
                }
            }
            for (int j = i + 1; j <= n; ++j) {
                for (int k = 1; k <= n; ++k) tmp[k] = s[k][1];
                for (int k = i + 1; k <= j; ++k)
                    swap(tmp[k], tmp[k - 1]);
                bool flag = true;
                for (int k = 1; k <= n; ++k) if (tmp[k] != t[k][1]) {
                    flag = false;
                    break;
                }
                if (flag) {
                    cout << j - i << '\n';
                    cout << i << ' ' << 1 << '\n';
                    for (int k = i + 1; k <= j; ++k)
                        cout << k << ' ' << 1 << '\n';
                    return 0;
                }
            }
        }
        cout << "-1\n";
        return 0;
    }
    bool flag = true;
    for (int i = 1; i <= n; ++i) if (flag) for (int j = 1; j <= m; ++j) if (s[i][j] == t[1][1]) {
        solve(i, j);
        flag = false;
        break;
    }
    printf("%d\n", (int)ans.size() - 1);
    REP(i, ans.size()) {
        printf("%d %d\n", ans[i].first, ans[i].second);
    }
    return 0;
}