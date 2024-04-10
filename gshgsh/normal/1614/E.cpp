#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define R (l+r>>1)
#define L (l+r>>1)+1
#define INF 1000000001
#define MAXN 20000001
int N,rt,tot,ls[MAXN],rs[MAXN],sum[MAXN],lval[MAXN],lst;
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
void upd(int&k,int l,int r,int x,int v){if(!k)k=++tot;if(l!=r)x<=R?upd(ls[k],l,R,x,v):upd(rs[k],L,r,x,v),sum[k]=sum[ls[k]]+sum[rs[k]],lval[k]=lval[ls[k]];else sum[k]+=v,lval[k]+=v;}
int ask(int k,int l,int r,int x,int y){return k&&l<=y&&r>=x?l<x||r>y?ask(ls[k],l,R,x,y)+ask(rs[k],L,r,x,y):sum[k]:0;}
int Ask(int x){return ask(rt,0,INF,0,x)+x;}
int Getmn(int k,int l,int r,int nsum,int v){if(l==r)return l;if(nsum+sum[ls[k]]+R>=v)return Getmn(ls[k],l,R,nsum,v);return Getmn(rs[k],L,r,nsum+sum[ls[k]],v);}
int Getmx(int k,int l,int r,int nsum,int v){if(l==r)return l;if(nsum+sum[ls[k]]+lval[rs[k]]+L<=v)return Getmx(rs[k],L,r,nsum+sum[ls[k]],v);return Getmx(ls[k],l,R,nsum,v);}
int main()
{
	int N=get();
	For(i,1,N)
	{
		int t=get();int x=Ask(0),y=Ask(INF-1);
		if(x>t){upd(rt,0,INF,0,-1);int k=get();while(k--){int x=(get()+lst)%INF;cout<<(lst=Ask(x))<<'\n';}continue;}
		if(y<t){upd(rt,0,INF,0,1);int k=get();while(k--){int x=(get()+lst)%INF;cout<<(lst=Ask(x))<<'\n';}continue;}
		int l=Getmn(rt,0,INF,0,t),r=Getmx(rt,0,INF,0,t);upd(rt,0,INF,0,1);upd(rt,0,INF,l,-1);upd(rt,0,INF,r+1,-1);
		int k=get();while(k--){int x=(get()+lst)%INF;cout<<(lst=Ask(x))<<'\n';}
	}
	return 0;
}