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
int n,m,ans[5111][2],a[5111];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		ans[i][0]=ans[i][1]=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(ans[i][0]!=ans[j][1]&&ans[i][1]!=ans[j][0]&&(ans[i][0]==ans[i][1]||ans[j][0]==ans[j][1]))
			{
				swap(ans[j][1],ans[i][1]);
			}
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++)if(ans[i][0]!=ans[i][1])cnt++;
	printf("%d\n",cnt);
	for(int i=1;i<=n;i++)printf("%d %d\n",ans[i][0],ans[i][1]);
// 	system("pause");
	return 0;
}