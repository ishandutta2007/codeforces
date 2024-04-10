#include <cstdio>
#include <algorithm>
#include <cassert>
#include <vector>
#include <numeric>

const int MN = 1e3+10;
int N, a[MN], ord[MN];
std::vector<int> q[MN];
struct swp
{
public:
	int x,y;
	void out()
	{
		printf("%d %d\n", x+1, y+1);
		//std::swap(a[x], a[y]);
	}
};
std::vector<swp> f;
int main()
{
	scanf("%d", &N);
	for(int i=0;i<N;++i)
		scanf("%d", a+i);
	std::iota(ord, ord+N, 0);
	std::sort(ord, ord+N, [](int x, int y){return a[x]<a[y]||!(a[y]<a[x])&&x<y;});
	for(int i=0;i<N;++i) a[ord[i]]=i;

	for(int i=0;i<N;++i)
		for(int j=i+1;j<N;++j)
			if(a[i]>a[j])
				q[i].push_back(j);

	//for(int i=0;i<N;++i) printf("%d%c", a[i], " \n"[i+1==N]);
	for(int i=0;i<N;++i)
	{
		std::sort(q[i].begin(), q[i].end(), [](int x, int y){return a[x]>a[y];});
		for(auto x:q[i])
			f.push_back({i, x}), std::swap(a[x], a[i]);//??
		//for(int i=0;i<N;++i) printf("%d%c", a[i], " \n"[i+1==N]);
	}
	printf("%u\n", f.size());
	for(int i=0;i<f.size();++i)
		f[i].out();
	for(int i=0;i+1<N;++i) assert(a[i]<=a[i+1]);//??
	return 0;
}