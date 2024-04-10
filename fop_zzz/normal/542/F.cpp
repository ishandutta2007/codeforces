#include<cstdio>
#include<string>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#define For(i,j,k) for(int i=j;i<=k;++i)
#define Dow(i,j,k) for(int i=k;i>=j;--i)
#define ll long long
#define inf 1e9
using namespace std;
inline ll read()
{
    ll t=0,f=1;char c=getchar();
    while(c<'0'||c>'9')	{if(c=='-')	f=-1;c=getchar();}
    while(c<='9'&&c>='0')	t=t*10LL+c-48LL,c=getchar();
    return t*f;
}
priority_queue<int> q[20001];
int n,T,x,y;
int main()
{
	n=read();T=read();
	For(i,1,n)	
	{ 
		x=read();y=read();
		q[x].push(y);
	}
	For(i,1,T-1)
	{
		while(!q[i].empty())
		{
			int tmp=q[i].top();q[i].pop();
			if(!q[i].empty())	tmp+=q[i].top(),q[i].pop();
			q[i+1].push(tmp);
		}
	}
	cout<<q[T].top()<<endl;
}