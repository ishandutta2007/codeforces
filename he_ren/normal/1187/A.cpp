#include<cstdio>

inline int max(int a,int b){ return a>b? a: b;}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,s,t;
		scanf("%d%d%d",&n,&s,&t);
		printf("%d\n",max(n-s,n-t) + 1);
	}
	return 0;
}