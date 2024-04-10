#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int a[2][2];
int z = 0, o = 0;
char ans[1000005];

int main() {
    forn(i, 2) forn(j, 2) scanf("%d", a[i] + j);
    while ((LL)z * (z - 1) / 2 < a[0][0]) ++z;
    while ((LL)o * (o - 1) / 2 < a[1][1]) ++o;
    if ((LL)z * (z - 1) / 2 != a[0][0] || (LL)o * (o - 1) / 2 != a[1][1]) {
        cout << "Impossible" << endl;
        return 0;
    }
    if (a[0][0] == 0 && a[0][1] == 0 && a[1][0] == 0 && a[1][1] == 0) {
        cout << "0" << endl;
        return 0;
    }
    if (o == 0 && (a[0][1] || a[1][0])) {
        o = 1;
    }
    if (z == 0 && (a[0][1] || a[1][0])) {
        z = 1;
    }
    if (a[0][1] + a[1][0] != (LL)o * z) {
        cout << "Impossible" << endl;
        return 0;
    }
    int len = o + z;
    ans[len] = '\0';
    forn(i, z) ans[i] = '0';
    forn(i, o) ans[z + i] = '1';
    LL need = (LL)z * o - a[0][1];
    for (int i = z - 1; i >= 0; --i) {
        int cur = min(need, (LL)o);
        swap(ans[i], ans[i + cur]);
        need -= cur;
        if (need == 0) break;
    }
    printf("%s\n", ans);
    return 0;
}