#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

LL d[50][2] = {};
LL ss, xx;
int s[50], x[50];

int main() {
    //freopen("input.txt", "r", stdin);
    cin >> ss >> xx;
    bool eq = ss == xx;
    REP(i, 50) {
        s[i] = ss & 1;
        ss >>= 1;
        x[i] = xx & 1;
        xx >>= 1;
    }
    d[0][0] = 1;
    REP(i, 49) REP(j, 2) {
        REP(a, 2) REP(b, 2) {
            if ((a + b + j) % 2 != s[i]) continue;
            if ((a ^ b) != x[i]) continue;
            d[i + 1][(a + b + j) / 2] += d[i][j];
        }
    }
    if (eq) d[49][0] -= 2;
    cout << d[49][0] << endl;
    return 0;
}