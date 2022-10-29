#include<bits/stdc++.h>
using namespace std;
long long n,a,b;
struct node{
    long long v,h;    
}d[1000000];
bool cmp(const node&a,const node&b){
    return a.h-a.v>b.h-b.v;
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>a>>b;
    long long all=0;
    for (int i=1;i<=n;i++)cin>>d[i].h>>d[i].v,all+=d[i].v;
    sort(d+1,d+n+1,cmp);
    for (int i=1;i<=min(b,n);i++){
        all+=max((long long)0,d[i].h-d[i].v);     
    }
    long long ans=all;
    long long u=1;
    while (a--)u*=2;
    for (int i=1;i<=min(b,n);i++){
        ans=max(ans,all-max((long long)0,d[i].h-d[i].v)+max((long long)0,d[i].h*u-d[i].v));
    }
    if (b)
    for (int i=b+1;i<=n;i++)
        ans=max(ans,all-max((long long)0,d[b].h-d[b].v)+max((long long)0,d[i].h*u-d[i].v));
    cout<<ans;
    return 0;
}