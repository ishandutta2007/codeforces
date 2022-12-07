#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int a[1000005];
LL ans[1000005] = {};
LL p[1000005] = {};
LL q[1000005] = {};

void addlr(int from, int to, int val) {
//    cerr << from << ' ' << to << ": " << val << endl;
    p[from] += val - 1;
    p[to] -= val - 1;
    q[from] += 1;
    q[to] -= 1;
    p[to] -= to - from;
}

void calc() {
    forn(i, n) q[i + 1] += q[i];
    assert(q[n] == 0);
    forn(i, n) p[i] += q[i];
    forn(i, n) p[i + 1] += p[i];
    assert(p[n] == 0);
    forn(i, n) ans[i] += p[i];
    memset(p, 0, sizeof p);
    memset(q, 0, sizeof q);
}

int main() {
//    freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    forn(i, n) scanf("%d", a + i), --a[i];

    forn(i, n) {
        int from = n - 1 - a[i];
        int to = n;
        from += i;
        to += i;
        if (from >= n) {
            addlr(from - n, to - n, 0);
        } else {
            addlr(from, n, 0);
            addlr(0, to - n, n - from);
        }
    }
    calc();
    reverse(ans, ans + n);
//    cerr << endl << endl;


    forn(i, n) {
        int from = a[i];
        int to = n;
        from -= i;
        to -= i;
        if (from < 0) {
            addlr(from + n, n, 0);
            addlr(0, to, -from);
        } else {
            addlr(from, to, 0);
        }
    }
    calc();

    int best = 0;
    forn(i, n) if (ans[i] < ans[best]) {
        best = i;
    }

    cout << ans[best] << ' ' << best << endl;
    return 0;
}