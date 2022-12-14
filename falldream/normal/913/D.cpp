#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
#include<queue>
#define MN 200000
#define pa pair<int,int>
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
priority_queue<pa>q; 
int n,T,ans=0,from=0;
vector<pa> v[MN+5];

void Solve(int stop=0)
{
	while(!q.empty()) q.pop();
	int sum=0;
	for(int i=n;i;--i)
	{
		for(int j=0;j<v[i].size();++j) q.push(v[i][j]),sum+=v[i][j].first;
		while(sum>T||q.size()>i) sum-=q.top().first,q.pop();
		if(i==stop) return;
		if(q.size()>ans) ans=q.size(),from=i;
	}
}

int main()
{
	n=read();T=read();
	for(int i=1;i<=n;++i) 
	{
		int a=read();
		v[a].push_back(make_pair(read(),i));
	}
	Solve();
	if(!ans) return 0*puts("0\n0");
	Solve(from);
	printf("%d\n%d\n",ans,ans);
	while(!q.empty()) printf("%d ",q.top().second),q.pop(); 
	return 0;
}