#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, x[MN], y[MN], ans[MN], used[MN];

ll d(int i, int j) {
    return (x[j] - x[i])*(x[j] - x[i]) + (y[j] - y[i])*(y[j] - y[i]);
}

int main() {
    scanf("%lld", &n);

    for(int i = 0; i < n; i++) {
        scanf("%lld %lld", &x[i], &y[i]);
    }

    ll best = -1;
    ll f1, f2;

    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            if(d(i, j) > best) {
                best = d(i, j);
                f1 = i; f2 = j;
            }
        }
    }

    ans[0] = f1; ans[1] = f2;
    used[f1] = used[f2] = 1;

    for(int i = 2; i < n; i++) {
        best = -1;
        for(int j = 0; j < n; j++) {
            if(used[j]) continue;
            if(d(ans[i-1], j) > best) {
                best = d(ans[i-1], j);
                f1 = j;
            }
        }
        ans[i] = f1;
        used[f1] = 1;
    }

    for(int i = 0; i < n; i++)
        printf("%lld ", ans[i] + 1);
    return 0;
}