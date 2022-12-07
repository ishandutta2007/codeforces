#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m;
int a[100005], b[100005], c[100005], fen[100005];

void fenAdd(int pos, int val) {
    for (; pos < 100005; pos |= pos + 1) {
        fen[pos] = max(fen[pos], val);
    }
}

int fenGet(int pos) {
    int res = 0;
    for (; pos >= 0; pos = (pos & (pos + 1)) - 1) {
        res = max(res, fen[pos]);
    }
    return res;
}

int main() {
    scanf("%d%d", &n, &m);
    forn(i, n) {
        int from, to;
        scanf("%d%d", &from, &to), --from, --to;
        ++a[from];
        --a[to + 1];
    }
    forn(i, m) a[i + 1] += a[i];
    assert(a[m] == 0);

    forn(i, 100005) fen[i] = 0;
    forn(i, m) {
        int cur = fenGet(a[i]) + 1;
        fenAdd(a[i], cur);
        b[i] = cur;
    }

    forn(i, 100005) fen[i] = 0;
    for (int i = m - 1; i >= 0; --i) {
        int cur = fenGet(a[i]) + 1;
        fenAdd(a[i], cur);
        c[i] = cur;
    }

//    forn(i, m) cerr << b[i] << ' ';
//    cerr << endl;
//    forn(i, m) cerr << c[i] << ' ';
//    cerr << endl;

    int ans = 0;
    forn(i, m) {
        ans = max(ans, b[i] + c[i] - 1);
    }
    cout << ans << endl;
    return 0;
}