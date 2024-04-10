// 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LINF=1ll<<61;
int n,m;
ll a[200111],d[200111];
struct node
{
    ll mx1,mx2,mx;
}t[500111];
node calmax(const node &tmp1,const node &tmp2)
{
    node res;
    res.mx1=max(tmp1.mx1,tmp2.mx1);
    res.mx2=max(tmp1.mx2,tmp2.mx2);
    res.mx=max(tmp1.mx1+tmp2.mx2,max(tmp1.mx,tmp2.mx));
    return res;
}
void build(int id,int l,int r)
{
    if(l==r)t[id].mx1=a[l]*2-d[l],t[id].mx2=a[l]*2+d[l],t[id].mx=-LINF;
    else
    {
        build(id<<1,l,l+r>>1);
        build(id<<1|1,(l+r>>1)+1,r);
        t[id]=calmax(t[id<<1],t[id<<1|1]);
    }
}
node query(int id,int l,int r,int tl,int tr)
{
    if(l<=tl&&tr<=r)return t[id];
    if(r<=tl+tr>>1)return query(id<<1,l,r,tl,tl+tr>>1);
    if(tl+tr>>1<l)return query(id<<1|1,l,r,(tl+tr>>1)+1,tr);
    return calmax(query(id<<1,l,r,tl,tl+tr>>1),query(id<<1|1,l,r,(tl+tr>>1)+1,tr));
}
inline int getval()
{
    int __res=0;bool neg=0;
    char __c;
    while((__c=getchar())!=' '&&__c!='\n')
    {
        if(__c=='-')neg=1;
        else __res=__res*10+__c-'0';
    }
    if(neg)__res=-__res;
    return __res;
}
int main()
{
    n=getval();m=getval();ll x;
    for(int i=1;i<=n;i++)x=getval(),d[i+1]=d[i]+x;
    for(int i=n+1;i<=(n<<1);i++)d[i+1]=d[n+1]+d[i-n+1];
    for(int i=1;i<=n;i++)a[i]=getval(),a[i+n]=a[i];
    build(1,1,n<<1);
    for(int i=1;i<=m;i++)
    {
        int l,r;
        l=getval();r=getval();
        if(l<=r)l+=n;l--,r++;if(r<l)swap(l,r);
        printf("%I64d\n",query(1,l,r,1,n<<1).mx);
    }
    return 0;
}