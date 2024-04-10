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
int n,t,a[30111];
bool vis[30111];
vector<int>con[30111];
void dfs(int x)
{
	vis[x]=1;
	for(int i=0;i<con[x].size();i++)
	{
		if(!vis[con[x][i]])dfs(con[x][i]);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>t;
	for(int i=1;i<n;i++)
	{
		cin>>a[i];
		con[i].PB(i+a[i]);
	}
	dfs(1);
	if(vis[t])cout<<"YES";else cout<<"NO";
	return 0;
}