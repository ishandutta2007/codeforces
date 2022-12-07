#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int a[300000];
int b[300000];

int main() {
    scanf("%d", &n);
    forn(i, n) scanf("%d", a + i), --a[i];
    int suf = n - 1;
    int ans = 1;
    printf("1");
    forn(i, n) {
        ++ans;
        b[a[i]] = 1;
        while (suf >= 0 && b[suf] == 1) {
            --ans;
            --suf;
        }
        printf(" %d", ans);
    }
    puts("");
    return 0;
}