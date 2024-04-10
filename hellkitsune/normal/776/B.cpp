#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
bool pr[100005];

int main() {
    forn(i, 100005) {
        pr[i] = true;
    }
    pr[0] = pr[1] = false;
    forn(i, 1000) if (pr[i]) {
        for (int j = i * i; j < 100005; j += i) {
            pr[j] = false;
        }
    }
    scanf("%d", &n);
    if (n < 3) {
        puts("1");
        forn(i, n) {
            printf("1 ");
        }
        puts("");
        return 0;
    }
    puts("2");
    for (int i = 2; i <= n + 1; ++i) if (pr[i]) {
        printf("%d ", 1);
    } else {
        printf("%d ", 2);
    }
    puts("");
    return 0;
}