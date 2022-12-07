#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
char c;
int from, to;
int m[400], f[400];

int main() {
    scanf("%d", &n);
    REP(i, n) {
        scanf(" %c%d%d", &c, &from, &to);
        if (c == 'M') {
            for (int i = from; i <= to; ++i) {
                ++m[i];
            }
        } else {
            for (int i = from; i <= to; ++i) {
                ++f[i];
            }
        }
    }
    int mx = 0;
    REP(i, 400) mx = max(mx, min(m[i], f[i]));
    cout << 2 * mx << endl;
    return 0;
}