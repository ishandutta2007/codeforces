#include <cstdio>
#include <algorithm>
#include <vector>

std::vector<long long> a;
int m;
char s[10];
long long ans=1e18;
void dfs(std::vector<long long>& x)
{
	if(x.size() ==1)
		ans = std::min(ans, x[0]);
	else
	{
		std::sort(x.begin(), x.end());
		int i = 4-x.size();
		do
		{
			std::vector<long long> y = x;
			if(s[i] == '*')
				y[0]*=y[1];
			else
				y[0]+=y[1];
			y.erase(y.begin()+1);
			dfs(y);
		}
		while (next_permutation(x.begin(), x.end()));
	}
}
int main(void)
{
	a.assign(4, -1);
	for(int i=0;i<4;++i)
		scanf("%lld", &a[i]);
	std::sort(a.begin(), a.begin()+4);
	for(int i=0;i<3;++i)
		scanf(" %c", s+i);
	dfs(a);
	printf("%lld\n", ans);
	return 0;
}