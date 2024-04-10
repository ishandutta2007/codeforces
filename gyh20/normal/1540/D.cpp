#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
re int t=0;re char v=getchar();
while(v<'0')v=getchar();
while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
return t;
}
const int M=998244353;
inline void add(re int &x,re int y){(x+=y)>=M?x-=M:x;}
inline int ksm(re int x,re int y){
re int s=1;
while(y){ 
if(y&1)s=1ll*s*x%M;
x=1ll*x*x%M,y>>=1;
}
return s;
}
struct edge{int to,next;}e[2000002];
int t,n,m,a[1000002],ans,cnt,head[1000002],bl[1000002],num,blk[100002],B,st[100002],ed[100002],stk[502][502],tg[2002],vis[100002],len[100002],mn[2002],c[2002],pos[2002];
inline void pu(re int p){
if(mn[p<<1]<mn[p<<1|1])mn[p]=mn[p<<1],pos[p]=pos[p<<1];
else mn[p]=mn[p<<1|1],pos[p]=pos[p<<1|1];
}
inline void build(re int p,re int l,re int r){
if(l==r){
mn[p]=c[l],pos[p]=l;return;
}
re int mid=l+r>>1;
build(p<<1,l,mid),build(p<<1|1,mid+1,r);
pu(p);
}
inline void Add(re int p,re int x){
tg[p]+=x,mn[p]+=x;
}
inline void pd(re int p){
if(tg[p])Add(p<<1,tg[p]),Add(p<<1|1,tg[p]),tg[p]=0;
}
inline void cg(re int p,re int l,re int r,re int x,re int y){
if(l==r){mn[p]=y;return;}
pd(p);
re int mid=l+r>>1;
if(x<=mid)cg(p<<1,l,mid,x,y);
else cg(p<<1|1,mid+1,r,x,y);
pu(p);
}
inline void add(re int p,re int l,re int r,re int x,re int y){
if(l>=x&&r<=y)return Add(p,-1);
pd(p);
re int mid=l+r>>1;
if(x<=mid)add(p<<1,l,mid,x,y);
if(y>mid)add(p<<1|1,mid+1,r,x,y);
pu(p);
}
inline void buildd(re int p,re int l,re int r){
memset(tg,0,sizeof(tg)),memset(mn,0,sizeof(mn)),memset(pos,0,sizeof(pos));
for(re int i=l;i<=r;++i)c[i-l+1]=a[i];
re int L=r-l+1;
build(1,1,L);
for(re int i=1;i<=r-l+1;++i){
stk[p][i]=mn[1],stk[p][i]=max(stk[p][i],stk[p][i-1]);
re int xx=pos[1];
if(xx^L)add(1,1,L,xx+1,L);
cg(1,1,L,xx,1e9);
}
stk[p][len[p]+1]=1e9;
}
signed main(){
n=read(),B=sqrt(n);
for(re int i=1;i<=n;++i)a[i]=read(),bl[i]=(i-1)/B+1;
for(re int i=1;i<=n;++i){
if(!st[bl[i]])st[bl[i]]=i;
ed[bl[i]]=i;
}
for(re int i=1;i<=bl[n];++i)len[i]=ed[i]-st[i]+1,buildd(i,st[i],ed[i]);
m=read();
while(m--){
re int o=read(),x=read();
if(o==1)a[x]=read(),buildd(bl[x],st[bl[x]],ed[bl[x]]);
else{
re int ans=a[x];
for(re int j=x+1;j<=ed[bl[x]];++j)ans+=(ans>=a[j]);
for(re int j=bl[x]+1;j<=bl[n];++j){
re int pos=upper_bound(stk[j]+1,stk[j]+len[j]+2,ans)-stk[j];
ans+=pos-1;
}
printf("%d\n",n-ans);
}
}
}