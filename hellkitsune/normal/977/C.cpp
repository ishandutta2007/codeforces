#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, k;
int a[200005];

int main() {
    scanf("%d%d", &n, &k);
    forn(i, n) scanf("%d", a + i);
    sort(a, a + n);
    if (k == 0) {
        if (a[0] == 1) {
            cout << -1 << endl;
        } else {
            cout << 1 << endl;
        }
        return 0;
    }
    if (k == n) {
        cout << a[n - 1] << endl;
        return 0;
    }
    if (a[k - 1] != a[k]) {
        cout << a[k - 1] << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}