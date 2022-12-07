#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int a[100000];
int all[100000], allc = 0;
set<int> se[100000];

int fen[100000];

void fenAdd(int pos, int val) {
    for (; pos < n; pos |= pos + 1) {
        fen[pos] += val;
    }
}

int fenGet(int pos) {
    int res = 0;
    for (; pos >= 0; pos = (pos & (pos + 1)) - 1) {
        res += fen[pos];
    }
    return res;
}

int main() {
    scanf("%d", &n);
    forn(i, n) scanf("%d", a + i);
    forn(i, n) all[i] = a[i];
    sort(all, all + n);
    allc = unique(all, all + n) - all;
    forn(i, n) a[i] = lower_bound(all, all + allc, a[i]) - all;
    forn(i, n) se[a[i]].insert(i);
    forn(i, n) fenAdd(i, 1);
    int ind = 0;
    LL ans = 0;
    forn(i, allc) while (!se[i].empty()) {
        auto it = se[i].lower_bound(ind);
        if (it != se[i].end()) {
            ans += fenGet(*it) - fenGet(ind - 1);
            fenAdd(*it, -1);
            ind = (*it + 1) % n;
            se[i].erase(it);
        } else {
            ans += fenGet(n - 1) - fenGet(ind - 1);
            ans += fenGet(*se[i].begin());
            fenAdd(*se[i].begin(), -1);
            ind = (*se[i].begin() + 1) % n;
            se[i].erase(se[i].begin());
        }
    }
    cout << ans << endl;
    return 0;
}