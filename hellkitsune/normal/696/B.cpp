#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int par[100000];
int sz[100000] = {}, dep[100000];

int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        scanf("%d", par + i);
        --par[i];
    }
    for (int i = n - 1; i >= 0; --i) {
        ++sz[i];
        if (i) sz[par[i]] += sz[i];
    }
    dep[0] = 1;
    for (int i = 1; i < n; ++i) {
        dep[i] = dep[par[i]] + 1;
    }
    REP(i, n) {
        int ans = n - sz[i] + 1 + dep[i];
        printf("%d.%d ", ans / 2, (ans % 2 == 0) ? 0 : 5);
    }
    printf("\n");
    return 0;
}