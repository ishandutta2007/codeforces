#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

struct TLess {
    long long a, b;
    int c, num;

    TLess(long long _a = 0, long long _b = 0, int _c = 0, int _num = 0)
        : a(_a)
        , b(_b)
        , c(_c)
        , num(_num)
    {
    }

    bool operator<(TLess &rhs) {
        return c < rhs.c;
    }
};


long long maxs[51][51][101];
int prev[51][51][101];
int prevq[51][51][101];

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector< TLess > lessons(m);
    for (int i = 0; i < m; ++i) {
        cin >> lessons[i].a >> lessons[i].b >> lessons[i].c;
        lessons[i].num = i + 1;
    }
    sort(lessons.begin(), lessons.end());
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            for (int q = 0; q <= 100; ++q) {
                maxs[i][j][q] = -1000000000000000001;
            }
        }
    }

    for (int i = 0; i < m; ++i) {
        for (int q = 0; q + lessons[i].a <= lessons[i].b; ++q) {
            maxs[1][i][q] = lessons[i].a + q;
            prev[1][i][q] = -1;
        }
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int next = j + 1; next < m; ++next) {
                if (lessons[next].c == lessons[j].c) {
                    continue;
                }
                for (int q = 0; lessons[j].a + q <= lessons[j].b; ++q) {
                    if (maxs[i][j][q] < 0) {
                        continue;
                    }
                    long long cur = lessons[j].a + q;
                    if (cur + k >= lessons[next].a && cur + k <= lessons[next].b) {
                        maxs[i + 1][next][cur + k - lessons[next].a] = max(
                            maxs[i + 1][next][cur + k - lessons[next].a], maxs[i][j][q] + cur + k);
                        prev[i + 1][next][cur + k - lessons[next].a] = j;
                        prevq[i + 1][next][cur + k - lessons[next].a] = q;
                    }
                    if (cur * k >= lessons[next].a && cur * k <= lessons[next].b) {
                        maxs[i + 1][next][cur * k - lessons[next].a] = max(
                            maxs[i + 1][next][cur * k - lessons[next].a], maxs[i][j][q] + cur * k);
                        prev[i + 1][next][cur * k - lessons[next].a] = j;
                        prevq[i + 1][next][cur * k - lessons[next].a] = q;
                    }
                }
            }
        }
    }

    vector< pair< int, long long > > ans;
    int curi = -1;
    int curq = -1;
    for (int i = 0; i < m; ++i) {
        for (int q = 0; q <= 100; ++q) {
            if (maxs[n][i][q] > 0) {
                if (curi < 0) {
                    curi = i;
                    curq = q;
                } else {
                    if (maxs[n][i][q] > maxs[n][curi][curq]) {
                        curi = i;
                        curq = q;
                    }
                }
            }
        }
    }

    if (curi < 0) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    while (n > 0) {
        ans.push_back(make_pair(curi, lessons[curi].a + curq));
        int newi = prev[n][curi][curq];
        int newq = prevq[n][curi][curq];
        curi = newi;
        curq = newq;
        --n;
    }
    reverse(ans.begin(), ans.end());
    for (size_t i = 0; i < ans.size(); ++i) {
        cout << lessons[ans[i].first].num << ' ' << ans[i].second << '\n';
    }

    return 0;
}