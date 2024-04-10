#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define lowbit(x) x&-x
#define MAXN 200001
#define B 500
int N,M,x[MAXN],y[MAXN],tim[MAXN],c[MAXN],val[B+1][B+1];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
void upd(int l,int r,int v){for(int i=l;i<=M;i+=lowbit(i))c[i]+=v;for(int i=r+1;i<=M;i+=lowbit(i))c[i]-=v;}
int ask(int x){int ans=0;for(int i=x;i;i-=lowbit(i))ans+=c[i];return ans;}
void Upd1(int id,int beg,int v){for(int i=beg;i+x[id]<=M;i+=x[id]+y[id])upd(i+x[id],min(M,i+x[id]+y[id]-1),v);}
void Upd2(int id,int beg,int v){int siz=x[id]+y[id];beg%=siz;for(int i=(beg+x[id])%siz;i!=beg;i=(i+1)%siz)val[siz][i]+=v;}
void Upd(int id,int beg,int v){if(x[id]>M)return;if(x[id]+y[id]>B)Upd1(id,beg,v);else Upd2(id,beg,v);}
int Ask(int t){int sum=ask(t);For(i,1,B)sum+=val[i][t%i];return sum;}
int main()
{
	N=get(),M=get();For(i,1,N)x[i]=get(),y[i]=get();
	For(i,1,M){int opt=get(),x=get();Upd(x,opt==1?i:tim[x],opt==1?1:-1);if(opt==1)tim[x]=i;cout<<Ask(i)<<'\n';}return 0;
}