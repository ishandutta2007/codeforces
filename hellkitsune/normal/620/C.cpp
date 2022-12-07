#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

struct HashSet {
    static const int BCNT = 200003;
    vector<int> b[BCNT];
    vector<int> ne;

    void insert(int x) {
        int n = x % BCNT;
        if (n < 0) n += BCNT;
        for (int val : b[n]) if (val == x) {
            return;
        }
        if (b[n].empty()) ne.pb(n);
        b[n].pb(x);
    }

    int count(int x) {
        int n = x % BCNT;
        if (n < 0) n += BCNT;
        for (int val : b[n]) if (val == x) {
            return 1;
        }
        return 0;
    }

    void clear() {
        for (int x : ne) b[x].clear();
        ne.clear();
    }
};

int n;
int a[300000];
HashSet se;
vector<int> ans;

int main() {
    scanf("%d", &n);
    REP(i, n) scanf("%d", a + i);
    REP(i, n) if (se.count(7 - a[i])) {
        se.clear();
        ans.pb(i);
    } else {
        se.insert(7 - a[i]);
    }
    if (ans.empty()) {
        printf("-1\n");
    } else {
        printf("%d\n", (int)ans.size());
        ans.back() = n - 1;
        int beg = 0;
        for (int x : ans) {
            printf("%d %d\n", beg + 1, x + 1);
            beg = x + 1;
        }
    }
    return 0;
}