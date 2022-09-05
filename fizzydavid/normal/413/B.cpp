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
int n,m,k,cnt[11],ans[21111];
bool a[21111][11];
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			int tmp;
			scanf("%d",&tmp);
			a[i][j]=(bool)tmp;
		}
	}
	for(int i=1;i<=k;i++)
	{
		int t1,t2;
		scanf("%d%d",&t1,&t2);
		cnt[t2]++;
		ans[t1]--;
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
	{
		if(a[i][j])ans[i]+=cnt[j];
	}
	for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
// 	system("pause");
	return 0;
}