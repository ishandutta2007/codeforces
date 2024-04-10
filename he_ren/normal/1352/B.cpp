#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;

void solve(void)
{
	int n,d;
	scanf("%d%d",&n,&d);
	if(n<d || (d%2==0 && n%2==1)){ printf("No\n"); return;}
	
	if(d%2==0)
	{
		printf("Yes\n");
		for(int i=1; i<d; ++i) printf("%d ",1);
		printf("%d\n",n-(d-1));
	}
	else
	{
		if(n%2==1)
		{
			printf("Yes\n");
			for(int i=1; i<d; ++i) printf("%d ",1);
			printf("%d\n",n-(d-1));
		}
		else
		{
			if(d*2 > n){ printf("No\n"); return;}
			printf("Yes\n");
			for(int i=1; i<d; ++i) printf("%d ",2);
			printf("%d\n",n-(d-1)*2);
		}
	}
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}