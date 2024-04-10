#include <bits/stdc++.h>
#pragma comment(linker, "/stack:247474112")
#pragma GCC optimize("Ofast")
#define fi first
#define se second
using namespace std;
typedef long long ll;
const int N=400005;
const ll MOD=1e9+7;
ll isp[N],prm[N],val[N],n,q,cnt,a[N];
ll mypow(ll a,ll b)
{
    if(!b) return 1;
    ll t=mypow(a,b/2);
    if(b%2) return t*t%MOD*a%MOD;
    return t*t%MOD;
}
struct st
{
    ll vl,arr;
    st(){vl=arr=0;}
};
st tree[4*N],lazy[4*N];
ll gv(st a)
{
    ll res=a.vl;
    for(int i=0;i<cnt;i++){
        if(!(a.arr&(1LL<<i))) continue;
        (res*=val[i])%=MOD;
    }
    return res;
}
st mrg(st a,st b)
{
    st res;
    res.vl=a.vl*b.vl%MOD;
    res.arr=a.arr|b.arr;
    return res;
}
void propagate(int nd,int l,int r)
{
    if(!lazy[nd].vl) return;
    (tree[nd].vl*=mypow(lazy[nd].vl,r-l+1))%=MOD;
    tree[nd].arr|=lazy[nd].arr;
    if(l!=r){
        if(!lazy[nd*2].vl) lazy[nd*2].vl=1;
        if(!lazy[nd*2+1].vl) lazy[nd*2+1].vl=1;
        (lazy[nd*2].vl*=lazy[nd].vl)%=MOD;
        (lazy[nd*2+1].vl*=lazy[nd].vl)%=MOD;
        lazy[nd*2].arr|=lazy[nd].arr;
        lazy[nd*2+1].arr|=lazy[nd].arr;
    }
    lazy[nd].vl=0; lazy[nd].arr=0;
}
void update(int nd,int l,int r,int s,int e,st v)
{
    propagate(nd,l,r);
    if(r<s||e<l) return;
    if(s<=l&&r<=e){
        lazy[nd]=v;
        propagate(nd,l,r);
        return;
    }
    int m=(l+r)/2;
    update(nd*2,l,m,s,e,v);
    update(nd*2+1,m+1,r,s,e,v);
    tree[nd]=mrg(tree[nd*2],tree[nd*2+1]);
}
void build(int nd,int l,int r)
{
    if(l==r){
        tree[nd].vl=a[l];
        for(int i=0;i<cnt;i++){
            if(a[l]%prm[i]==0)
                tree[nd].arr|=(1LL<<i);
        }
        return;
    }
    int m=(l+r)/2;
    build(nd*2,l,m);
    build(nd*2+1,m+1,r);
    tree[nd]=mrg(tree[nd*2],tree[nd*2+1]);
}
st query(int nd,int l,int r,int s,int e)
{
    propagate(nd,l,r);
    st res;
    if(r<s||e<l) return res;
    if(s<=l&&r<=e) return tree[nd];
    int m=(l+r)/2;
    st s1=query(nd*2,l,m,s,e),s2=query(nd*2+1,m+1,r,s,e);
    if(!s1.vl) return s2;
    if(!s2.vl) return s1;
    return mrg(s1,s2);
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    for(int i=2;i<=300;i++){
        if(isp[i]) continue;
        val[cnt]=(i-1LL)*mypow(i,MOD-2)%MOD;
        prm[cnt++]=i;
        for(int j=i*i;j<=300;j+=i) isp[j]=1;
    }
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>a[i];
    build(1,1,n);
    for(int i=1;i<=q;i++){
        string s; ll l,r,x;
        st res;
        cin>>s;
        if(s[0]=='M'){
            cin>>l>>r>>x;
            res.vl=x;
            for(int j=0;j<cnt;j++){
                if(x%prm[j]==0) res.arr|=(1LL<<j);
            }
            update(1,1,n,l,r,res);
        }
        else{
            cin>>l>>r;
            cout<<gv(query(1,1,n,l,r))%MOD<<"\n";
        }
    }
    return 0;
}