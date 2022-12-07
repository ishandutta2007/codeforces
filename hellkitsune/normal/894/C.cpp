#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int a[1000];

int gcd(int a, int b) {
    while (b) a %= b, swap(a, b);
    return a;
}

int main() {
    scanf("%d", &n);
    forn(i, n) scanf("%d", a + i);
    int g = 0;
    forn(i, n) g = gcd(g, a[i]);
    if (a[0] != g) {
        cout << -1 << endl;
        return 0;
    }
    printf("%d\n", 2 * n);
    forn(i, n) printf("%d %d ", g, a[i]);
    printf("\n");
    return 0;
}