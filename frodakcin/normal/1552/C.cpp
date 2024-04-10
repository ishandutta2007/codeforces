#include <cstdio>
#include <cstring>
#include <vector>
#include <array>
#include <algorithm>

const int MN = 1e2+10;

int N, K;
bool ok[MN*2];
std::vector<std::array<int, 2> > c;

void solve()
{
	scanf("%d%d", &N, &K);
	for(int i=0;i<K;++i)
	{
		int x, y; scanf("%d%d", &x, &y);
		--x, --y;
		if(y<x) std::swap(x, y);
		ok[x]=ok[y]=1;
		c.push_back({x, y});
	}

	std::vector<int> a;
	for(int i=0;i<N*2;++i)
		if(!ok[i])
			a.push_back(i);
	std::sort(a.begin(), a.end());
	for(int i=0;i<a.size()/2;++i)
	{
		int x=a[i], y=a[i+a.size()/2];
		c.push_back({x, y});
	}

	memset(ok, 0, 2*N*sizeof*ok);
	int ans=0;
	for(int i=0;i<N;++i)
		for(int j=0;j<N;++j)
			if(i!=j)
				if(c[i][0]<c[j][0]&&c[j][0]<c[i][1]&&c[i][1]<c[j][1])
					++ans;
	printf("%d\n", ans);
	c.clear();
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T--) solve();
	return 0;
}