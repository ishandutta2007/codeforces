#include <bits/stdc++.h>

#define MN 500100
#define LG 20

using namespace std;
typedef long long ll;

ll N, a[MN], rmq[MN][LG], r2[MN][LG], t;

void build() {
    for(int i = 0; i < N; i++)
        rmq[i][0] = r2[i][0] = a[i];

    for(int j = 1; (1 << j) <= N; j++)
        for(int i = 0; i + (1 << j) <= N; i++) {
            rmq[i][j] = min(rmq[i][j-1], rmq[i + (1 << (j-1))][j-1]);
            r2[i][j]  = max(r2[i][j-1],   r2[i + (1 << (j-1))][j-1]);
        }
}

ll query(int a, int b, int op) {
    if(a > b) swap(a,b);
    int lg = __builtin_clz(1) - __builtin_clz(b - a + 1);
    if(op == 0) return min(rmq[a][lg], rmq[b -(1 << lg)+1][lg]);
    else return max(r2[a][lg], r2[b -(1 << lg)+1][lg]);
}

int main() {
    scanf("%lld", &t);
    st:
    scanf("%lld", &N);

    for(int i = 0; i < N; i++) {
        scanf("%lld", &a[i]);
    }
    build();

    for(int x = 0; x < N; x++) {
        int maxi = query(0, x, 1);

        int l1, l2, r1, r2;

        {
            int l = x+1, r = N, m;
            while(l < r) {
                m = (l + r) / 2;
                if(query(x+1, m, 0) > maxi) l = m + 1;
                else r = m;
            }
            l1 = l;
        } {
            int l = x+1, r = N, m;
            while(l < r) {
                m = (l + r) / 2;
                if(query(x+1, m, 0) >= maxi) l = m + 1;
                else r = m;
            }
            r1 = l;
        } {
            int l = x+1, r = N, m;
            while(l < r) {
                m = (l + r) / 2;
                if(query(m, N-1, 1) > maxi) l = m + 1;
                else r = m;
            }
            l2 = l;
        } {
            int l = x+1, r = N, m;
            while(l < r) {
                m = (l + r) / 2;
                if(query(m, N-1, 1) >= maxi) l = m + 1;
                else r = m;
            }
            r2 = l - 1;
        }

        if(l1 >= r1 || l2 > r2 || r1 < l2 || l1 >= r2) continue;
        puts("YES");
        int y = max(l1+1, l2) - (x+1);
        printf("%d %d %lld\n", x + 1, y, N-x-y-1);
        goto nxt;
    }

    puts("NO");
    nxt:;
    if(--t) goto st;
    return 0;
}