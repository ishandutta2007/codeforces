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
int n,m,cost[1111];
int ans;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&cost[i]);
	for(int i=1;i<=m;i++)
	{
		int a,b;scanf("%d%d",&a,&b);
		ans+=min(cost[a],cost[b]);
	}
	cout<<ans;
//	system("pause");
	return 0;
}