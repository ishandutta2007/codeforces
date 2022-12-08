#include <cstdio>
#include <cmath>
#include <algorithm>
#include <numeric>

template<typename T> bool ckmin(T& a, const T& b) {return b<a?a=b,1:0;}

const int INF = 1e9;
bool v[100][100];
int xc, yc, N, K, a;

int wt(int x, int y0, int y1)
{
	int f=0;
	for(int i=y0;i<=y1;++i)
	{
		if(v[x][i]) return INF;
		f += std::abs(x-xc)+std::abs(i-yc);
	}
	return f;
}

int main()
{
	scanf("%d%d", &N, &K);
	xc=K+1>>1, yc=xc;
	for(int i=0;i<N;++i)
	{
		scanf("%d", &a);
		--a;
		int x=-1, y0=-1, y1=-1, w=INF;
		for(int j=1;j<=K;++j)
		{
			for(int k=1;k+a<=K;++k)
				if(ckmin(w, wt(j, k, k+a)))
					x=j, y0=k, y1=k+a;
		}
		if(~x)
			std::fill(v[x]+y0, v[x]+y1+1, true), printf("%d %d %d\n", x, y0, y1);
		else
			printf("-1\n");
	}
	return 0;
}