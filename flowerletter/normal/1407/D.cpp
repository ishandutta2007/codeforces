#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int a[300005],s[300005],cnt,mx[300005],mn[300005],dp[300005],qwq[300005],qaq[300005],qwqp[300005],qaqp[300005];
vector <int> e[300005];
int main(int argc, char** argv) {
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	qwq[n]=qaq[n]=a[n],qwqp[n]=qaqp[n]=n;
	for(int i=n-1;i>=1;i--)
	{
		qwq[i]=qwq[i+1],qaq[i]=qaq[i+1],qwqp[i]=qwqp[i+1],qaqp[i]=qaqp[i+1];
		if(a[i]<=qwq[i+1])  qwq[i]=a[i],qwqp[i]=i;
		if(a[i]>=qaq[i+1]) qaq[i]=a[i],qaqp[i]=i;
	}
	for(int i=1;i<=n;i++)
	{
		while(cnt&&a[s[cnt]]<=a[i])
			mn[s[cnt--]]=i;
		s[++cnt]=i;
	}
	cnt=0;
	for(int i=n;i>=1;i--)
	{
		while(cnt&&a[s[cnt]]<=a[i])
			e[i].push_back(s[cnt--]);
		s[++cnt]=i;
	}
	cnt=0;
	for(int i=1;i<=n;i++)
	{
		while(cnt&&a[s[cnt]]>=a[i])
			mx[s[cnt--]]=i;
		s[++cnt]=i;
	}
	cnt=0;
	for(int i=n;i>=1;i--)
	{
		while(cnt&&a[s[cnt]]>=a[i])
			e[i].push_back(s[cnt--]);
		s[++cnt]=i;
	}
	for(int i=1;i<=n;i++)
	{
		e[i].push_back(mx[i]),e[i].push_back(mn[i]),e[i].push_back(i+1);
		if(a[i]>qaq[i+1])
			e[i].push_back(qaqp[i+1]);
		if(a[i]<qwq[i+1])
			e[i].push_back(qwqp[i+1]);
	}
	for(int i=2;i<=n;i++) dp[i]=1e9;
//	for(int i=1;i<=n;i++)
//		cout << mn[i] << " " << mx[i] << "\n";
//	puts("");
	for(int i=1;i<=n;i++)
	{
		for(auto v:e[i])
		{
			if(v>=1&&v<=n)
			{
				dp[v]=min(dp[v],dp[i]+1);
			}
		}
	}
	cout << dp[n];
	return 0;
}