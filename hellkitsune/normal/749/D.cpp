#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, qq;
int a[200005], b[200005];
vector<int> where[200005];
bool was[200005] = {};
vector<int> ord;
int inv[200005];
vector<int> v;
set<int> se;
int last[200005];

int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    forn(i, n) {
        scanf("%d%d", a + i, b + i);
        --a[i];
        where[a[i]].pb(i);
    }
    for (int i = n - 1; i >= 0; --i) {
        if (!was[a[i]]) {
            was[a[i]] = true;
            ord.pb(a[i]);
            se.insert(i);
            last[a[i]] = i;
        }
    }
    memset(inv, -1, sizeof inv);
    int sz = int(ord.size());
    forn(i, sz) {
        inv[ord[i]] = i;
    }
    memset(was, 0, sizeof was);
    scanf("%d", &qq);
    forn(q, qq) {
        v.clear();
        int cnt;
        scanf("%d", &cnt);
        forn(i, cnt) {
            int x;
            scanf("%d", &x);
            --x;
            if (inv[x] != -1) {
                v.pb(inv[x]);
            }
        }
        for (int x : v) {
            was[x] = true;
        }
        int best = -1;
        forn(i, sz) if (!was[i]) {
            best = i;
            break;
        }
        for (int x : v) {
            was[x] = false;
        }
        if (best == -1) {
            printf("0 0\n");
            continue;
        }
        int num = ord[best];
        for (int x : v) {
            se.erase(last[ord[x]]);
        }
        se.erase(last[num]);

        int from = -1;
        if (!se.empty()) {
            from = *se.rbegin();
            ++from;
        }
        int ind = *lower_bound(where[num].begin(), where[num].end(), from);
        printf("%d %d\n", num + 1, b[ind]);

        se.insert(last[num]);
        for (int x : v) {
            se.insert(last[ord[x]]);
        }
    }
    return 0;
}