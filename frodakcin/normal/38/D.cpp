#include <cstdio>
#include <algorithm>

using ll = long long;

const int MN = 1e2+10;

int N, x1[MN], y1[MN], x2[MN], y2[MN];

int main()
{
	scanf("%d", &N);
	for(int i=0;i<N;++i) scanf("%d%d%d%d", x1+i, y1+i, x2+i, y2+i);
	for(int i=0;i<N;++i)
	{
		if(x2[i]<x1[i]) std::swap(x1[i], x2[i]);
		if(y2[i]<y1[i]) std::swap(y1[i], y2[i]);
	}
	for(int i=1;i<=N;++i)
	{
		bool ok=1;
		ll cx=0, cy=0, d=0;
		for(int j=i-1;j>=0;--j)
		{
			//printf("%d,%d: %.3lf %.3lf\n", i, j, (double)cx/d, (double)cy/d);
			if(d)
				if(cx < x1[j]*d || x2[j]*d < cx || cy < y1[j]*d || y2[j]*d < cy)
				{
					ok=0;
					break;
				}

			ll m=(x2[j]-x1[j]);
			m*=m*m;

			d += m*2;
			cx += m*(x2[j]+x1[j]);
			cy += m*(y1[j]+y2[j]);

		}
		if(!ok) return printf("%d\n", i-1), 0;
	}
	printf("%d\n", N);
	return 0;
}