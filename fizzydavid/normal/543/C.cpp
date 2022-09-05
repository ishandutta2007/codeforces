//while(true)rp++;
#include<bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<"="<<x<<endl;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
ll dp[1050000];
int n,m;
ll c[22][22];
string s[22];
vector<pair<int,ll> >v;
vector<int>tv;
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	string tmps;
	for(int i=1;i<=n;i++)
	{
		cin>>tmps;
		s[i]=' '+tmps;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>c[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		ll tmp=c[i][1];
		for(int j=1;j<=m;j++)
			tmp=min(tmp,c[i][j]);
		v.PB(MP(1<<(i-1),tmp));
	}
	for(int i=1;i<=m;i++)
	{
		for(char ch='a';ch<='z';ch++)
		{
			ll sum=0,mx=0;
			int id=0;
			tv.clear();
			for(int j=1;j<=n;j++)
			{
				if(ch==s[j][i])
				{
					tv.PB(j);
					id+=1<<(j-1);
					sum+=c[j][i];
					mx=max(mx,c[j][i]);
				}
			}
			v.PB(MP(id,sum-mx));
		}
	}
	dp[0]=0;
	for(int i=1;i<(1<<n);i++)
	{
		dp[i]=LINF;
		for(int j=0;j<v.size();j++)
		{
			dp[i]=min(dp[i&(~v[j].FF)]+v[j].SS,dp[i]);
		}
	}
	cout<<dp[(1<<n)-1]<<endl;
	return 0;
}