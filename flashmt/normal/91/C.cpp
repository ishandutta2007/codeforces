#include <iostream>
#include <algorithm>
#include <cstdio>
#define z 1000000009
using namespace std;

int n,d[100100],re;

int find(int x)
{
	if (d[x]!=x) d[x]=find(d[x]);
	return d[x];
}

int main()
{
	int m,x,y,xRoot,yRoot;
	cin >> n >> m;
	for (int i=1;i<=n;++i) d[i]=i;
	while (m--)
	{
		scanf("%d%d",&x,&y);
		xRoot=find(x);
		yRoot=find(y);
		if (xRoot==yRoot) re=(re*2+1)%z;
		else d[yRoot]=xRoot;
		printf("%d\n",re);
	}
	return 0;
}