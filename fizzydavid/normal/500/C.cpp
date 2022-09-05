//while(true)rp++;
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<iomanip>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<set>
#include<utility>
#include<vector>
using namespace std;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
int n,m,w[511],b[1111];
bool vis[1111];
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	ll ans=0;
	for(int i=1;i<=n;i++)cin>>w[i];
	for(int i=1;i<=m;i++)cin>>b[i];
	for(int i=1;i<=m;i++)
	{
		memset(vis,0,sizeof(vis));
		for(int j=i+1;j<=m;j++)
		{
			if(b[j]==b[i])break;
			vis[b[j]]=1;
		}
		int cnt=0;
		for(int j=1;j<=n;j++)cnt+=vis[j];
		ans+=1ll*w[b[i]]*cnt;
	}
	cout<<ans;
	return 0;
}