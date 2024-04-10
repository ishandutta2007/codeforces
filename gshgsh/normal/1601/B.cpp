#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
#include<queue>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 300001
int N,a[MAXN],b[MAXN],f[MAXN],dep[MAXN],pre[MAXN],pre2[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
void print(int x){if(x!=N)print(pre[x]),cout<<pre2[x]<<' ';}
int getf(int x){return f[x]==x?x:f[x]=getf(f[x]);}
int main()
{
	N=get();For(i,1,N)a[i]=get(),f[i]=i;For(i,1,N)b[i]=get();For(i,0,N)dep[i]=-1;dep[N]=0;queue<int>q;q.push(N);
	while(!q.empty())
	{
		int u=q.front();q.pop();if(a[u]==u){cout<<dep[u]+1<<'\n';print(u);cout<<"0\n";return 0;}
		for(int i=getf(u-a[u]);i<u;i=getf(i+1)){f[getf(i)]=getf(i+1);if(dep[i+b[i]]==-1)dep[i+b[i]]=dep[u]+1,pre[i+b[i]]=u,pre2[i+b[i]]=i;q.push(i+b[i]);}
	}
	cout<<"-1\n";return 0;
}