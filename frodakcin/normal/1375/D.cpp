#include <cstdio>
#include <cstring>
#include <cassert>
#include <vector>

const int MN = 1e3+10;

int T, N, a[MN];
bool u[MN];
std::vector<int> f;

int mex()
{
	memset(u, 0, (N+1)*sizeof*u);
	for(int i=0;i<N;++i)
		u[a[i]]=1;
	for(int i=0;i<=N;++i)
		if(!u[i]) return i;
	assert(0);
}
int mex2()
{
	memset(u+1, 0, N*sizeof*u);
	for(int i=0;i<N;++i)
		if(a[i]) u[a[i]]=1;
	for(int i=1;i<=N;++i)
		if(!u[i])
			return i;
	return N+1;
}
int main()
{
	scanf("%d", &T);
	for(;T--;)
	{
		scanf("%d", &N);
		for(int i=0;i<N;++i)
			scanf("%d", a+i);
		int m=0;
		for(;;)
		{
			while(m=mex())
			{
				a[m-1]=m;
				f.push_back(m-1);
			}
			bool g=1;
			for(int i=0;g&&i<N;++i)
				if(a[i]!=i+1)
					a[i]=m, f.push_back(i), g=0;
			if(g) break;
		}
		printf("%u\n", f.size());
		for(int i=0;i<f.size();++i) printf("%d%c", f[i]+1, " \n"[i+1==f.size()]);
		f.clear();
		//for(int i=0;i<N;++i) printf("%d%c", a[i], " \n"[i+1==N]);
	}
	return 0;
}