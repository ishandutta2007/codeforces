#include <cstdio>
#include <algorithm>

const int MN=1e5+10;
int T, N, K, a[MN], v;
bool e, f;

int main(void)
{
	scanf("%d", &T);
	for(;T--;)
	{
		scanf("%d%d", &N, &K);
		for(int i=0;i<N;++i)
			scanf("%d", a+i);
		if(N==1)
		{
			if(a[0]==K) printf("yes\n");
			else printf("no\n");
		}
		else if(N==2)
		{
			if((a[0]==K||a[1]==K)&&(a[0]>=K)&&(a[1]>=K))
				printf("yes\n");
			else
				printf("no\n");
		}
		else
		{
			e=0;
			for(int i=0;i<N;++i)
				if(a[i]==K)
					e=1;
			if(!e)
				printf("no\n");
			else
			{
				f=0;
				for(int i=0;!f&&i+3<=N;++i)
					if((a[i]>=K)+(a[i+1]>=K)+(a[i+2]>=K)>=2)
						f=1;
				if(f) printf("yes\n");
				else printf("no\n");
			}
		}
	}
	return 0;
}