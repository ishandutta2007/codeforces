#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int array_size = 2.2e5;
const int val_size = 1.1e6;
int n,q,B,a[array_size],cnt[val_size]; ll sum;
struct Query
{
    int ql,qr,id,in; ll ans;
    Query(int _ql=1,int _qr=1,int _id=0)
    { ql=_ql,qr=_qr,id=_id,in=(_ql-1)/B+1,ans=0; }
    bool operator <(const Query&a) const
    { return in^a.in?in<a.in:(in&1)?qr<a.qr:qr>a.qr; } 
}Q[array_size];
void add(int val)
{
    sum-=1ll*val*cnt[val]*cnt[val];
    ++cnt[val];
    sum+=1ll*val*cnt[val]*cnt[val];
}
void del(int val)
{
    sum-=1ll*val*cnt[val]*cnt[val];
    --cnt[val];
    sum+=1ll*val*cnt[val]*cnt[val];
}
signed main()
{
    scanf("%d %d",&n,&q); B=pow(n,0.6);
    for(int i=1;i<=n;++i) scanf("%d",a+i);
    for(int i=1,x,y;i<=q;++i)
    {
        scanf("%d %d",&x,&y);
        Q[i]=Query(x,y,i);
    }
    sort(Q+1,Q+1+q);
    int l=1,r=0;
    for(int i=1;i<=q;++i)
    {
        int x=Q[i].ql,y=Q[i].qr;
        while(l>x) add(a[--l]);
        while(r<y) add(a[++r]);
        while(l<x) del(a[l++]);
        while(r>y) del(a[r--]);
        Q[i].ans=sum;
    }
    sort(Q+1,Q+1+q,[&](Query a,Query b){return a.id<b.id;});
    for(int i=1;i<=q;++i) printf("%lld\n",Q[i].ans);
    return 0;
}