#include <cstdio>

const int MN = 1e5+10;

int N;

int ask(int id)
{
	if(id == 0 || id == N+1) return MN;
	printf("? %d\n", id);
	fflush(stdout);
	int x;
	scanf("%d", &x);
	return x;
}

int main()
{
	scanf("%d", &N);
	int l=1,r=N;
	for(;l<=r;)
	{
		int m=l+(r-l)/2;
		int v=ask(m);
		if(ask(m-1)<v)
			r=m-1;
		else if(ask(m+1)<v)
			l=m+1;
		else
		{
			printf("! %d\n", m);
			break;
		}
	}
	return 0;
}