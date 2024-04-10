#include<iostream>
#include<cstdio>
#include<queue>
#define ll long long
#define mp(x,y) make_pair(x,y)
#define pa pair<ll,int>
#define MN 500000
using namespace std;
inline int read()
{
	int x = 0; char ch = getchar();
	while(ch < '0' || ch > '9')  ch = getchar();
	while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
	return x;
}

int A[MN+5],B[MN+5],n,m;ll tot;
priority_queue<pa,vector<pa>,greater<pa> > q;

int Solve(int x)
{
	tot=0;int num=0;
	for(int i=1;i<=n;++i)
	{	
		q.push(mp(A[i],0));
		ll t=q.top().first,now=B[i]-x;
		if(now+t<0) 
		{
			tot+=now+t;
			q.pop();
			q.push(mp(-now,1));		
		}
	}
	while(!q.empty()) num+=q.top().second,q.pop();
	return num;
}

int main()
{
	n=read();m=read();
	for(int i=1;i<=n;++i) A[i]=read();
	for(int i=1;i<=n;++i) B[i]=read();
	int l=0,r=2e9,mid;
	while(l<=r)
	{
		mid=1LL*l+r>>1;int num=Solve(mid);
		if(num==m) return 0*printf("%lld\n",tot+1LL*m*mid);
		if(num<m) l=mid+1;
		else r=mid-1;
	}
	return 0;
}