#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

struct E {
    int pos, ind;
    E(int pos, int ind) : pos(pos), ind(ind) {}

    inline bool operator < (const E &rhs) const {
        return pos < rhs.pos;
    }
};

int n;
vector<E> ev;
int from[200000], to[200000];
vector<int> all;

const int SZ = 400005;
int fen[SZ];

void fenInc(int pos) {
    for (; pos < SZ; pos |= pos + 1) {
        ++fen[pos];
    }
}

int fenGet(int pos) {
    int res = 0;
    for (; pos >= 0; pos = (pos & (pos + 1)) - 1) {
        res += fen[pos];
    }
    return res;
}

int ans[200000];

int main() {
    scanf("%d", &n);
    REP(i, n) scanf("%d%d", from + i, to + i);
    REP(i, n) all.pb(from[i]), all.pb(to[i]);
    sort(all.begin(), all.end());
    REP(i, n) {
        from[i] = lower_bound(all.begin(), all.end(), from[i]) - all.begin();
        to[i] = lower_bound(all.begin(), all.end(), to[i]) - all.begin();
        ev.pb(E(to[i], i));
    }
    sort(ev.begin(), ev.end());
    int tot = 0;
    for (E e : ev) {
        ans[e.ind] = tot - fenGet(from[e.ind]);
        fenInc(from[e.ind]);
        ++tot;
    }
    REP(i, n) printf("%d\n", ans[i]);
    return 0;
}