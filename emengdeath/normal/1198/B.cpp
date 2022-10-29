#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 1e6;
int n, k;
int a[N], f[N];
void down(int l, int r, int s) {
    if (f[s]) {
        if (l != r) {
            f[s + s] = max(f[s+ s], f[s]);
            f[s + s + 1] = max(f[s + s + 1], f[s]);
            f[s] = 0;
        }
    }
}
void change(int l, int r, int s,int  ll, int v){
    down(l, r, s);
    if (l == r) {
        f[s] = 0;
        a[l] = v;
        return;
    }
    if ((l+ r) / 2 >= ll)
        change(l, (l + r) / 2, s + s, ll, v);
    else
        change((l + r) / 2 + 1, r, s + s + 1, ll, v);
}
void work(int l, int r, int s) {
    down(l ,r, s);
    if (l == r) {
        a[l] = max(a[l], f[s]);
        return;
    }
    work(l, (l + r) / 2 , s + s);
    work((l + r) / 2 + 1, r, s + s+ 1);
}
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n ; i ++)
        scanf("%d", &a[i]);
    scanf("%d", &k);
    while (k --) {
        int x, y, z;
        scanf("%d %d", &x, &y);
        if (x == 2) {
            down(1, n, 1);
            f[1] = y;
        } else {
            scanf("%d", &z);
            change(1, n, 1, y, z);
        }
    }
    work(1, n , 1);
    for (int i = 1; i < n ; i ++)
        printf("%d ", a[i]);
    printf("%d", a[n]);
    return 0;
}