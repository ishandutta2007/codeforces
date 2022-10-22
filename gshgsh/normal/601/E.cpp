#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define ls(x) x<<1
#define rs(x) x<<1|1
#define R (l+r>>1)
#define L (l+r>>1)+1
#define base 10000019
#define P 1000000007
#define MAXN 30001
#define MAXM 1001
int N,M,Q,tot,s[MAXN*2],e[MAXN*2],v[MAXN*2],w[MAXN*2],f[MAXM],g[MAXM];bool que[MAXN];vector<pair<int,int>>q[MAXN*4];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
void upd(int k,int l,int r,int x,int y,int v,int w){if(l>=x&&r<=y)return q[k].push_back({v,w});x<=R&&(upd(ls(k),l,R,x,y,v,w),0),y>=L&&(upd(rs(k),L,r,x,y,v,w),0);}
void ask(int k,int l,int r)
{
	int*g=new int[M+1];For(i,0,M)g[i]=f[i];for(auto i:q[k]){int v=i.first,w=i.second;FOR(i,M,w)f[i]=max(f[i],f[i-w]+v);}
	if(l==r){if(que[l]){int ans=0,mul=1;For(i,1,M)ans=(ans+1ll*f[i]*mul)%P,mul=1ll*mul*base%P;cout<<ans<<'\n';}For(i,0,M)f[i]=g[i];return;}
	ask(ls(k),l,R),ask(rs(k),L,r);For(i,0,M)f[i]=g[i];
}
int main()
{
	N=get(),M=get();For(i,1,N)s[i]=1,v[i]=get(),w[i]=get();tot=N;
	Q=get();For(i,1,Q){int opt=get();if(opt==1){s[++tot]=i,v[tot]=get(),w[tot]=get();}else if(opt==2)e[get()]=i;else que[i]=1;}
	For(i,1,tot)!e[i]&&(e[i]=Q),upd(1,1,Q,s[i],e[i],v[i],w[i]);ask(1,1,Q);return 0;
}