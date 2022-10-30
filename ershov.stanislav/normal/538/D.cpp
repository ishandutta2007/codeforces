#include <bits/stdc++.h>

#define mp make_pair
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back

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

const int INF = 1e9;
const ll lINF = 1e18;
const double EPS = 1e-12;

using namespace std;

int n;

char f[55][55];
char ans[120][120];

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf(" %s", f[i]);
    }
    for (int i = 0; i < 120; i++) {
        for (int j = 0; j < 120; j++) {
            ans[i][j] = 'x';
        }
    }
    ans[60][60] = 'o';
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (f[i][j] == '.') {
                for (int ii = 0; ii < n; ii++) {
                    for (int jj = 0; jj < n; jj++) {
                        if (f[ii][jj] == 'o') {
                            ans[60 + i - ii][60 + j - jj] = '.';
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (f[i][j] == 'x') {
                bool flag = false;
                for (int ii = 0; ii < n; ii++) {
                    for (int jj = 0; jj < n; jj++) {
                        if (f[ii][jj] == 'o' && ans[60 + i - ii][60 + j - jj] == 'x') {
                            flag = true;
                        }
                    }
                }
                if (!flag) {
                    printf("NO\n");
                    return 0;
                }
            }
        }
    }
    printf("YES\n");
    for (int i = 60 - n + 1; i < 60 + n; i++) {
        for (int j = 60 - n + 1; j < 60 + n; j++) {
            printf("%c", ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}