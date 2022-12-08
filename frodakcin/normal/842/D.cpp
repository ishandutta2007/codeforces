#include <cstdio>
#include <vector>
#include <array>

using i2 = std::array<int, 2>;

int main()
{
	int N, M;
	scanf("%d%d", &N, &M);
	std::vector<int> a(N);
	for(int& x:a) scanf("%d", &x);
	std::vector<i2> c;
	std::vector<int> s; // sz

	c.push_back({-1,-1});
	for(int i=0;i<N;++i)
	{
		for(int j=18, n=0;j>=0;--j)
		{
			bool x=a[i]>>j&1;
			if(c[n][x] == -1) c[n][x]=c.size(), c.push_back({-1,-1});
			n=c[n][x];
		}
	}

	s.assign(c.size(), 1);
	for(int i=c.size()-1;i>=0;--i)
		if(c[i][0] != -1 || c[i][1] != -1)
		{
			s[i]=0;
			for(int k=0;k<2;++k)
				if(c[i][k] != -1)
					s[i] += s[c[i][k]];
		}

	int x=0;
	for(int i=0;i<M;++i)
	{
		int v; scanf("%d", &v);
		x^=v;
		int f=0;
		int n=0;
		for(int j=18;j>=0;--j)
		{
			if(n==-1) break;
			bool k = x>>j&1;
			if(c[n][k] != -1 && s[c[n][k]] == 1<<j)
				f |= 1<<j, n=c[n][!k];
			else
				n=c[n][k];
		}
		printf("%d\n", f);
	}
}