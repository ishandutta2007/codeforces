#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 300300;
const int Q = 1000100;

using namespace std;

int n;
int m;
int a[N];
int b[N];
int f[Q];
int t[4 * Q];
int lz[4 * Q];

void push(int x)
{
        if(lz[x]){
                t[x * 2] += lz[x];
                t[x * 2 + 1] += lz[x];
                lz[x * 2] += lz[x];
                lz[x * 2 + 1] += lz[x];
                lz[x] = 0;
        }
}

void build(int x, int l, int r)
{
        if(l == r){
                t[x] = f[l];
                return;
        }
        int m = (l + r) / 2;
        build(x * 2, l, m);
        build(x * 2 + 1, m + 1, r);
        t[x] = max(t[x * 2], t[x * 2 + 1]);
}

void upd(int x, int l, int r, int tr, int y)
{
        if(l > tr){
                return;
        }
        if(r == tr){
                t[x] += y;
                lz[x] += y;
                return;
        }
        push(x);
        int m = (l + r) / 2;
        upd(x * 2, l, m, min(m, tr), y);
        upd(x * 2 + 1, m + 1, r, tr, y);
        t[x] = max(t[x * 2], t[x * 2 + 1]);
}

int get(int x, int l, int r)
{
        if(l == r){
                return l;
        }
        push(x);
        int m = (l + r) / 2;
        if(t[x * 2 + 1] > 0){
                return get(x * 2 + 1, m + 1, r);
        } else{
                return get(x * 2, l, m);
        }
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        scanf("%d %d", &n, &m);
        for(int i = 1; i <= n; i++){
                scanf("%d", &a[i]);
                f[a[i]] += 1;
        }
        for(int i = 1; i <= m; i++){
                scanf("%d", &b[i]);
                f[b[i]] -= 1;
        }
        for(int i = Q - 2; i >= 0; i--){
                f[i] += f[i + 1];
        }
        int last = 1000000;
        build(1, 1, last);
        int q;
        scanf("%d", &q);
        for(int i = 1; i <= q; i++){
                int t, x, y;
                scanf("%d %d %d", &t, &x, &y);
                if(t == 1){
                        upd(1, 1, last, a[x], -1);
                        a[x] = y;
                        upd(1, 1, last, a[x], 1);
                } else{
                        upd(1, 1, last, b[x], 1);
                        b[x] = y;
                        upd(1, 1, last, b[x], -1);
                }
                if(::t[1] <= 0){
                        printf("-1\n");
                } else{
                        printf("%d\n", get(1, 1, last));
                }
        }
}