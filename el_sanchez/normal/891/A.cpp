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

const int MAXN = 2222;

int n;
int a[MAXN];

bool read() {
    if (scanf("%d\n", &n) < 1) {
        return 0;
    }
    forn(i, n) {
        scanf("%d", &a[i]);
    }
    return 1;
}

int solve() {
    int ones = 0;
    forn(i, n) {
        if (a[i] == 1) {
            ones++;
        }
    }
    
    if (ones > 0) {
        return n - ones;
    }
    
    // no ones
    static const int INF = (int)1e9;
    
    int min_len = INF;
    for (int L = 0; L < n; L++) {
        int cur = a[L];
        int cur_len = 0;
        for (int R = L; R < n; R++) {
            cur = __gcd(cur, a[R]);
            cur_len++;
            
            if (cur == 1) {
                min_len = min(min_len, cur_len);   
            }
        }
    }
    
    if (min_len == INF) {
        return -1;
    }
    return (min_len - 1) + (n - 1);
}

int main() {
#ifdef LOCAL
    freopen(FILE_NAME ".in", "r", stdin);
//    freopen(FILE_NAME ".out", "w", stdout);
#endif
   
    while (read()) {
        printf("%d\n", solve());
    }

    return 0;
}