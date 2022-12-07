#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int a[100005];
int f[100005], g[100005];
int m;

int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    forn(i, n) {
        scanf("%d", a + i);
        --a[i];
    }
    m = 0;
    forn(i, n) if (a[i] == i) {
        g[m] = i;
        f[i] = m;
        ++m;
    }
    forn(i, n) if (a[i] != i) {
        if (a[a[i]] != a[i]) {
            cout << -1 << endl;
            return 0;
        }
        f[i] = f[a[i]];
    }
    printf("%d\n", m);
    forn(i, n) printf("%d ", f[i] + 1);
    printf("\n");
    forn(i, m) printf("%d ", g[i] + 1);
    printf("\n");
    return 0;
}