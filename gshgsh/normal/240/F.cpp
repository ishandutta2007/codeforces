#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define R (l+r>>1)
#define L (l+r>>1)+1
#define ls(x) x<<1
#define rs(x) x<<1|1
#define MAXN 100001
int N,M,a[MAXN],tr[MAXN*4][26],tg[MAXN*4];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
int getc(){char c=getchar();while(c<'a'||c>'z')c=getchar();return c-'a';}\
void psh(int k){For(i,0,25)tr[k][i]=tr[ls(k)][i]+tr[rs(k)][i];}void pt(int k,int l,int r,int v){For(i,0,25)tr[k][i]=0;tr[k][v]=r-l+1,tg[k]=v;}void dwn(int k,int l,int r){if(tg[k]!=-1)pt(ls(k),l,R,tg[k]),pt(rs(k),L,r,tg[k]),tg[k]=-1;}
void build(int k,int l,int r){l!=r?build(ls(k),l,R),build(rs(k),L,r),psh(k),0:tr[k][a[l]]=1,tg[k]=-1;}
void upd(int k,int l,int r,int x,int y,int v){l<=y&&r>=x?l<x||r>y?dwn(k,l,r),upd(ls(k),l,R,x,y,v),upd(rs(k),L,r,x,y,v),psh(k):pt(k,l,r,v),0:0;}
int ask(int k,int l,int r,int x,int y,int v){return l<=y&&r>=x?l<x||r>y?dwn(k,l,r),ask(ls(k),l,R,x,y,v)+ask(rs(k),L,r,x,y,v):tr[k][v]:0;}
void Upd(int l,int r)
{
	int cnt[26],tot=0;For(i,0,25)cnt[i]=ask(1,1,N,l,r,i),tot+=cnt[i]&1;if(tot>1)return;if(tot){For(i,0,25)if(cnt[i]&1){upd(1,1,N,l+r>>1,l+r>>1,i),cnt[i]--;break;}}
	int x=l,y=r;For(i,0,25)if(cnt[i])upd(1,1,N,x,x+cnt[i]/2-1,i),upd(1,1,N,y-cnt[i]/2+1,y,i),x+=cnt[i]/2,y-=cnt[i]/2;
}
int main(){freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);N=get(),M=get();For(i,1,N)a[i]=getc();build(1,1,N);For(i,1,M){int l=get(),r=get();Upd(l,r);}For(i,1,N)For(j,0,25)if(ask(1,1,N,i,i,j)){putchar(j+'a');break;}return 0;}