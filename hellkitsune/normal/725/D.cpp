#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
LL t[300005], w[300005];
pair<LL, LL> p[300005];
LL tt;

struct Cmp {
    inline bool operator()(const int &lhs, const int &rhs) const {
        if (w[lhs] - t[lhs] != w[rhs] - t[rhs]) {
            return w[lhs] - t[lhs] < w[rhs] - t[rhs];
        }
        return lhs < rhs;
    }
};

set<int, Cmp> q;

int main() {
    scanf("%d", &n);
    forn(i, n) {
        scanf("%I64d%I64d", t + i, w + i);
    }
    tt = t[0];
    --n;
    forn(i, n) {
        p[i] = mp(-t[i + 1], w[i + 1]);
    }
    sort(p, p + n);
    forn(i, n) {
        t[i] = -p[i].first;
        w[i] = p[i].second;
    }
    int ind = 0;
    while (ind < n && t[ind] > tt) {
        q.insert(ind);
        ++ind;
    }
    int ans = ind;
    while (!q.empty()) {
        int i = *q.begin();
        q.erase(q.begin());
        if (w[i] - t[i] + 1 > tt) {
            break;
        }
        tt -= w[i] - t[i] + 1;
        while (ind < n && t[ind] > tt) {
            q.insert(ind);
            ++ind;
        }
//        for (int x : q) cerr << x << ' ';
//        cerr << "!" << endl;
        ans = min(ans, (int)q.size());
    }
    cout << ans + 1 << endl;
    return 0;
}