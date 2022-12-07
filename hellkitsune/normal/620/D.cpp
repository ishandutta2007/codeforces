#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

struct T {
    int val, x, y;
    T(int val, int x, int y) : val(val), x(x), y(y) {}
};

inline bool cmp(const T &lhs, const T &rhs) {
    return lhs.val < rhs.val;
}

int n, m;
int a[2000], b[2000], ao[2000], bo[2000], tmp[2000];
vector<T> aa, bb;
LL cur = 0, ans;
int k = 0;
vector<PII> ops;

inline bool acmp(const int &lhs, const int &rhs) {
    return a[lhs] < a[rhs];
}

inline bool bcmp(const int &lhs, const int &rhs) {
    return b[lhs] < b[rhs];
}

void reord(int *a, int *ao, int n, bool isa) {
    REP(i, n) ao[i] = i;
    sort(ao, ao + n, isa ? acmp : bcmp);
    REP(i, n) tmp[i] = a[ao[i]];
    REP(i, n) a[i] = tmp[i];
}

int main() {
    scanf("%d", &n);
    REP(i, n) scanf("%d", a + i);
    scanf("%d", &m);
    REP(i, m) scanf("%d", b + i);
    reord(a, ao, n, true);
    reord(b, bo, m, false);

    REP(i, n) cur += a[i];
    REP(i, m) cur -= b[i];
    ans = abs(cur);

    int j = 0;
    REP(i, n) {
        LL c = cur - 2 * a[i];
        while (j < m - 1 && c + 2 * b[j + 1] <= 0) ++j;
        if (abs(c + 2 * b[j]) < ans) {
            ans = abs(c + 2 * b[j]);
            k = 1;
            ops.clear();
            ops.pb(mp(i, j));
        }
        if (j < m - 1 && abs(c + 2 * b[j + 1]) < ans) {
            ans = abs(c + 2 * b[j + 1]);
            k = 1;
            ops.clear();
            ops.pb(mp(i, j + 1));
        }
    }
    if (n > 1 && m > 1) {
        REP(i, n) for (int j = i + 1; j < n; ++j) aa.pb(T(a[i] + a[j], i, j));
        REP(i, m) for (int j = i + 1; j < m; ++j) bb.pb(T(b[i] + b[j], i, j));
        n = (int)aa.size();
        m = (int)bb.size();
        sort(aa.begin(), aa.end(), cmp);
        sort(bb.begin(), bb.end(), cmp);

        j = 0;
        REP(i, n) {
            LL c = cur - 2ll * aa[i].val;
            while (j < m - 1 && c + 2ll * bb[j + 1].val <= 0) ++j;
            if (abs(c + 2ll * bb[j].val) < ans) {
                ans = abs(c + 2ll * bb[j].val);
                k = 2;
                ops.clear();
                ops.pb(mp(aa[i].x, bb[j].x));
                ops.pb(mp(aa[i].y, bb[j].y));
            }
            if (j < m - 1 && abs(c + 2ll * bb[j + 1].val) < ans) {
                ans = abs(c + 2ll * bb[j + 1].val);
                k = 2;
                ops.clear();
                ops.pb(mp(aa[i].x, bb[j + 1].x));
                ops.pb(mp(aa[i].y, bb[j + 1].y));
            }
        }
    }
    cout << ans << endl;
    printf("%d\n", k);
    REP(i, k) printf("%d %d\n", ao[ops[i].first] + 1, bo[ops[i].second] + 1);
    return 0;
}