#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

struct S {
    LL from, to;
    int ind;
    S(LL from, LL to, int ind) : from(from), to(to), ind(ind) {}
};

struct Cmp {
    inline bool operator()(const S &lhs, const S &rhs) const {
        return lhs.to < rhs.to;
    }
};

int n, m;
int x[200000], ord[200000], tmp[200000], cnt[200000] = {};
LL t[200000], ltmp[200000];
set<S, Cmp> seg;
multiset<PII> rem;

const bool cmp(const int &lhs, const int &rhs) {
    return x[lhs] < x[rhs];
}

void reord(int *a) {
    REP(i, n) tmp[i] = a[ord[i]];
    REP(i, n) a[i] = tmp[i];
}

void reordl(LL *a) {
    REP(i, n) ltmp[i] = a[ord[i]];
    REP(i, n) a[i] = ltmp[i];
}

int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    int zzz;
    REP(i, n) scanf("%d%d", x + i, &zzz), t[i] = zzz;
    REP(i, n) ord[i] = i;
    sort(ord, ord + n, cmp);
    reord(x);
    reordl(t);
    int bad = -1;
    REP(i, n) {
        int l = max(bad + 1, x[i]);
        int r = x[i] + t[i];
        if (r >= l) {
            seg.insert(S(l, r, i));
        }
        bad = max(bad, r);
    }
    REP(query, m) {
        int p, b;
        scanf("%d%d", &p, &b);
        auto it = seg.lower_bound(S(0, p, 0));
        if (it != seg.end() && it->from <= p) {
            int ind = it->ind;
            ++cnt[ind];
            t[ind] += b;
            auto it2 = rem.lower_bound(mp(it->from, 0));
            while (it2 != rem.end() && x[ind] + t[ind] >= it2->first) {
                auto it3 = it2;
                ++it3;
                ++cnt[ind];
                t[ind] += it2->second;
                rem.erase(it2);
                it2 = it3;
            }
            auto it3 = it;
            ++it3;
            while (it3 != seg.end() && it3->to <= x[ind] + t[ind]) {
                auto it4 = it3;
                ++it4;
                seg.erase(it3);
                it3 = it4;
            }
            LL from = it->from;
            seg.erase(it);
            seg.insert(S(from, x[ind] + t[ind], ind));
        } else {
            rem.insert(mp(p, b));
        }
    }
    REP(i, n) tmp[ord[i]] = i;
    REP(ii, n) {
        int i = tmp[ii];
        printf("%d %I64d\n", cnt[i], t[i]);
    }
    return 0;
}