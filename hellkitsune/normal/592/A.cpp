#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

string s[8];

int main() {
    REP(i, 8) cin >> s[i];
    int bestA = 15, bestB = 15;
    REP(i, 8) REP(j, 8) if (s[i][j] == 'W') {
        bool ok = true;
        REP(k, i) if (s[k][j] != '.') ok = false;
        if (ok) bestA = min(bestA, i);
    } else if (s[i][j] == 'B') {
        bool ok = true;
        for (int k = i + 1; k < 8; ++k) if (s[k][j] != '.') ok = false;
        if (ok) bestB = min(bestB, 7 - i);
    }
    if (bestA <= bestB) {
        printf("A\n");
    } else {
        printf("B\n");
    }
    return 0;
}