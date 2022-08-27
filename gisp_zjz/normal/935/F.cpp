#include<bits/stdc++.h>
#define maxn 250002

using namespace std;
typedef long long ll;
const ll inf=1ll*100000000*100000000;

struct seg{
    ll l,r,val,ps;
};

seg a[maxn*4];
ll n,query,o,u,v,w,c[maxn],ans,b[maxn],ss;

void build(int p,int l,int r)
{
    a[p].l=l; a[p].r=r;
    if (l==r){
        a[p].val=b[l]; c[l]=p;
        a[p].ps=max(0ll,b[l+1]-b[l])+max(0ll,b[l-1]-b[l]);
        if (l==1||l==n) a[p].ps=inf;
        return ;
    }
    int mid=(l+r)>>1;
    build(p*2,l,mid);
    build(p*2+1,mid+1,r);
    a[p].ps=min(a[p*2].ps,a[p*2+1].ps);
}

ll q(int x)
{
    ll tmp=c[x],rt=0;
    while (tmp){
        rt+=a[tmp].val;
        tmp>>=1;
    }
    return rt;
}

void update(int p,int l,int r,ll res)
{
    if (a[p].r<l||a[p].l>r) return;
    if (a[p].l>=l&&a[p].r<=r){
        a[p].val+=res;
        return ;
    }
    update(p*2,l,r,res);
    update(p*2+1,l,r,res);
}

void update2(int x)
{
    a[c[x]].ps=max(0ll,q(x-1)-q(x))+max(0ll,q(x+1)-q(x));;
    int tmp=c[x]/2;
    while (tmp){
        a[tmp].ps=min(a[tmp*2].ps,a[tmp*2+1].ps);
        tmp>>=1;
    }
}

ll qry(int p,int l,int r)
{
    if (a[p].r<l||a[p].l>r) return inf;
    if (a[p].l>=l&&a[p].r<=r) return a[p].ps;
    return min(qry(p*2,l,r),qry(p*2+1,l,r));
}

int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&b[i]);
    build(1,1,n);ans=0;
    scanf("%d",&query);
    for (int i=1;i<n;i++) ans+=abs(b[i]-b[i+1]);
    while (query--)
    {
        scanf("%d%d%d%d",&o,&u,&v,&w);
        if (o==2){
            if (u>1) ans-=abs(q(u-1)-q(u));
            if (v<n) ans-=abs(q(v+1)-q(v));
            update(1,u,v,w);
            if (u>1) ans+=abs(q(u-1)-q(u));
            if (v<n) ans+=abs(q(v+1)-q(v));
            if (u>1) update2(u); if (u>2) update2(u-1);
            if (v<n) update2(v); if (v<n-1) update2(v+1);
        }
        else{
            ss=(w-qry(1,u,v))*2;
            if (u==1) ss=max(ss,abs(q(1)+w-q(2))-abs(q(1)-q(2)));
            if (v==n) ss=max(ss,abs(q(n)+w-q(n-1))-abs(q(n)-q(n-1)));
            if (u!=v) ss=max(ss,0ll);
            else{
                ss=0;
                if (u>1) ss+=abs(q(u)+w-q(u-1))-abs(q(u)-q(u-1));
                if (u<n) ss+=abs(q(u)+w-q(u+1))-abs(q(u)-q(u+1));
            }
            printf("%lld\n",ans+ss);
        }
    }
    //for (int i=1;i<=n;i++) cout << q(i) << endl;
    return 0;
}