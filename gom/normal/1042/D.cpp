#include <bits/stdc++.h>
#define N 200005
using namespace std;
typedef long long ll;
int n,m,tree[4*2*N];
ll t,a[N],s[N],tmp[N*2],ans;
int to(ll x)
{
    return (lower_bound(tmp,tmp+m,x)-tmp)+1;
}
void update(int nd,int l,int r,int x)
{
    tree[nd]++;
    if(l==r) return;
    int m=(l+r)/2;
    if(x<=m) update(nd*2,l,m,x);
    else update(nd*2+1,m+1,r,x);
}
int query(int nd,int l,int r,int x)
{
    if(l==r) return tree[nd];
    int m=(l+r)/2;
    if(x<=m) return tree[nd*2+1]+query(nd*2,l,m,x);
    else return query(nd*2+1,m+1,r,x);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>t;
    tmp[m++]=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s[i]=s[i-1]+a[i];
        tmp[m++]=s[i];
        tmp[m++]=s[i]-t+1;
    }
    sort(tmp,tmp+m);
    m=unique(tmp,tmp+m)-tmp;
    for(int i=1;i<=n;i++){
        update(1,1,m,to(s[i-1]));
        ans+=(ll)query(1,1,m,to(s[i]-t+1));
    }
    cout<<ans;
    return 0;
}