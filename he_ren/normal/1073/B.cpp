#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 2e5 + 5;

int a[MAXN],b[MAXN],vis[MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	for(int i=1; i<=n; ++i) scanf("%d",&b[i]);
	
	for(int i=1,now=1; i<=n; ++i)
	{
		if(vis[b[i]]){ printf("0 "); continue;}
		int cnt=0;
		do vis[a[now]]=1, ++cnt;
		while(a[now++]!=b[i]);
		printf("%d ",cnt);
	}
	return 0;
}