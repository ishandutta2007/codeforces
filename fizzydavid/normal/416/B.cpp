#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<ctime>
#include<utility>
#include<vector>
using namespace std;
#define y0 qgoiqoeinfoiqwef
#define y1 vmpoqmeppjofaqoi
#define yn qoigmnioqonfopiq
int m,n,t[51111][6],p[6];
int main()
{
	scanf("%d %d",&m,&n);
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&t[i][j]);
			p[j]+=t[i][j];
			for(int k=j+1;k<=n;k++)p[k]=max(p[k],p[j]);
		}
		printf("%d ",p[n]);
	}	
	return 0;
}