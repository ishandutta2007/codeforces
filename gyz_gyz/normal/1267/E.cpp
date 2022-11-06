#include <bits/stdc++.h>
using namespace std;
const int maxn=110;

int a[maxn][maxn];
int b[maxn];
pair<int,int> I[maxn];
int n,m,ans,winner;

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	for (int j=1;j<=n;j++)
		scanf("%d",&a[i][j]);
	for (int i=1;i<=n-1;i++)
	{
		for (int j=1;j<=m;j++) b[j]=a[j][i]-a[j][n];
		sort(b+1,b+1+m);
		reverse(b+1,b+1+m);
		int sum=0,res=0;
		while (res<m && sum+b[res+1]>=0) sum+=b[++res];
		if (res>ans) ans=res,winner=i;
	}
	ans=m-ans;
	printf("%d\n",ans);
	for (int i=1;i<=m;i++) I[i].first=a[i][winner]-a[i][n],I[i].second=i;
	sort(I+1,I+1+m);
	for (int i=1;i<=ans;i++) printf("%d ",I[i].second);
	return 0;
}