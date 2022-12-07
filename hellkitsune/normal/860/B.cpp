#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
vector<PII> v, nv;
char s[70000][10];

int main() {
    scanf("%d", &n);
    forn(i, n) {
        scanf("%s", s[i]);
    }
    forn(i, n) {
        vector<PII> z;
        forn(j, 9) {
            int cur = 0;
            for (int k = j; k < 9; ++k) {
                cur = 10 * cur + (s[i][k] - '0');
                z.pb(mp(cur, k - j));
            }
        }
        sort(z.begin(), z.end());
        z.erase(unique(z.begin(), z.end()), z.end());
        for (PII p : z) {
            v.pb(p);
        }
    }
    sort(v.begin(), v.end());
    for (int i = 1; i < (int)v.size(); ++i) {
        if (v[i] == v[i - 1]) {
            if (nv.empty() || nv.back() != v[i]) {
                nv.pb(v[i]);
            }
        }
    }
    forn(i, n) {
        int bj = 0, bk = 1234;
        forn(j, 9) {
            int cur = 0;
            for (int k = j; k < 9; ++k) {
                cur = 10 * cur + (s[i][k] - '0');
                auto it = lower_bound(nv.begin(), nv.end(), mp(cur, k - j));
                if (it == nv.end() || *it != mp(cur, k - j)) {
                    if (k - j < bk - bj) {
                        bj = j;
                        bk = k;
                    }
                }
            }
        }
        for (int j = bj; j <= bk; ++j) {
            printf("%c", s[i][j]);
        }
        puts("");
    }
    return 0;
}