#include <cstdio>
#include <vector>
#include <algorithm>

const int MN = 20000;

std::vector<int> v, ok;
int N, K, L, a[MN], Q, num;
bool u[MN];

int main()
{
	scanf("%d%d", &N, &K);
	L=N/K;
	for(int i=0;i<N;++i)
		scanf("%d", a+i);
	scanf("%d", &Q);
	for(int i=0;i<Q;++i)
	{
		int sum=0;
		bool use=0;
		for(int j=0;j<L;++j)
		{
			int x;
			scanf("%d", &x), --x;
			if(u[x]) use=1;
			u[x]=1;
			sum += a[x];
		}
		if(!use) ++num;
		//printf("%d\n", sum);
		v.push_back(sum);
	}
	for(int i=0;i<N;++i)
		if(!u[i])
			ok.push_back(a[i]);
	if(num < K && (int)ok.size() >= L)
	{
		std::sort(ok.begin(), ok.end());
		int x=0, y=0;
		for(int i=0;i<L;++i)
			x += ok[i], y += ok[(int)ok.size()-i-1];
		v.push_back(x);
		v.push_back(y);
	}
	std::sort(v.begin(), v.end());
	printf("%.12lf %.12lf\n", (double)v[0]/L, (double)v.back()/L);
	return 0;
}