#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef unsigned int uint;
const int MAXN = 1e5 + 5;
const int MAXM = 1e5 + 5;

vector<int> a[MAXM],sum[MAXM];
int tot[MAXN];

int main(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i)
	{
		int s,r;
		scanf("%d%d",&s,&r);
		a[s].push_back(r);
	}
	
	for(int i=1; i<=m; ++i)
		sort(a[i].begin(),a[i].end()),
		reverse(a[i].begin(),a[i].end());
	for(int i=1; i<=m; ++i)
	{
		if(!a[i].size()) continue;
		sum[i].push_back(a[i][0]);
		for(uint j=1; j<a[i].size(); ++j)
			sum[i].push_back(sum[i][j-1] + a[i][j]);
	}
	
	for(int i=1; i<=m; ++i)
		for(uint j=0; j<a[i].size(); ++j)
			if(sum[i][j]>0) tot[j+1]+=sum[i][j];
	
	int ans=0;
	for(int i=1; i<=n; ++i)
		if(ans<tot[i]) ans=tot[i];
	printf("%d",ans);
	return 0;
}