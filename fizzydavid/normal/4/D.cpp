#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<set>
#include<utility>
#include<vector>
using namespace std;
#define ff first
#define ss second
#define pb push_back 
#define mp make_pair
typedef long long ll;
const int INF=1<<28;
const long long LINF=1ll<<61;
int n,w[5111],h[5111],nxt[5111],dp[5111];
int dfs(int x)
{
	if(dp[x]!=0)return dp[x];
	int mx=0;
	for(int i=1;i<=n;i++)
	{
		if(w[x]<w[i]&&h[x]<h[i])
		{
			int tmp=dfs(i);
			if(tmp>mx)mx=tmp,nxt[x]=i;
		}
	}
	return dp[x]=mx+1;
}
int main()
{
	scanf("%d%d%d",&n,&w[0],&h[0]);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&w[i],&h[i]);
	}
	dfs(0);
	cout<<dp[0]-1<<endl;
	int tmp=0;
	while(nxt[tmp]!=0)
	{
		cout<<nxt[tmp]<<" ";
		tmp=nxt[tmp];
	}
// 	system("pause");
	return 0;
}