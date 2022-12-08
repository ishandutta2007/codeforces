#include <cstdio>

const int MN = 3e2+10;
int N, M, a[MN][MN], T;
int main()
{
	scanf("%d", &T);
	for(;T--;)
	{
		scanf("%d%d", &N, &M);
		bool good=1;
		for(int i=0;i<N;++i)
			for(int j=0;j<M;++j)
			{
				scanf("%d", a[i]+j);
				int v=4;
				if(!i)--v;
				if(i+1==N)--v;
				if(!j)--v;
				if(j+1==M)--v;
				if(a[i][j]>v) good=0;
			}
		if(good)
		{
			printf("YES\n");
			for(int i=0;i<N;++i)
				for(int j=0;j<M;++j)
				{
					int v=4;
					if(!i)--v;
					if(i+1==N)--v;
					if(!j)--v;
					if(j+1==M)--v;
					printf("%d%c", v, " \n"[j+1==M]);
				}
		}
		else//impossible?
		{
			printf("NO\n");
		}
	}
	return 0;
}