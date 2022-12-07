#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int sum[1 << 18], mx[1 << 18], e[1 << 18];
const int off = 1 << 17;
vector<int> ans;

void stUpdate(int pos, int val, int ee) {
    pos += off;
    sum[pos] = mx[pos] = val;
    e[pos] = ee;
    for (pos >>= 1; pos >= 1; pos >>= 1) {
        int le = 2 * pos;
        int ri = le + 1;
        sum[pos] = sum[le] + sum[ri];
        mx[pos] = max(mx[le], sum[le] + mx[ri]);
    }
}

int stFind(int v, int L, int R, int val) {
    if (L == R) {
        assert(mx[v] == val);
        assert(e[v] != -1);
        return e[v];
    }
    assert(mx[v] >= val);
    int mid = (L + R) >> 1;
    if (mx[2 * v] >= val) {
        return stFind(2 * v, L, mid, val);
    }
    return stFind(2 * v + 1, mid + 1, R, val - sum[2 * v]);
}

int main() {
    scanf("%d", &n);
    forn(i, n) {
        int pos, qt;
        scanf("%d%d", &pos, &qt);
        pos = n - pos;
        if (qt == 0) {
            stUpdate(pos, -1, -1);
        } else {
            int x;
            scanf("%d", &x);
            stUpdate(pos, 1, x);
        }
        if (mx[1] < 1) {
            ans.pb(-1);
        } else {
            ans.pb(stFind(1, 0, off - 1, 1));
        }
    }
    for (int x : ans) {
        printf("%d\n", x);
    }
    return 0;
}