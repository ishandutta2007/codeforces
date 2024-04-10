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

char s[10][10];

int main()
{
#ifdef DEBUG
    freopen("text.in", "r", stdin);
#endif
    for (int i = 0; i < 8; i++) {
        scanf("%s", s[i]);
    }
    int mnw = INF;
    for (int c = 0; c < 8; c++) {
        for (int r = 0; r < 8; r++) {
            if (s[r][c] == 'B') {
                break;
            }
            if (s[r][c] == 'W') {
                mnw = min(mnw, r);
            }
        }
    }
    int mnb = INF;
    for (int c = 0; c < 8; c++) {
        for (int r = 7; r >= 0; r--) {
            if (s[r][c] == 'W') {
                break;
            }
            if (s[r][c] == 'B') {
                mnb = min(mnb, 7 - r);
            }
        }
    }
    if (mnw <= mnb) {
        printf("A\n");
    } else {
        printf("B\n");
    }
    return 0;
}