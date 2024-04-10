#include<iostream>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define R (l+r>>1)
#define L (l+r>>1)+1
#define ls(x) x<<1
#define rs(x) x<<1|1
#define MAXN 100001
int N,M,a[MAXN],tr[MAXN*4][20],tg[MAXN*4];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
void put(ll x){if(x>=10)put(x/10);putchar(x%10+'0');}
void psh(int k){For(i,0,19)tr[k][i]=tr[ls(k)][i]+tr[rs(k)][i];}void pt(int k,int l,int r,int v){For(i,0,19)if((v>>i)&1)tr[k][i]=r-l+1-tr[k][i],tg[k]^=1<<i;}void dwn(int k,int l,int r){if(tg[k])pt(ls(k),l,R,tg[k]),pt(rs(k),L,r,tg[k]),tg[k]=0;}
void build(int k,int l,int r){l!=r?build(ls(k),l,R),build(rs(k),L,r),psh(k):pt(k,l,r,a[l]);}
void upd(int k,int l,int r,int x,int y,int v){l<=y&&r>=x?l<x||r>y?dwn(k,l,r),upd(ls(k),l,R,x,y,v),upd(rs(k),L,r,x,y,v),psh(k):pt(k,l,r,v),0:0;}
int ask(int k,int l,int r,int x,int y,int v){return l<=y&&r>=x?l<x||r>y?dwn(k,l,r),ask(ls(k),l,R,x,y,v)+ask(rs(k),L,r,x,y,v):tr[k][v]:0;}
ll Ask(int l,int r){ll ans=0;For(i,0,19)ans+=(1ll<<i)*ask(1,1,N,l,r,i);return ans;}
int main(){N=get();For(i,1,N)a[i]=get();build(1,1,N);M=get();For(i,1,M){int opt=get(),l=get(),r=get();opt==2?upd(1,1,N,l,r,get()),0:(put(Ask(l,r)),putchar('\n'),0);}return 0;}