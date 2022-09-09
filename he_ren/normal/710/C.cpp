#include<cstdio>
#include<cmath>
#include<algorithm>
const int MAXN = 49 + 5;
using namespace std;

int n,nn,m;
int used[MAXN*MAXN];

int dis(int i,int j){ return abs(nn-i)+abs(nn-j);}
inline void print(int k)
{
	for(; k<=m; k+=2)
	{
		if(!used[k])
		{
			used[k]=1;
			printf("%d ",k);
			return;
		}
	}
}

int main(void)
{
	scanf("%d",&n);
	m=n*n;
	nn=(n+1)>>1;
	
	for(int i=1; i<=n; ++i)
	{
		for(int j=1; j<=n; ++j)
		{
			if(dis(i,j)<nn)
				print(1);
			else
				print(2);
		}
		putchar('\n');
	}
	return 0;
}