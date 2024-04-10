#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MN 1001000

ll n, p[MN], a[MN], b[MN], m, c[MN];

map<int, int> av[4];

int main() {
    scanf("%lld", &n);
    for(int i = 0; i < n; i++) {
        scanf("%lld", &p[i]);
    }
    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        av[a[i]][p[i]] = i;
    }
    for(int i = 0; i < n; i++) {
        scanf("%lld", &b[i]);
        av[b[i]][p[i]] = i;
    }
    scanf("%lld", &m);
    for(int i = 0; i < m; i++) {
        scanf("%lld", &c[i]);
        if (av[c[i]].empty()) printf("-1 ");
        else {
            auto [x, j] = *av[c[i]].begin();
            av[a[j]].erase(x);
            av[b[j]].erase(x);
            printf("%d ", x);
        }
    }
    return 0;
}