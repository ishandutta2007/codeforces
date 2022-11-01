#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, m, a[2020][2020], c[2020], imp, ans = 0;

int main() {
    scanf("%lld %lld", &n, &m);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf("%1d", &a[i][j]);
            if(a[i][j] == 1) c[j]++;
        }
    }

    for(int i = 0; i < n; i++) {
        imp = 0;
        for(int j = 0; j < m; j++) {
            if(a[i][j] == 1 && c[j] == 1) imp++;
        }
        if(imp == 0) ans = 1;
    }

    printf("%s\n", ans ? "YES" : "NO");
    return 0;
}