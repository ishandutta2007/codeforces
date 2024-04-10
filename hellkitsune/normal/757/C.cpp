#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m;
set<int> se[1000001];
int where[1000001];
int sz = 1;
int cnt;
int a[500005];
PII b[500005];
int bc;
vector<int> cur;

inline bool cmp(const int &lhs, const int &rhs) {
    return where[lhs] < where[rhs];
}

void update() {
    sort(cur.begin(), cur.end(), cmp);
    int cnt = int(cur.size());
    for (int beg = 0; beg < cnt; ) {
        int end = beg + 1;
        while (end < cnt && where[cur[beg]] == where[cur[end]]) {
            ++end;
        }
        int w = where[cur[beg]];
        if (int(se[w].size()) > end - beg) {
            for (int i = beg; i < end; ++i) {
                se[w].erase(cur[i]);
            }
            for (int i = beg; i < end; ++i) {
                se[sz].insert(cur[i]);
                where[cur[i]] = sz;
            }
            ++sz;
        }
        beg = end;
    }
}

const int MOD = int(1e9) + 7;

int fac[1000005];

int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    forn(i, m) {
        se[0].insert(i + 1);
        where[i + 1] = 0;
    }
    forn(_, n) {
        scanf("%d", &cnt);
        forn(i, cnt) {
            scanf("%d", a + i);
        }
        sort(a, a + cnt);
        cur.clear();
        bc = 0;
        for (int beg = 0; beg < cnt; ) {
            int end = beg + 1;
            while (end < cnt && a[beg] == a[end]) {
                ++end;
            }
            b[bc++] = mp(end - beg, a[beg]);
            beg = end;
        }
        sort(b, b + bc);
        for (int beg = 0; beg < bc; ) {
            int end = beg + 1;
            while (end < bc && b[beg].first == b[end].first) {
                ++end;
            }
            cur.clear();
            for (int i = beg; i < end; ++i) {
                cur.pb(b[i].second);
            }
            update();
            beg = end;
        }
    }
    fac[0] = 1;
    for (int i = 1; i < 1000005; ++i) {
        fac[i] = (LL)fac[i - 1] * i % MOD;
    }
    int ans = 1;
    forn(i, sz) {
        ans = (LL)ans * fac[int(se[i].size())] % MOD;
    }
    cout << ans << endl;
    return 0;
}