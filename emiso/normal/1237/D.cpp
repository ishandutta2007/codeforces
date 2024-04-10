#include <bits/stdc++.h>

#define MN 400100
#define LG 20

using namespace std;
typedef long long ll;

ll n, N, a[MN], rmq[MN][LG], x, y, q, ans[MN];

void build() {
    for(int i = 0; i < N; i++)
        rmq[i][0] = a[i];

    for(int j = 1; (1 << j) < N; j++)
        for(int i = 0; i + (1 << j) <= N; i++) {
            rmq[i][j] = min(rmq[i][j-1], rmq[i + (1 << (j-1))][j-1]);
        }
}

ll query(int a, int b) {
    if(a > b) swap(a,b);
    int lg = __builtin_clz(1) - __builtin_clz(b - a + 1);

    return min(rmq[a][lg], rmq[b -(1 << lg)+1][lg]);
}

int main() {
    scanf("%lld", &n);
    N = 4 * n;
    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        a[i + n] = a[i + 2*n] = a[i + 3*n] = a[i];
    }
    build();

    {
        ll maxi = 0;
        for(int i = n; i < 4*n; i++) {
            maxi = max(maxi, a[i]);
            if(a[i] * 2 < maxi) break;
            ans[n]++;
        }
        if(ans[n] > 2 * n) {
            for(int i = 0; i < n; i++)
                printf("-1 ");
            return 0;
        } else ans[0] = ans[n];
    }

    for(int i = n-1; i > 0; i--) {
        if(a[i] < a[i+1]) ans[i] = ans[i+1] + 1;
        else {
            int l = i, r = 4*n-1, m;
            while(l < r) {
                m = (l + r + 1) / 2;
                if(query(i, m) * 2 < a[i]) r = m - 1;
                else l = m;
            }
            ans[i] = min(ans[i+1] + 1, l - i + 1LL);
        }
    }

    for(int i = 0; i < n; i++)
        printf("%lld ", ans[i]);
    return 0;
}