#include <bits/stdc++.h>

#define mp make_pair
#define fs first
#define sc second
#define pb push_back

#define y0 yy0
#define y1 yy1
#define next _next
#define prev _prev
#define link _link
#define hash _hash

#define sz(s) int((s).size())
#define len(s) int((s).size())
#define all(s) (s).begin(), (s).end()

typedef long long ll;
typedef long double ld;

const ll INF = 1e9;
const ll lINF = 1e18;
const double EPS = 1e-12;
const int MOD = 1e9 + 9;

using namespace std;

pair<int, int> v[111111];
map<pair<int, int>, int> num;
set<pair<int, int> > all;
map<int, set<int > > sup, dep;
int n;

set<pair<int, int> > cur;

bool check(int p) {
    for (auto i : sup[p]) {
        if (dep[i].size() == 1) {
            return false;
        }
    }
    return true;
}

int main() {
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &v[i].fs, &v[i].sc);
        all.insert(v[i]);
        num[v[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        for (int j = -1; j < 2; j++) {
            if (all.count(mp(v[i].fs + j, v[i].sc + 1))) {
                sup[num[v[i]]].insert(num[mp(v[i].fs + j, v[i].sc + 1)]);
            }
            if (all.count(mp(v[i].fs + j, v[i].sc - 1))) {
                dep[num[v[i]]].insert(num[mp(v[i].fs + j, v[i].sc - 1)]);
            }
        }
    }

    set<int> cur;
    for (int i = 0; i < n; i++) {
        if (check(i)) {
            cur.insert(i);
        }
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int nxt;
        if (i % 2 == 0) {
            nxt = *(--cur.end());
        } else {
            nxt = *(cur.begin());
        }
        cur.erase(nxt);
        ans = (ans * n + nxt) % MOD;

        for (auto j : sup[nxt]) {
            dep[j].erase(nxt);
            if (dep[j].size() == 1) {
                cur.erase(*dep[j].begin());
            }
        }
        for (auto j : dep[nxt]) {
            sup[j].erase(nxt);
            if (check(j)) {
                cur.insert(j);
            }
        }
    }

    printf("%d", (int) ans);
    return 0;
}