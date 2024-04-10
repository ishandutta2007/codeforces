#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+3;
ll L,R,n;
int a[maxn];
bool intersect(ll a,ll b,ll c,ll d){
    return max(a,c)<=min(b,d);
}
void solve(ll l,ll r,int x,int y){
    //cout<<l<<' '<<r<<' '<<x<<' '<<y<<endl;
    if (x==y){
        if (intersect(l,r,L,R)) printf("%d ",x);
        return;
    }
    if (x<y){
        int len=(y-x-1)*2;
        if (intersect(l,l+len,L,R)){
            for (int i=0;i<=len;i+=2) a[i]=x;
            int tmp=x; for (int i=1;i<=len-1;i+=2) a[i]=++tmp;
            for (ll i=max(l,L);i<=min(l+len,R);i++) printf("%d ",a[i-l]);
        }
        solve(l+len+1,r-1,y,x+1);
        if (intersect(r,r,L,R)) printf("%d ",x);
    } else {
        int len=(x-y-1)*2;
        if (intersect(l,l,L,R)) printf("%d ",x);
        for (ll j=y;j<x;j++){
            len=(x-j)*2;
            if (intersect(l+1,l+len,L,R)){
                int tmp=j;
                for (int i=1;i<=len;i+=2) a[i]=j;
                for (int i=2;i<=len;i+=2) a[i]=++tmp;
                for (ll i=max(l+1,L);i<=min(l+len,R);i++) printf("%d ",a[i-l]);
            }
            l+=len;
        }
    }
}
int main(){
    int _; scanf("%d",&_);
    while (_--){
        scanf("%lld%lld%lld",&n,&L,&R);
        solve(1,n*(n-1)+1,1,n); puts("");
    }
}