#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m, k;
int a[100];

int main() {
    scanf("%d%d%d", &n, &m, &k);
    --m;
    forn(i, n) scanf("%d", a + i);
    int mn = 12341234;
    forn(i, n) if (a[i] != 0 && a[i] <= k) {
        mn = min(mn, abs(i - m) * 10);
    }
    cout << mn << endl;
    return 0;
}