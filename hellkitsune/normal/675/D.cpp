#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

struct S {
    int a, b, par;
    S(int a, int b, int par) : a(a), b(b), par(par) {}
    inline bool operator < (const S &rhs) const {
        return b < rhs.b;
    }
};

int n, a[100000];
set<S> se;
const int MX = 1e9;
vector<int> ans;

int main() {
    scanf("%d", &n);
    REP(i, n) scanf("%d", a + i);
    if (a[0] > 1) se.insert(S(1, a[0] - 1, a[0]));
    if (a[0] < MX) se.insert(S(a[0] + 1, MX, a[0]));
    for (int i = 1; i < n; ++i) {
        int val = a[i];
        auto it = se.lower_bound(S(0, val, 0));
        ans.pb(it->par);
        int x = it->a;
        int y = it->b;
        se.erase(it);
        if (x < val) {
            se.insert(S(x, val - 1, val));
        }
        if (y > val) {
            se.insert(S(val + 1, y, val));
        }
    }
    for (int x : ans) printf("%d ", x);
    printf("\n");
    return 0;
}