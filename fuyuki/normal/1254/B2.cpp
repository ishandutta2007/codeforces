#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
#define rnt re int
#define re register
#define LL inline ll
#define V inline void
#define ll long long int
#define FOR(i,a,b) for(rnt i=a;i<=b;i++)
const int N=1e6+1;
int n,tot,a[N];
ll sum,ans;
LL min(const ll&x,const ll&y){return x<y?x:y;}
V input(){scanf("%d",&n);FOR(i,1,n)scanf("%d",a+i),sum+=a[i];}
LL once(ll k){
    ll out=0,now=0;
    FOR(i,1,n)now+=a[i],now%=k,out+=min(now,k-now);
    return out;
}
V work(){
    if(sum<=1)return void(cout<<"-1");
    ans=1ll<<62;
    for(rnt i=2;1ll*i*i<=sum;i++)if(sum%i==0){
        ans=min(ans,once(i));
        while(sum%i==0)sum/=i;
    }
    if(sum^1)ans=min(ans,once(sum));
    cout<<ans;
}
int main(){
    input();
    work();
    return 0;
}