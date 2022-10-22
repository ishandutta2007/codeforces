#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 2501
int N,K,f[MAXN];struct Edge{int u,v,w;}E[MAXN*MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int getf(int x){return f[x]==x?x:f[x]=getf(f[x]);}
int main()
{
	N=get();For(i,1,N)For(j,1,N){int x=get();if(i!=j)E[++K]={i,j,x};else if(x){cout<<"NOT MAGIC\n";return 0;}}For(i,1,N)f[i]=i;sort(E+1,E+K+1,[&](const Edge&a,const Edge&b){return a.w<b.w;});
	For(i,1,K){int j=i;while(j<K&&E[j].w==E[j+1].w)j++;For(k,i,j)if(getf(E[k].u)==getf(E[k].v)){cout<<"NOT MAGIC\n";return 0;}For(k,i,j)f[getf(E[k].u)]=getf(E[k].v);i=j;}cout<<"MAGIC\n";return 0;
}