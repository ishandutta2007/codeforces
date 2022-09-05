//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define foreach(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#ifndef LOCAL
#define cerr if(0)cout
#endif
typedef long long ll;
const int mod=1e9+7;
int Tn;
vector<int> con[1011];
int n;
bool f[1011];
bool f2[1011];
int queryA(int x)
{
	printf("A %d\n",x);
	fflush(stdout);
	int ret;
	scanf("%d",&ret);
	if(ret==-1)exit(0);
	return ret;
}
int queryB(int x)
{
	printf("B %d\n",x);
	fflush(stdout);
	int ret;
	scanf("%d",&ret);
	if(ret==-1)exit(0);
	return ret;
}
int dfs(int x,int pre=-1)
{
	if(f[x])return x;
	for(auto u:con[x])
	{
		if(u==pre)continue;
		int t=dfs(u,x);
		if(t)return t;
	}
	return 0;
}
void solve()
{
	memset(f,0,sizeof(f));
	memset(f2,0,sizeof(f2));
	scanf("%d",&n);
	for(int i=1;i<=n;i++)con[i].clear();
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		con[x].PB(y);
		con[y].PB(x);
	}
	int k1,k2;
	scanf("%d",&k1);
	for(int i=0;i<k1;i++)
	{
		int x;
		scanf("%d",&x);
		f[x]=1;
	}
	int rt2;
	scanf("%d",&k2);
	for(int i=0;i<k2;i++)
	{
		int x;
		scanf("%d",&x);
		f2[x]=1;
		if(i==0)rt2=x;
	}
	int rt1=queryB(rt2);
	int p=dfs(rt1);
	int q=queryA(p);
	if(f2[q])
	{
		printf("C %d\n",p);
		fflush(stdout);
		return;
	}
	else
	{
		printf("C -1\n");
		fflush(stdout);
		return;
	}
}
int main()
{
	scanf("%d",&Tn);
	while(Tn--)
	{
		solve();
	}
	return 0;
}