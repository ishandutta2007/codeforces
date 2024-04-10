#include<bits/stdc++.h>
using namespace std;
const int N = 1.1e5;
typedef long long ll;
int qpow(int a,int b,int mod)
{
    int ans=1;
    for(;b;b>>=1,a=1ll*a*a%mod) 
        if(b&1) ans=1ll*a*ans%mod;
    return ans;
}
struct node
{
    int l,r; mutable ll v;
    node(int ll,int rr=-1,long long vv=0):l(ll),r(rr),v(vv){}
    bool operator<(const node&o) const { return l<o.l; }
};
set <node> ODT;
using IT=set<node>::iterator;
IT split(int pos)
{
    auto it=ODT.lower_bound(node(pos));
    if(it!=ODT.end() && it->l == pos) return it;
    --it; int l=it->l, r=it->r; ll v=it->v;
    ODT.erase(it),ODT.insert(node(l,pos-1,v));
    return ODT.insert(node(pos,r,v)).first;
}
void add(int l,int r,ll val)
{
    auto itl=split(l),itr=split(r+1);
    for(;itl!=itr;++itl) itl->v+=val;
}
void assign(int l,int r,ll val)
{
    auto itl=split(l),itr=split(r+1);
    ODT.erase(itl,itr);
    ODT.insert(node(l,r,val));
}
ll rnk(int l,int r,int k)
{
    static vector<pair<ll,int> >vp;
    auto itl=split(l),itr=split(r+1);
    vp.clear();
    for(;itl!=itr;++itl) 
        vp.push_back({itl->v,itl->r-itl->l+1});
    sort(vp.begin(),vp.end());
    for(auto it:vp) 
    {
        k-=it.second; 
        if(k<=0) return it.first;
    }
    return -1ll;
}
ll sum(int l,int r,int ex,int mod)
{
    auto itl=split(l),itr=split(r+1);
    ll res=0;
    for(;itl!=itr;++itl) 
        res=(res+1ll*(itl->r-itl->l+1)*qpow(itl->v%mod,ex,mod)%mod)%mod;
    return res;
}
int n,m; ll seed,vmax,a[N];
const ll mod = 1e9+7;
inline ll rnd()
{
    ll ret=seed;
    seed=(seed*7+13)%mod;
    return ret;
}
signed main()
{
    scanf("%d %d %lld %lld",&n,&m,&seed,&vmax);
    for(int i=1;i<=n;++i)
    {
        a[i]=(rnd()%vmax)+1;
        ODT.insert(node(i,i,a[i]));
    }
    ODT.insert(node(n+1,n+1,0));
    for(int op,l,r,x,y,i=1;i<=m;++i)
    {
        op=rnd()%4+1; l=rnd()%n+1; r=rnd()%n+1;
        if(l>r) swap(l,r);
        if(op==3) 
            x=(rnd()%(r-l+1))+1;
        else 
            x=(rnd()%(vmax))+1;
        if(op==4)
            y=(rnd()%(vmax))+1;
        if(op==1)
            add(l,r,x);
        if(op==2)
            assign(l,r,x);
        if(op==3)
            printf("%lld\n",rnk(l,r,x));
        if(op==4)
            printf("%lld\n",sum(l,r,x,y));
    }
    return 0;
}