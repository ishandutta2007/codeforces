#include <ctime>
#include <cstdio>
#include <algorithm>
#include <ctime>
#include <iostream>
#include <queue>
#include <bitset>
#include <string>
#include <cstring>
#include <set>
#include <cmath>
#include <unordered_set>
using namespace std;
const int N = 200001;
int k;
struct node{
    int mx[1<<5], mn[1<<5];
    void build(int*a){
        for (int i = 0; i < (1 <<k);i ++)
        {
            mx[i] = 0;
            for (int j = 0;j < k; j ++)
                mx[i] += (((i >> j) & 1) * 2 - 1) * a[j];
            mn[i] = mx[i];
        }
    }
}f[N * 4];
int n;
int a[N][5];
void merge(node&a, node&b, node&c){
    for (int i = 0; i < (1 << k); i ++)
        a.mn[i] = min(b.mn[i], c.mn[i]), a.mx[i] = max(b.mx[i], c.mx[i]);
}
void build(int l, int r,int s){
    if (l == r){
        f[s].build(a[l]);
        return;
    }
    build(l, (l+r)/2, s + s);
    build((l+r)/2+1, r, s + s + 1);
    merge(f[s], f[s+s],f[s+s+1]);
}
void change(int l, int r, int s, int ll) {
    if (l == r) {
        f[s].build(a[0]);
        return;
    }
    if ((l+r)/2>=ll)
        change(l,(l+r)/2,s+s,ll);
    else
        change((l+r)/2+1,r,s+s+1, ll);
    merge(f[s],f[s+s],f[s+s+1]);
}
void search(int l, int r, int s, int ll, int rr) {
    if (r < ll || rr <l )return;
    if (ll <= l && r <= rr) {
        if (ll == l)
            f[0] = f[s];
        else
            merge(f[0],f[0],f[s]);
        return;
    }
    search(l,(l+r)/2,s+s,ll, rr);
    search((l+r)/2+1, r,s+s+1,ll, rr);
}
int main() {
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n ; i ++) {
        for (int j = 0; j < k ; j ++)
            scanf("%d", &a[i][j]);
    }
    build(1, n, 1);
    int q;
    scanf("%d", &q);
    while (q --) {
        int x;
        scanf("%d", &x);
        if (x == 1){
            int y;
            scanf("%d", &y);
            for (int i =0; i < k; i ++)
                scanf("%d", &a[0][i]);
            change(1, n , 1, y);
        } else {
            int l,r;
            scanf("%d %d", &l, &r);
            search(1, n,1, l, r);
            int ans = 0;
            for (int i = 0; i < (1 << k); i ++)
                ans = max(ans, f[0].mx[i] + f[0].mx[(1 << k) - 1 - i]);
            cout<<ans<<endl;
        }
    }
    return 0;
}