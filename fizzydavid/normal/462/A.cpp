//source:
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
int n;
bool vis[111][111];
int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin.ignore();
		for(int j=1;j<=n;j++)
		{
			char x;cin>>x;
			if(x=='o')vis[i][j]=1;
		}
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
	{
			int cnt=0;
			if(vis[i-1][j])cnt++;
			if(vis[i+1][j])cnt++;
			if(vis[i][j-1])cnt++;
			if(vis[i][j+1])cnt++;
			if(cnt&1)
			{
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	return 0;
}