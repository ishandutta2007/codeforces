#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define forab(i, a, b) for (int i = int(a); i < int(b); ++i)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; --i)
#define sz(c) int((c).size())
#define all(c) (c).begin(), (c).end()
#define mp(x, y) make_pair(x, y)
#define pb push_back
#define fst first
#define snd second

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;
using vvi = vector<vi>;

#define FILE_NAME "a"

const int MAXN = 30;

int n;
int t[MAXN];
pii a[MAXN];
int b[MAXN];

bool read() {
    if (scanf("%d\n", &n) < 1) {
        return 0;
    }
    forn(i, n) {
        scanf("%d", &a[i].fst);
        a[i].snd = i;
        t[i] = a[i].fst;
    }
    return 1;
}

void solve() {
    sort(a, a + n);
    b[a[0].snd] = a[n - 1].fst;
    for (int i = 1; i < n; i++) {
        b[a[i].snd] = a[i - 1].fst;   
    }
    
    forn(i, n) {
        printf("%d%c", b[i], " \n"[i == n - 1]);   
    }
/*    
    forn(mask, 1 << n) {
        if (mask == 0 || mask == ((1 << n) - 1)) {
            continue;
        }
        int sum = 0;
        forn(i, n) {
            if ((mask >> i) & 1) {
                sum += t[i] - b[i];   
            }
        }
        if (sum == 0) {
            forn(i, n) {
                cout << ((mask >> i) & 1);
            }
            cout << endl;
            assert(false);
        }
    }
*/    
}

int main() {
#ifdef LOCAL
    freopen(FILE_NAME ".in", "r", stdin);
//    freopen(FILE_NAME ".out", "w", stdout);
#endif
   
    while (read()) {
        solve();
    }

    return 0;
}