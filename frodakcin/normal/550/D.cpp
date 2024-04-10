#include <cstdio>
#include <cassert>
#include <vector>

int K, X;
std::vector<int> x;
std::vector<std::vector<int> > y;
struct edge
{
	public:
		int u,v;
};
std::vector<edge> fin;
void adde(int u, int v){fin.push_back({u,v});}

int main()
{
	scanf("%d", &K);
	if(K%2==0) return printf("NO\n"), 0;
	//if(K==1) return printf("YES\n1\n2 1\n1 2\n"), 0;
	int h=++X;
	for(int i=1;i<K;++i)
	{
		x.push_back(++X);
		adde(h, x.back());
		y.push_back(std::vector<int>());
		for(int i=1;i<K;++i)
		{
			y.back().push_back(++X);
			adde(x.back(), y.back().back());
		}
		for(int u:y.back())
			for(int v:y.back())
				if(u<v) adde(u,v);
	}
	for(int i=0;i+1<K;i+=2)
		for(int j=0;j+1<K;++j)
			adde(y[i][j], y[i+1][j]);

	x.clear();
	y.clear();
	adde(h, ++X);
	h=X;
	for(int i=1;i<K;++i)
	{
		x.push_back(++X);
		adde(h, x.back());
		y.push_back(std::vector<int>());
		for(int i=1;i<K;++i)
		{
			y.back().push_back(++X);
			adde(x.back(), y.back().back());
		}
		for(int u:y.back())
			for(int v:y.back())
				if(u<v) adde(u,v);
	}
	for(int i=0;i+1<K;i+=2)
		for(int j=0;j+1<K;++j)
			adde(y[i][j], y[i+1][j]);

	printf("YES\n");
	printf("%d %u\n", X, fin.size());
	assert(X*K == fin.size()*2);
	for(auto x:fin) printf("%d %d\n", x.u, x.v);
	return 0;
}