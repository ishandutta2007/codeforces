#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const int INF = int(1e9) + 123;

int n;
int a[300005], aa[300005];
char c[300005], cc[300005];
LL fu[300005], mx[300005];

int main() {
//    freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    forn(i, n) scanf("%d %c", a + i, c + i);
    bool haveG = false;
    forn(i, n) if (c[i] == 'G') {
        haveG = true;
    }
    LL ans = 0;
    if (!haveG) {
        int mnR = INF, mxR = -INF;
        int mnB = INF, mxB = -INF;
        forn(i, n) if (c[i] == 'R') {
            mnR = min(mnR, a[i]);
            mxR = max(mxR, a[i]);
        } else {
            mnB = min(mnB, a[i]);
            mxB = max(mxB, a[i]);
        }
        if (mnR != INF) {
            ans += mxR - mnR;
        }
        if (mnB != INF) {
            ans += mxB - mnB;
        }
        cout << ans << endl;
        return 0;
    }
    int mnG, mxG;
    for (char col = 'R'; ; col = 'B') {
        int nn = 0;
        forn(i, n) if (c[i] == 'G' || c[i] == col) {
            aa[nn] = a[i];
            cc[nn] = c[i];
            ++nn;
        }
        mnG = INF, mxG = -INF;
        int ind = 0;
        forn(i, nn) if (cc[i] == 'G') {
            if (mnG == INF) {
                mnG = mxG = aa[i];
                continue;
            }
            if (col == 'R') {
                fu[ind] = 3ll * (aa[i] - mxG);
                mx[ind] = 2ll * (aa[i] - mxG);
            }
            int dist = 0;
            for (int j = i - 1; ; --j) {
                dist = max(dist, aa[j + 1] - aa[j]);
                if (cc[j] == 'G') {
                    break;
                }
            }
            fu[ind] -= dist;
            ++ind;
            mxG = aa[i];
        }
        if (col == 'B') {
            break;
        }
    }
    forn(i, 300005) ans += min(fu[i], mx[i]);
    bool wr = false, wb = false;
    forn(i, n) {
        if (c[i] == 'R' && !wr) {
            wr = true;
            if (a[i] < mnG) ans += mnG - a[i];
        }
        if (c[i] == 'B' && !wb) {
            wb = true;
            if (a[i] < mnG) ans += mnG - a[i];
        }
    }

    wr = false, wb = false;
    for (int i = n - 1; i >= 0; --i) {
        if (c[i] == 'R' && !wr) {
            wr = true;
            if (a[i] > mxG) ans += a[i] - mxG;
        }
        if (c[i] == 'B' && !wb) {
            wb = true;
            if (a[i] > mxG) ans += a[i] - mxG;
        }
    }

    cout << ans << endl;
    return 0;
}