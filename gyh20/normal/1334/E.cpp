#include<bits/stdc++.h>
#define re register
#define int long long
#define M 998244353
using namespace std;
inline int read(){
    re int t=0;re char v=getchar();
    while(v<'0')v=getchar();
    while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
    return t;
}
int d,q,l,r,jc[100002],inv[100002];
inline int gcd(re int x,re int y){
    return y?gcd(y,x%y):x;
}
map<int,int>v;
inline int random(int n)
{
return (int)((double)rand()/RAND_MAX*n+0.5);
}
int pp[40]= {9643,9649,9661,9677,9679,9689,9697,9719,9721,9733,9739,9743,9749,9767,9769,9781,9787,9791,9803,9811,9817,9829};
#define ll long long
inline ll msc(ll x,ll y,ll p) {
    ll z=(long double)x/p*y;
    ll res=(unsigned ll)x*y-(unsigned ll)z*p;
    return (res+p)%p;
}
inline ll ksm(ll x,ll y,ll z) {
    if(!y)return 1;
    ll tmp=ksm(x,y/2,z);
    if(y&1)return msc(msc(tmp,tmp,z),x,z);
    else return msc(tmp,tmp,z);
}

inline bool mr(re ll n) {
    if(n==2)return 1;
    if(n<2)return 0;
    re ll m=n-1;
    re int k=0;
    while(m%2==0)k++,m/=2;
    for(re int i=1; i<=5; i++) {
        ll kk=rand()%(n-1)+1,x=ksm(kk,m,n),y=0;
        for(re int j=1; j<=k; j++) {
            y=msc(x,x,n);
            if(y==1&&x!=1&&x!=n-1)return 0;
            x=y;
        }
        if(y!=1)return 0;
    }
    return 1;
}
#define ll long long 
inline int as(re int x){
    return x>0?x:-x;
}
inline ll pr(ll x,ll c) {
    if(!c)c=rand();
    ll s=0,t=0;
    int stp=0,goal=1;
    ll val=1;
    for(goal=1;;goal<<=1,s=t,val=1) {
        for(stp=1; stp<=goal; ++stp) {
            t=(msc(t,t,x)+c)%x;
            val=msc(val,as(t-s),x);
            if((stp%127)==0) {
                ll d=gcd(val,x);
                if(d>1)return d;
            }
        }
        ll d=gcd(val,x);
        if(d>1)return d;
    }
}
int tot,ans[100002];
inline void ff(re int x){
    if(x==1)return;
    if(mr(x)){
        ans[++tot]=x;
        return;
    }
    int p=x,tmp=0;  
    while(p>=x)p=pr(x,pp[tmp++]);
    ff(p);
    ff(x/p);
}
inline int ksm(re int x,re int y){
    re int ans=1;
    while(y){
        if(y&1)ans=1ll*ans*x%M;
        x=1ll*x*x%M;
        y>>=1;
    }
    return ans;
}
inline int calc(re int x){
    if(v.find(x)!=v.end())return v[x];
    if(x==1)return 1;
    re int siz=0;
    for(re int i=1;i<=tot;++i){
        if(x%ans[i]==0)siz+=calc(x/ans[i]),siz%=M;
    }
    return v[x]=siz;
}
signed main(){
    d=read();tot=0;ff(d);
    re int cnt=0;
    for(re int i=1;i<=tot;++i)if(ans[i]!=ans[i-1])ans[++cnt]=ans[i];tot=cnt;
    q=read();
    while(q--){
        re int l=read(),r=read(),x=gcd(l,r);
        l/=x;r/=x;
        printf("%lld\n",calc(l)*calc(r)%M);
    }
}