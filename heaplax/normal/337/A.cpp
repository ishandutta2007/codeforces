#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
using namespace std;
int n,m,f[51],ans=1000000;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)scanf("%d",&f[i]);
	sort(f+1,f+m+1);
	for(int i=1,j=i+n-1;j<=m;i++,j++)
		ans=min(ans,f[j]-f[i]);
	printf("%d\n",ans);
	return 0;
}