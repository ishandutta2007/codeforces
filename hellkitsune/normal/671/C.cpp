#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

struct S {
    int from, to, val;
    S(int from, int to, int val) : from(from), to(to), val(val) {}
    inline bool operator < (const S &rhs) const {
        return to < rhs.to;
    }
};

set<S> se;
vector<int> di[200001];
int n;
int a[200001];
int cnt[200001] = {};
int pos[200001];
LL ans = 0, sum = 0;

void update(int from, int val) {
    auto it = se.lower_bound(S(0, from, 0));
    vector<S> toPush;
    int to = -1;
    for (; it != se.end(); ) {
        if (it->val >= val) break;
        if (it->from < from) {
            toPush.pb(S(it->from, from - 1, it->val));
        }
        sum += (LL)(val - it->val) * (it->to - max(it->from, from) + 1);
        to = it->to;
        auto save = it;
        ++save;
        se.erase(it);
        it = save;
    }
    if (to != -1) {
        se.insert(S(from, to, val));
    }
    for (const S &s : toPush) {
        se.insert(s);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    for (int i = 1; i <= 200000; ++i) {
        for (int j = i; j <= 200000; j += i) {
            di[j].pb(i);
        }
    }
    scanf("%d", &n);
    REP(i, n) scanf("%d", a + i);
    memset(pos, -1, sizeof pos);
    int cur = 0;
    se.insert(S(0, 0, 0));
    for (int i = n - 1; i > 0; --i) {
        for (int x : di[a[i]]) if (++cnt[x] == 1) {
            pos[x] = n - i;
        } else if (cnt[x] == 2) {
            if (pos[x] == n - i) {
                pos[x] = -1;
            }
            cur = max(cur, x);
        }
        se.insert(S(n - i, n - i, cur));
        sum += cur;
    }
    ans = sum;
    cur = 0;
    memset(cnt, 0, sizeof cnt);
    REP(i, n) {
        for (int x : di[a[i]]) if (++cnt[x] == 1) {
            if (pos[x] != -1) {
                update(pos[x], x);
            }
        } else if (cnt[x] == 2) {
            cur = max(cur, x);
        }
        update(0, cur);
        auto it = se.end();
        --it;
        S s = *it;
        se.erase(it);
        sum -= s.val;
        if (s.from < s.to) {
            se.insert(S(s.from, s.to - 1, s.val));
        }
        ans += sum;
    }
    cout << ans << endl;
    return 0;
}