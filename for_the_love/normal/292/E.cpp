#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
struct Tnode{
    int s, sign;
} t[800005];

int a[100005], b[100005], n, m, x[100005], y[100005], k[100005], p, i, po, tmp;
void down(int x){
    t[x].s = t[x].sign;
    t[x + x].sign = t[x + x + 1].sign = t[x].sign;
    t[x].sign = 0;
}
void Insert(int x, int l, int r, int a, int b, int c){
    if (t[x].sign) down(x);
    if (l >= a && r <= b){
        t[x].sign = c;
        return;
    }
    int mid = (l + r) / 2;
    if (b > mid) Insert(x + x + 1, mid + 1, r, a, b, c);
    if (a <= mid) Insert(x + x, l, mid, a, b, c);
}
int get(int x, int l, int r, int a){
    if (t[x].sign) down(x);
    if (l == a && r == a) return t[x].s;
    int mid = (l + r) / 2;
    if (a > mid) return get(x + x + 1, mid + 1, r, a); else return get(x + x, l, mid, a);
}
int main(){
    scanf("%d%d", &n, &m);
    for (i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (i = 1; i <= n; i++) scanf("%d", &b[i]);
    for (i = 1; i <= m; i++){
        scanf("%d", &p);
        if (p == 1){
            scanf("%d%d%d", &x[i], &y[i], &k[i]);
            Insert(1, 1, n, y[i], y[i] + k[i] - 1, i);
        }else{
            scanf("%d", &po);
            tmp = get(1, 1, n, po);
            if (!tmp) printf("%d\n", b[po]); else printf("%d\n", a[x[tmp] + po - y[tmp]]);
        }
    }

}