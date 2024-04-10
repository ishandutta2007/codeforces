#pragma GCC optimize(3)
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include<iostream>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define ls(x) x<<1
#define rs(x) x<<1|1
#define R (l+r>>1)
#define L (l+r>>1)+1
#define MAXN 200001
int N,M,a[MAXN];ll sum[MAXN*4],mx[MAXN*4],tg[MAXN*4];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
void put(int x){if(x>=10)put(x/10);putchar(x%10+'0');}
void psh(int k){sum[k]=sum[ls(k)]+sum[rs(k)],mx[k]=max(mx[ls(k)],mx[rs(k)]);}void pt(int k,int l,int r,int v){sum[k]=1ll*(r-l+1)*v,mx[k]=v,tg[k]=v;}void dwn(int k,int l,int r){if(tg[k])pt(ls(k),l,R,tg[k]),pt(rs(k),L,r,tg[k]),tg[k]=0;}
void build(int k,int l,int r){l!=r?build(ls(k),l,R),build(rs(k),L,r),psh(k),0:sum[k]=mx[k]=a[l];}
void upd(int k,int l,int r,int x,int y,int v){l<=y&&r>=x?l<x||r>y?dwn(k,l,r),upd(ls(k),l,R,x,y,v),upd(rs(k),L,r,x,y,v),psh(k):pt(k,l,r,v),0:0;}
ll ask(int k,int l,int r,int x,int y){return l<=y&&r>=x?l<x||r>y?dwn(k,l,r),ask(ls(k),l,R,x,y)+ask(rs(k),L,r,x,y):sum[k]:0;}
int get1(int k,int l,int r,int v){return l!=r?dwn(k,l,r),mx[rs(k)]>v?get1(rs(k),L,r,v):min(get1(ls(k),l,R,v),L):mx[k]>v?N+1:l;}
int get2(int k,int l,int r,ll v){return l!=r?dwn(k,l,r),sum[ls(k)]>v?get2(ls(k),l,R,v):max(get2(rs(k),L,r,v-sum[ls(k)]),R):mx[k]>v?0:l;}
void Upd(int x,int v){int l=get1(1,1,N,v);upd(1,1,N,l,x,v);}
int Ask(int x,ll v){int cnt=0;while(x<=N){x=max(get1(1,1,N,v),x);if(x>N)break;v+=ask(1,1,N,1,x-1);int r=get2(1,1,N,v);cnt+=r-x+1,v-=ask(1,1,N,1,r),x=r+1;}return cnt;}
int main(){N=get(),M=get();For(i,1,N)a[i]=get();build(1,1,N);For(i,1,M){int opt=get(),x=get(),v=get();opt==1?Upd(x,v),0:(put(Ask(x,v)),putchar('\n'),0);}return 0;}