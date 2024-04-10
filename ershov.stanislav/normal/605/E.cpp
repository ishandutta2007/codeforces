#include <bits/stdc++.h>

#define mp make_pair
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back

#define all(s) (s).begin(), (s).end()
#define sz(s) ((int) ((s).size()))

typedef long long ll;
typedef long double ld;

const int INF = (int) 1e9 + 100;
const ll lINF = 1e18;
const double EPS = 1e-12;

#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

using namespace std;

const int maxn = 1100;
int n;
ld a[maxn][maxn];
ld curexp[maxn];
ld lft[maxn];
int used[maxn];

int main() {
#ifdef DEBUG
    freopen("text.in", "r", stdin);
#endif
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int c;
            scanf("%d", &c);
            a[i][j] = (ld) c / 100;
        }
    }
    for (int i = 0; i < n - 1; i++) {
        lft[i] = 1;
        curexp[i] = 1;
    }
    {
        used[n - 1] = 1;
        for (int i = 0; i < n - 1; i++) {
            lft[i] *= (1 - a[i][n - 1]);
        }
    }
    for (int i = 0; i < n - 1; i++) {
        int mxi = -1;
        for (int j = 0; j < n; j++) {
            if (used[j] == 1) {
                continue;
            }
            if (lft[j] > 1 - EPS) {
                continue;
            }
            //cout << "j: " << j << ' ' << (curexp[j] / (1 - lft[j])) << endl;
            if (mxi == -1 || (curexp[j] / (1 - lft[j])) < (curexp[mxi] / (1 - lft[mxi]))) {
                mxi = j;
            }
        }
        //cout << mxi << endl;
        used[mxi] = 1;
        curexp[mxi] = curexp[mxi] / (1 - lft[mxi]);
        for (int j = 0; j < n; j++) {
            if (used[j] == 1) {
                continue;
            }
            curexp[j] += lft[j] * a[j][mxi] * curexp[mxi];
            lft[j] *= (1 - a[j][mxi]);
        }
    }
    printf("%.18f\n", (double) curexp[0]);
    return 0;
}