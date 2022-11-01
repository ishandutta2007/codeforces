#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MN 1001000

ll t = 1, n, k, ans, a[505][505];
//char s[MN]; string str;

int main() {
    scanf("%lld", &t);
    st: ans = 0;
    scanf("%lld %lld", &n, &k);

    ans = 1;
    int d[2] = {1, 2};

    for(int i = 0; ans && i < n; i++) {
        for (int j = 0; ans && j < k; j++) {
            a[i][j] = d[i%2];
            d[i%2] += 2;
            if (a[i][j] > n*k) ans = 0;
        }
    }
    
    if (ans) {
        puts("YES");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++)
                printf("%lld ", a[i][j]);
            puts("");
        }
    } else puts("NO");

    if(--t) goto st;
    return 0;
}