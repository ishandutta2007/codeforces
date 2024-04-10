#include <bits/stdc++.h>

#define MN 200100
#define LG 20

using namespace std;
typedef long long ll;

ll N, a[MN], roq[MN][LG], ans;
map<int, int> last;

void build() {
    for(int i=0; i<N; i++)
        roq[i][0] = a[i];

    for(int j=1; (1 << j) <= N; j++)
        for(int i=0; i + (1 << j) <= N; i++) {
            roq[i][j] = (roq[i][j-1] | roq[i + (1 << (j-1))][j-1]);
        }
}

ll query(int a, int b) {
    if(a > b) swap(a,b);
    int lg = __builtin_clz(1) - __builtin_clz(b - a + 1);
    return (roq[a][lg] | roq[b -(1 << lg)+1][lg]);
}

int main() {
    scanf("%lld", &N);
    ans = N * (N + 1) / 2;

    for(int i = 0; i < N; i++) {
        scanf("%lld", &a[i]);
        last[a[i]] = -1;
    }

    build();

    for(ll i = 0; i < N; i++) {
        ll lb, up;

        ll l = last[a[i]] + 1, r = i;
        while(l < r) {
            ll m = (l + r) >> 1;
            if(query(m, i) == a[i])
                r = m;
            else l = m + 1;
        }
        lb = l;

        l = i, r = N - 1;
        while(l < r) {
            ll m = (l + r + 1) >> 1;
            if(query(i, m) == a[i])
                l = m;
            else r = m - 1;
        }
        up = l;

        ans -= (i - lb + 1) * (up - i + 1);
        last[a[i]] = i;
    }

    printf("%lld\n", ans);
    return 0;
}