#include <cstdio>
#include <vector>

int N, M, a[200][200];
bool vu[200], hu[200];

std::vector<int> h, v;

int main()
{
	scanf("%d%d", &N, &M);
	for(int i=0;i<N;++i)
		for(int j=0;j<M;++j)
			scanf("%d", a[i]+j);
	for(bool ok=1;ok;)
	{
		ok=0;
		for(int i=0;!ok&&i<N;++i)
		{
			int sum=0;
			for(int j=0;j<M;++j)
				sum+=a[i][j];
			if(sum<0)
			{
				ok=1;
				for(int j=0;j<M;++j) a[i][j]*=-1;
				//v.push_back(i+1);
				vu[i]^=1;
			}
		}
		for(int i=0;!ok&&i<M;++i)
		{
			int sum=0;
			for(int j=0;j<N;++j)
				sum+=a[j][i];
			if(sum<0)
			{
				ok=1;
				for(int j=0;j<N;++j) a[j][i]*=-1;
				//h.push_back(i+1);
				hu[i]^=1;
			}
		}
	}
	for(int i=0;i<N;++i) if(vu[i]) v.push_back(i+1);
	for(int i=0;i<M;++i) if(hu[i]) h.push_back(i+1);
	printf("%u", v.size()); for(int x:v) printf(" %d", x);
	printf("\n");
	printf("%u", h.size()); for(int x:h) printf(" %d", x);
	printf("\n");
	return 0;
}