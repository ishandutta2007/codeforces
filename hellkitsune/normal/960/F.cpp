#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m;
int from, to, w;
int ans = 0;
set<PII> se[100000];

int setGet(set<PII> &se, int w) {
    auto it = se.lower_bound(mp(w, -1));
    if (it != se.begin()) {
        --it;
        return it->second;
    }
    return 0;
}

void setPut(set<PII> &se, int w, int val) {
    auto it = se.lower_bound(mp(w, -1));
    if (it != se.end() && it->first == w) {
        if (it->second >= val) {
            return;
        }
        auto it2 = it;
        ++it2;
        se.erase(it);
        it = it2;
    }
    while (it != se.end()) {
        if (it->second > val) {
            break;
        }
        auto it2 = it;
        ++it2;
        se.erase(it);
        it = it2;
    }
    if (it != se.begin()) {
        --it;
        if (it->second >= val) {
            return;
        }
    }
    se.insert(mp(w, val));
}

int main() {
    scanf("%d%d", &n, &m);
    forn(_, m) {
        scanf("%d%d%d", &from, &to, &w);
        --from, --to;
        int val = setGet(se[from], w) + 1;
        ans = max(ans, val);
        setPut(se[to], w, val);
    }
    cout << ans << endl;
    return 0;
}