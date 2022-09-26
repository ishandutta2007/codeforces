#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <queue>
#include <map>

using namespace std;

const int MAXN = 100005;

int n,m,y1,y2,ans;
int a[MAXN];
int b[MAXN];

map<int,int> match;

int main()
{
	scanf("%d%d",&n,&y1);
	for (int i = 1;i <= n;i++)
		scanf("%d",&a[i]);
	scanf("%d%d",&m,&y2);
	for (int i = 1;i <= m;i++)
		scanf("%d",&b[i]);
	match.clear();
	for (int i = 1;i <= n;i++)
		match[a[i]]++;
	for (int i = 1;i <= m;i++)
		match[b[i]]++;
	for (map<int,int>::const_iterator j = match.begin();j != match.end();j++)
		ans = max(ans,(*j).second);	
	for (int i = 1;i <= 1000000000;i <<= 1)
	{
		match.clear();
		for (int j = 1;j <= n;j++)
			match[a[j] % (i << 1)]++;
		for (int j = 1;j <= m;j++)
			match[(b[j] + i) % (i << 1)]++;
		for (map<int,int>::const_iterator j = match.begin();j != match.end();j++)
			ans = max(ans,(*j).second);
	}
	printf("%d\n",ans);
	return 0;
}