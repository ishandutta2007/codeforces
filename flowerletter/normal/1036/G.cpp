#include <bits/stdc++.h>
using namespace std;
vector <int> e[2000005];
int w[2000005],deg[2000005],checks[2000005],checkt[2000005],a[30],cnt[3000005],dp[3000005];
queue <int> q;
signed main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++)
		checks[i]=checkt[i]=1;
	for(int i=1;i<=3000000;i++)
		cnt[i]=cnt[i^i&-i]+1;
	for(int i=1;i<=m;i++)
	{
		int u,v;
		cin >> u >> v;
		e[v].push_back(u);
		++deg[u],checks[v]=0,checkt[u]=0;
	}
	int Cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(checkt[i])
			w[i]=1<<Cnt++,q.push(i);
	}
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(auto v:e[x])
		{
			if(!--deg[v]) q.push(v);
			w[v]|=w[x];
		}
	}
	int CNT=0,flag=1;
	for(int i=1;i<=n;i++)
		if(checks[i]) a[CNT++]=w[i];
	for(int i=1;i<(1<<CNT);i++)
	{
		for(int j=0;j<CNT;j++)
			if(i&(1<<j)) dp[i]=dp[i^(1<<j)]|a[j];
		if(cnt[dp[i]]<=cnt[i]&&cnt[i]!=CNT)
		{
			flag=0;
		}
	}
	if(flag) cout << "YES";
	else cout << "NO";
	return 0;
}