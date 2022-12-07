#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define pb push_back
#define mp make_pair
typedef long long LL;
typedef pair<int, int> PII;

int n;
LL t;
LL a[200000], b[200000];
int x[200000];
int need[200005];

int main() {
    scanf("%d%I64d", &n, &t);
    forn(i, n) scanf("%I64d", a + i);
    forn(i, n) scanf("%d", x + i), --x[i];
    forn(i, n) if (x[i] < i) {
        cout << "No" << endl;
        return 0;
    }
    forn(i, n) if (x[i] > i) {
        need[i + 1] += 1;
        need[x[i] + 1] -= 1;
    }
    forn(i, n) {
        need[i + 1] += need[i];
    }
    forn(i, n) b[i] = a[i] + t;
    for (int i = 1; i < n; ++i) if (need[i]) {
        b[i - 1] = a[i] + t;
    }
    forn(i, n - 1) {
        b[i + 1] = max(b[i + 1], b[i] + 1);
    }
    forn(i, n) if (x[i] != n - 1) {
        int ind = x[i] + 1;
        if (b[ind - 1] >= a[ind] + t) {
            cout << "No" << endl;
            return 0;
        }
    }
    printf("Yes\n");
    forn(i, n) printf("%I64d ", b[i]);
    puts("");
    return 0;
}