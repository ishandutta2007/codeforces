#include<iostream>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define ls(x) x<<1
#define rs(x) x<<1|1
#define R (l+r>>1)
#define L (l+r>>1)+1
#define INF 0x3fffffffffffffff
#define MAXN 300001
int N,a[MAXN],b[MAXN],tot,s[MAXN];ll f[MAXN],tr[MAXN*4],tg[MAXN*4];
void psh(int k,ll v){tr[k]+=v,tg[k]+=v;}void dwn(int k){psh(ls(k),tg[k]),psh(rs(k),tg[k]),tg[k]=0;}
void upd(int k,int l,int r,int x,int y,ll v){l<=y&&r>=x?l<x||r>y?dwn(k),upd(ls(k),l,R,x,y,v),upd(rs(k),L,r,x,y,v),tr[k]=max(tr[ls(k)],tr[rs(k)]):(psh(k,v),0):0;}
ll ask(int k,int l,int r,int x,int y){return l<=y&&r>=x?l<x||r>y?dwn(k),max(ask(ls(k),l,R,x,y),ask(rs(k),L,r,x,y)):tr[k]:-INF;}
int main(){cin>>N;For(i,1,N)cin>>a[i];For(i,1,N)cin>>b[i];For(i,1,N){while(a[s[tot]]>=a[i])upd(1,0,N,s[tot-1],s[tot]-1,-b[s[tot]]),tot--;upd(1,0,N,s[tot],i-1,b[i]);upd(1,0,N,i,i,f[i]=ask(1,0,N,0,i-1));s[++tot]=i;}cout<<f[N]<<endl;return 0;}