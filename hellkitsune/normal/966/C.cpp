#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
LL b[100000];
LL ans[100000], tmp[100000];
vector<LL> cur;

int main() {
    scanf("%d", &n);
    forn(i, n) scanf("%I64d", b + i);
    int cnt = 0;
    for (int bi = 59; bi >= 0; --bi) {
        LL bit = 1ll << bi;
        cur.clear();
        for (int i = 0; i < n; ++i) if (b[i] & bit) {
            cur.pb(b[i]);
            swap(b[i], b[n - 1]);
            --n;
            --i;
        }
        int sz = (int)cur.size();
        int ncnt = 0;
        bool can = true;
        forn(i, cnt) {
            if (can && sz > 0) {
                tmp[ncnt++] = cur[sz - 1];
                --sz;
                can = false;
            }
            tmp[ncnt++] = ans[i];
            if (ans[i] & bit) {
                can = true;
            }
        }
        if (can && sz > 0) {
            tmp[ncnt++] = cur[sz - 1];
            --sz;
            can = false;
        }
        if (sz > 0) {
            printf("No\n");
            return 0;
        }
        forn(i, ncnt) ans[i] = tmp[i];
        cnt = ncnt;
    }
    assert(n == 0);
    puts("Yes");
    forn(i, cnt) printf("%I64d ", ans[i]);
    puts("");

//    puts("");
//    LL x = 0;
//    forn(i, cnt) {
//        x ^= ans[i];
//        printf("%I64d ", x);
//    }
//    puts("");
    return 0;
}