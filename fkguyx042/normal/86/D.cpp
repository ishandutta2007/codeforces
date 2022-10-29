#include <cstdio>  
#include <iostream>  
#include <algorithm>  
#include <cstring>  
#include <cmath>  
using namespace std;  
#define N 200100  
typedef long long ll;  
ll a[N], cnt[N*5], ans[N], res;  
int L, R;  
  
struct node {  
    int x, y, l, p;  
} q[N];  
bool cmp(const node &x, const node &y) {  
    if (x.l == y.l) return x.y < y.y;  
    return x.l < y.l;  
}  
void query(int x, int y, int flag) {  
    if (flag) {  
        for (int i=x; i<L; i++) {  
            res += ((cnt[a[i]]<<1)+1)*a[i];  
            cnt[a[i]]++;  
        }  
        for (int i=L; i<x; i++) {  
            cnt[a[i]]--;  
            res -= ((cnt[a[i]]<<1)+1)*a[i];  
        }  
        for (int i=y+1; i<=R; i++) {  
            cnt[a[i]]--;  
            res -= ((cnt[a[i]]<<1)+1)*a[i];  
        }  
        for (int i=R+1; i<=y; i++) {  
            res += ((cnt[a[i]]<<1)+1)*a[i];  
            cnt[a[i]]++;  
        }  
  
    } else {  
        for (int i=x; i<=y; i++) {  
            res += ((cnt[a[i]]<<1)+1)*a[i];  
            cnt[a[i]]++;  
        }  
    }  
    L = x, R = y;  
}  
int main() {  
    int n, t;  
  
    scanf("%d%d", &n, &t);  
    for (int i=1; i<=n; i++) scanf("%I64d", &a[i]);  
    int block_size = sqrt(n);  
  
    for (int i=0; i<t; i++) {  
        scanf("%d%d", &q[i].x, &q[i].y);  
        q[i].l = q[i].x / block_size;  
        q[i].p = i;  
    }  
  
    sort(q, q+t, cmp);  
  
  
    memset(cnt, 0, sizeof(cnt));  
  
    res = 0;  
    for (int i=0; i<t; i++) {  
        query(q[i].x, q[i].y, i);  
        ans[q[i].p] = res;  
    }  
  
    for (int i=0; i<t; i++) printf("%I64d\n", ans[i]);  
  
    return 0;  
}