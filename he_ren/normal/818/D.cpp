#include<cstdio>
#include<cstring>
#include<vector>
const int MAXN = 1e5 + 5;
const int MAXA = 1e6 + 5;
using namespace std;

int c[MAXN];
int t[MAXA];
int can[MAXA];

int main(void)
{
	memset(can,1,sizeof(can));
	
	int n,a;
	scanf("%d%d",&n,&a);
	for(int i=1; i<=n; ++i) scanf("%d",&c[i]);
	
	for(int i=1; i<=n; ++i)
	{
		if(t[c[i]]<t[a]) can[c[i]]=0;
		++t[c[i]];
	}
	
	for(int i=1; i<MAXA; ++i)
		if(t[i]<t[a]) can[i]=0;
	can[a]=0;
	
	for(int i=1; i<MAXA; ++i)
		if(can[i])
		{
			printf("%d",i);
			return 0;
		}
	printf("-1");
	return 0;
}