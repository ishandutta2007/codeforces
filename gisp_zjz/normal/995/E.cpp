#include<bits/stdc++.h>
#define F first
#define S second

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
const ll n=20;
ll u,v,p,d,ans[200],s,t,N,f,res,cc;
pi a[1<<(n+1)];

ll pow_(ll x,ll y){
    ll rt=1;
    for (ll i=0;i<30;i++) {
        if (y&(1<<i)) rt=rt*x%p;
        x=x*x%p;
    }
    return rt;
}

void dfs(ll x,ll y,ll z){
    if (z==n) a[y+f*N]={x,y+f*N};
    else {
        dfs(pow_((x+1)%p,p-2),y|(1<<z),z+1);
        dfs(pow_((x+p-1)%p,p-2),y,z+1);
    }
}

int main(){
    cin >> u >> v >> p;
    N=1<<n;
    f=0; dfs(u,0,0);
    f=1; dfs(v,0,0);
    sort(a,a+N*2);
    for (int i=0;i<N*2-1;i++) if (abs(a[i].F-a[i+1].F)<=100&&a[i].S<N&&a[i+1].S>=N) {
        s=a[i].S;
        t=a[i+1].S-N;
        res=a[i+1].F-a[i].F;
        break;
    }
    cc=n*4+abs(res);
    for (int i=0;i<n;i++){
        ans[i*2]=(s&(1<<i))?1:2;
        ans[i*2+1]=3;
    }
    for (int i=n*2;i<cc-n*2;i++) ans[i]=(res>0)?1:2;
    for (int i=0;i<n;i++){
        ans[cc-1-i*2]=(t&(1<<i))?2:1;
        ans[cc-2-i*2]=3;
    }
    cout << cc << endl;
    for (ll i=0;i<cc;i++) printf("%d ",ans[i]); printf("\n");
    for (int i=0;i<cc;i++) {
        if (ans[i]==1) u=(u+1)%p; else if (ans[i]==2) u=(u+p-1)%p;
        else u=pow_(u,p-2);
    }
    //cout << u << ' ' << v << endl;
    return 0;
}