#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define ls(k) k<<1
#define rs(k) k<<1|1
#define R (l+r>>1)
#define L (l+r>>1)+1
#define INF 0x3fffffff
#define MAXN 35001
#define MAXM 101
int N,M,a[MAXN],pre[MAXN],mn[MAXN*4],tg[MAXN*4],f[MAXN][MAXM];
void build(int k,int l,int r){l!=r?build(ls(k),l,R),build(rs(k),L,r),0:0,mn[k]=tg[k]=0;}
void pt(int k,int v){mn[k]+=v,tg[k]+=v;}void dwn(int k){pt(ls(k),tg[k]),pt(rs(k),tg[k]),tg[k]=0;}
void upd(int k,int l,int r,int x,int y,int v){l<=y&&r>=x?l<x||r>y?dwn(k),upd(ls(k),l,R,x,y,v),upd(rs(k),L,r,x,y,v),mn[k]=min(mn[ls(k)],mn[rs(k)]):(pt(k,v),0):0;}
int ask(int k,int l,int r,int x,int y){return l<=y&&r>=x?l<x||r>y?dwn(k),min(ask(ls(k),l,R,x,y),ask(rs(k),L,r,x,y)):mn[k]:INF;}
int main()
{
	cin>>N>>M;For(i,1,N)cin>>a[i];memset(f,0x3f,sizeof(f));f[0][0]=0;
	For(j,1,M){build(1,0,N);For(i,1,N)pre[i]=0;For(i,1,N)pre[a[i]]?upd(1,0,N,0,pre[a[i]]-1,i-pre[a[i]]),0:0,pre[a[i]]=i,f[i][j]=ask(1,0,N,0,i-1),upd(1,0,N,i,i,f[i][j-1]);}cout<<f[N][M]<<endl;return 0;
}