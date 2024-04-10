#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>

const int MN = 2e5 + 100;

std::vector<std::vector<int> > ans;
int a[MN], b[MN], c[MN], N, K;
int bsearch(int sz)
{
	int l = -1, r = ans.size(), m;
	for(;r-l>1;)
	{
		m = l+(r-l)/2;
		if(ans[m].size() < sz)
			r = m;
		else l = m;
	}
	return r;
}
int main(void)
{
	scanf("%d%d", &N, &K);
	for(int i = 0;i < N;++i)
		scanf(" %d", a+i);
	for(int i =0;i < N;++i)
		b[i] = i;
	std::sort(b, b+N, [](int x, int y){return a[x]>a[y];});
	for(int i = 1;i <= K;++i)
		scanf("%d", c+i);
	int j = 0, k;
	for(int i = K;i >= 1;--i)
	{
		for(k=j;k < N && a[b[k]] == i;++k);
		if(j == k)
			continue;
		int id = bsearch(c[i]);
		for(;j < k;++j)
		{
			if(id == ans.size())
				ans.push_back(std::vector<int>(0));
			ans[id].push_back(b[j]);
			if(ans[id].size() == c[i])
				++id;
		}
	}
	printf("%u\n", ans.size());
	for(auto x : ans)
	{
		printf("%d", x.size());
		for(auto y : x)
			printf(" %d", a[y]);
		printf("\n");
	}
	return 0;
}