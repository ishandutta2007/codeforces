#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 200001
int T,N,a[MAXN],dep[MAXN];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
int main()
{
	T=get();
	while(T--)
	{
		N=get();For(i,1,N)a[i]=get();queue<int>q;q.push(1);int id=2;
		while(!q.empty()){int u=q.front();q.pop();do{q.push(id),dep[id++]=dep[u]+1;}while(id<=N&&a[id]>a[id-1]);if(id>N)break;}cout<<dep[N]<<endl;
	}
	return 0;
}