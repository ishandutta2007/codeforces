#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

struct E {
    int x;
    bool start;
    E(int x, bool start) : x(x), start(start) {}
};

inline bool cmp(const E &lhs, const E &rhs) {
    if (lhs.x != rhs.x) return lhs.x < rhs.x;
    return lhs.start && !rhs.start;
}

int n, k;
vector<E> ev;
vector<PII> ans;

int main() {
    scanf("%d%d", &n, &k);
    REP(i, n) {
        int from, to;
        scanf("%d%d", &from, &to);
        ev.pb(E(from, true));
        ev.pb(E(to, false));
    }
    sort(ev.begin(), ev.end(), cmp);
    int cnt = 0, pre = -1e9 - 111;
    for (E e : ev) {
        if (cnt >= k) {
            if (!ans.empty() && ans.back().second == pre) {
                ans.back().second = e.x;
            } else {
                ans.pb(mp(pre, e.x));
            }
        }
        if (e.start) ++cnt;
        else --cnt;
        pre = e.x;
    }
    printf("%d\n", (int)ans.size());
    for (PII x : ans) printf("%d %d\n", x.first, x.second);
    return 0;
}