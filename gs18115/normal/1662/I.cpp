#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
const int inf=1e9+7;
const ll INF=1e18;
const int N=2e5+5;
int n,m,x[N];
ll a[N],ans,cur;
ll solve(int l,int r,int d){
    ll s=0,ret=0;
    for(int i=l,j=l-1;i<=r;i++){
        while(j+1<=r&&(j+1-i)*200<d){
            j++; s+=a[j];
        }
        ret=max(ret,s);
        s-=a[i];
    }
    return ret;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++) cin>>x[i];
    sort(x+1,x+1+m);
    for(int i=1;i<=n;i++) if((i-1)*100<x[1]) cur+=a[i];
    ans=cur; cur=0;
    for(int i=1;i<=n;i++) if((i-1)*100>x[m]) cur+=a[i];
    ans=max(ans,cur);
    for(int i=1;i<m;i++){
        int l=max(1,(x[i]+100)/100+1),r=min(n,(x[i+1]-1)/100+1);
        if(l<=r) ans=max(ans,solve(l,r,x[i+1]-x[i]));
    }
    cout<<ans;
    return 0;
}