#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int a;

int main() {
    scanf("%d", &a);
    int n = 1;
    if (a > 1) {
        n = 2 * (a - 1);
    }
    printf("%d %d\n", n, 2);
    printf("1 2\n");
    return 0;
}