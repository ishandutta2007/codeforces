#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 4e5+30;
struct node{
    int x, y, ans;
}a[maxn], tmp[maxn];
ll b[maxn];
int n, cnt, imax[maxn], id[maxn];
int m, V[maxn];
void update(int pos, int val){
    for(;pos<=cnt; pos+=pos&-pos){
        if(imax[pos] < val) imax[pos] = val;
        else break;
    }
}
int cal(int pos){
    int res = 0;
    for(;pos>0; pos-=pos&-pos)
        res = max(res, imax[pos]);
    return res;
}
void clr(int pos){
    for(;pos<=cnt; pos+=pos&-pos){
        if(imax[pos] == 0) break;
        imax[pos] = 0;
    }
}
bool cmp(int i, int j){
    return a[i].x < a[j].x;
}
void cdq(int l, int r){
    if(l == r) return;
    int mid = l+r>>1, L=l, R, k=0;
    cdq(l, mid);
    for(int i=mid+1; i<=r; ++i) id[i] = i;
    sort(id+mid+1, id+r+1, cmp);
    for(int i=mid+1; i<=r; ++i){
        int c = id[i];
        while(L<=mid && a[L].x < a[c].x){
            update(a[L].y, a[L].ans);++L;
        }
        a[c].ans = max(a[c].ans, cal(a[c].y-1)+1);
    }
    for(int i=l; i<=mid; ++i) clr(a[i].y);
    cdq(mid+1, r);
    L=l, R=mid+1;
    while(L<=mid && R<=r){
        if(a[L].x <= a[R].x) tmp[k++] = a[L++];
        else tmp[k++] = a[R++];
    }
    while(L<=mid) tmp[k++] = a[L++];
    while(R<=r) tmp[k++] = a[R++];
    for(int i=0; i<k; ++i) a[l+i] = tmp[i];
}
int main(){
    cnt = 0;
    scanf("%d",&m);
    for (int i=1;i<=m;i++){
        scanf("%d",&V[i]);
        int t=i-V[i]+1;
        if (t<=0) continue;
        ++n; a[n].x=V[i]; a[n].y=t;
    }
    if (!n){puts("0");return 0;}
    for(int i=1; i<=n; ++i){
        a[i].ans = 1;
        b[++cnt] = 1ll*(n+1)*a[i].y+i;
    }
    sort(b+1, b+1+cnt);
    cnt = unique(b+1, b+1+cnt)-b-1;
    for(int i=1; i<=n; ++i) a[i].y = lower_bound(b+1, b+1+cnt, 1ll*(n+1)*a[i].y+i)-b;
    cdq(1, n);
    int ans = 0;
    for(int i=1; i<=n; ++i) ans = max(ans, a[i].ans);
    printf("%d\n",ans);
    return 0;
}