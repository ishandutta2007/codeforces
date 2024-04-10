#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int t[100005], d[100005];
int a, b;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", t + i);
    }
    t[0] = -12345;
    d[0] = 0;
    a = 1, b = 1;
    for (int i = 1; i <= n; ++i) {
        while (t[i] - t[a] >= 90) {
            ++a;
        }
        while (t[i] - t[b] >= 1440) {
            ++b;
        }
        d[i] = d[i - 1] + 20;
        d[i] = min(d[i], d[a - 1] + 50);
        d[i] = min(d[i], d[b - 1] + 120);
    }
    forn(i, n) {
        printf("%d\n", d[i + 1] - d[i]);
    }
    return 0;
}