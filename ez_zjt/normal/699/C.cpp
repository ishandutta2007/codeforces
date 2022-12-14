#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 1010
using namespace std;

int n;
int a[MAXN],b[MAXN];
int f[MAXN][3];

int main()
{
	memset(a,0,sizeof a);
	memset(b,0,sizeof b);
	memset(f,0x77,sizeof f);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int t;
		scanf("%d",&t);
		if(t&1)
			a[i]=1;
		if(t&2)
			b[i]=1;
	}
	f[0][0]=f[0][1]=f[0][2]=0;
	for(int i=1;i<=n;i++)
	{
		f[i][0]=min(f[i][0],f[i-1][0]);
		f[i][0]=min(f[i][0],f[i-1][1]);
		f[i][0]=min(f[i][0],f[i-1][2]);

		if(a[i])
		{
			f[i][1]=min(f[i][1],f[i-1][2]);
			f[i][1]=min(f[i][1],f[i-1][0]);
		}

		if(b[i])
		{
			f[i][2]=min(f[i][2],f[i-1][1]);
			f[i][2]=min(f[i][2],f[i-1][0]);
		}

		f[i][0]++;
	}
	int ans=0x77777777;
	for(int i=0;i<3;i++)
		ans=min(ans,f[n][i]);
	printf("%d\n", ans);
}