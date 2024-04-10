#include <cstdio>

const int MN = 2e5+10;

int a[MN], T, N;

int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &N);
		for(int i=0;i<N;++i)
			scanf("%d", a+i);
		bool ok=0;
		for(int i=1;i<N;++i)
			if(a[i]!=a[i-1])
				ok=1;
		if(ok)
			printf("1\n");
		else
			printf("%d\n", N);
	}
	return 0;
}