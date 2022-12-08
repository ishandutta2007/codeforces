#include <cstdio>
#include <algorithm>
#include <vector>

const int B = 1000;
const int L = 1000;
struct pt
{
public:
	int x,y,id;
	bool operator < (pt o) const 
	{
		return y < o.y;
	}
};
std::vector<pt> a[1010];
int N;
int main()
{
	scanf("%d", &N);
	for(int i=0;i<N;++i)
	{
		int x,y;
		scanf("%d%d", &x,&y);
		a[x/B].push_back({x, y, i+1});
	}
	for(int i=0;i<=L;++i)
	{
		std::sort(a[i].begin(), a[i].end());
		if(i&1)
			for(int j=0;j<a[i].size();++j)
				printf("%d ", a[i][j].id);
		else
			for(int j=a[i].size()-1;j>=0;--j)
				printf("%d ", a[i][j].id);
	}
	return 0;
}