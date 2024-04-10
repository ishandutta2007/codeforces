#include <bits/stdc++.h>

using namespace std;

const int maxn=1e6; 
int n,cnt,c[maxn+5],f[maxn+5]; 
struct node {
    int x,y,id;
} a[maxn+5]; 
int lb(int x) {
    return x&(-x); 
}
void add(int x,int d) {
    for (int i=x;i<maxn;i+=lb(i)) c[i]=max(c[i],d); 
}
void clr(int x) {
    for (int i=x;i<maxn;i+=lb(i)) c[i]=0; 
}
int sum(int x) {
    int ret=0; 
    for (int i=x;i;i-=lb(i)) ret=max(ret,c[i]);
    return ret;  
}
bool cmpx(node x,node y) {
    return x.x<y.x; 
}
bool cmpid(node x,node y) {
    return x.id<y.id; 
}
int ans; 
void solve(int l,int r) {
    //cout<<l<<' '<<r<<'\n'; 
    if (l==r) {
        ans=max(ans,f[l]);
        return ; 
    }
    int mid=(l+r)>>1; 
    solve(l,mid);
    sort(a+l,a+mid+1,cmpx);
    sort(a+mid+1,a+r+1,cmpx);
    int pos=l;
    for (int i=mid+1;i<=r;i++) {
        while (a[pos].x<a[i].x&&pos<=mid) {
            add(a[pos].y,f[a[pos].id]);
           // cout<<a[pos].y<<' '<<f[a[pos].id]<<'\n'; 
            pos++; 
        }
        f[a[i].id]=max(f[a[i].id],sum(a[i].y)+1);
    }
    sort(a+mid+1,a+r+1,cmpid);
    for (int i=l;i<pos;i++) clr(a[i].y);
    solve(mid+1,r); 
}
int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;i++) {
        int t; 
       scanf("%d",&t); 
       if (i-t<0) continue ;
       a[++cnt].x=t,a[cnt].y=i-t+1;  
       a[cnt].id=cnt; 
    }
    if (cnt==0) {
        puts("0");
        return 0; 
    }
    for (int i=1;i<=cnt;i++) f[i]=1; 
    solve(1,cnt);
    for (int i=1;i<=cnt;i++) {
        ans=max(ans,f[i]); 
      //  cout<<f[i]<<'\n'; 
    }
    cout<<ans<<'\n'; 
    return 0;
}