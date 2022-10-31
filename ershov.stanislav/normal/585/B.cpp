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

const int INF = 1e9;
const ll lINF = 1e18;
const double EPS = 1e-12;

#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

using namespace std;

const int N = 4400;
int n, k;
char s[3][N];
int win[3][N];

int main()
{
#ifdef DEBUG
    freopen("text.in", "r", stdin);
#endif
    int t;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d%d", &n, &k);
        int rowstart = -1;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < n * 3; j++) {
                s[i][j] = '.';
            }
        }
        for (int i = 0; i < 3; i++) {
            scanf(" %s", s[i] + 2);
            s[i][2 + n] = '.';
            if (s[i][2] == 's') {
                rowstart = i;
                s[i][2] = '.';
            }
        }
        for (int j = 0; j < 3; j++) {
            if (s[j][(n - 1) * 3] == '.') {
                win[j][(n - 1) * 3] = 1;
            }
        }
        for (int r = n - 2; r >= 0; r--) {
            for (int j = 0; j < 3; j++) {
                if (s[j][r * 3] == '.' && s[j][r * 3 + 1] == '.' && s[j][r * 3 + 2] == '.' && s[j][r * 3 + 3] == '.') {
                    if ((win[j][(r + 1) * 3]) || (j > 0 && win[j - 1][(r + 1) * 3]) || (j < 2 && win[j + 1][(r + 1) * 3])) {
                        win[j][r * 3] = 1;
                    } else {
                        win[j][r * 3] = 0;
                    }
                } else {
                    win[j][r * 3] = 0;
                }
            }
        }
        if (win[rowstart][0]) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}