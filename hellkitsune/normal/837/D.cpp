#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const int INF = int(1e9);

int n, k;
int a[200], b[200];
int d[201][5001];

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    forn(i, n) {
        LL x;
        cin >> x;
        while (x % 2 == 0) {
            ++a[i];
            x /= 2;
        }
        while (x % 5 == 0) {
            ++b[i];
            x /= 5;
        }
    }
    forn(i, 201) forn(j, 5001) d[i][j] = -INF;
    d[0][0] = 0;
    forn(_, n) {
        int w = b[_];
        int value = a[_];
        int upto = 25 * _ + 1;
        for (int i = min(_, k - 1); i >= 0; --i) {
            forn(j, upto) {
                d[i + 1][j + w] = max(d[i + 1][j + w], d[i][j] + value);
            }
        }
    }
    int ans = 0;
    forn(i, 5001) {
        ans = max(ans, min(d[k][i], i));
    }
    cout << ans << endl;
    return 0;
}