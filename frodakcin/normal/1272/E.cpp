#include <cstdio>
#include <cstring>
#include <vector>

template<typename T> bool ckmin(T& a, const T& b) {return b<a?a=b,1:0;}

const int INF = 0x3f3f3f3f;

int N, a[201000];
int q[201000], Q;
int d[2][201000];
std::vector<int> b[201000];

int main()
{
	scanf("%d", &N);
	for(int i=0;i<N;++i)
	{
		scanf("%d", a+i);
		if(i-a[i]>=0)
			b[i-a[i]].push_back(i);
		if(i+a[i]<N)
			b[i+a[i]].push_back(i);
	}

	memset(d, 0x3f, sizeof d);
	//even
	{
		Q=0;
		for(int i=0;i<N;++i)
			if(~a[i]&1)
				q[Q++]=i, d[0][i]=0;
		for(int i=0,x;i<Q;++i)
		{
			x=q[i];
			for(int y:b[x])
				if(ckmin(d[0][y], d[0][x]+1))
					q[Q++]=y;
		}
	}
	//odd
	{
		Q=0;
		for(int i=0;i<N;++i)
			if(a[i]&1)
				q[Q++]=i, d[1][i]=0;
		for(int i=0,x;i<Q;++i)
		{
			x=q[i];
			for(int y:b[x])
				if(ckmin(d[1][y], d[1][x]+1))
					q[Q++]=y;
		}
	}
	for(int i=0;i<N;++i)
	{
		int x=d[~a[i]&1][i];
		printf("%d%c", x<INF?x:-1, " \n"[i+1==N]);
	}
	return 0;
}