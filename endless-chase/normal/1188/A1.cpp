#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int n,x,y,deg[111111];
vector<int> g[111111];
int main()
{
	scanf("%d",&n);
	for (int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
		deg[x]++;deg[y]++;
	}
	for (int i=1;i<=n;i++)
	{
		if (deg[i]==2)
		{
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	return Accepted;
}