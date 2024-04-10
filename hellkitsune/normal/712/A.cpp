#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int a[100000], b[100000];

int main() {
    scanf("%d", &n);
    forn(i, n) scanf("%d", a + i);
    b[n - 1] = a[n - 1];
    forn(i, n - 1) {
        b[i] = a[i] + a[i + 1];
    }
    forn(i, n) {
        printf("%d ", b[i]);
    }
    printf("\n");
    return 0;
}