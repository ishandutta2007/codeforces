#include<iostream>
#include<vector>
#include<cstdio>
#define MN 1000
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,b[MN+5],flag=1;
vector<int>v[MN+5];
void dfs(int x)
{
	if(!v[x].size()) {b[x]=1;return;}	
	int num=0;
	for(int i=0;i<v[x].size();++i)
		dfs(v[x][i]),num+=b[v[x][i]];
	if(num<3) flag=0;
}
int main()
{
	n=read();
	for(int i=2;i<=n;++i) v[read()].push_back(i);
	dfs(1);
	puts(flag?"Yes":"No");
	return 0;
}