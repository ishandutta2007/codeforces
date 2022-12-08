#include <cstdio>
#include <vector>
#include <algorithm>

const int MN = 2e5+10;
const int MK = 12;

int N, M, K, f;
struct Edge
{
	public:
		int n, w;
		bool operator < (const Edge& o) const {return w < o.w;}
};
struct Ord
{
	public:
		int i, k;
		bool operator < (const Ord& o) const {return k<o.k||!(o.k<k)&&i<o.i;}
		bool operator == (const Ord& o) const {return i==o.i&&k==o.k;}
};
std::vector<Edge> a[MN];
std::vector<Ord> b[MN];
std::vector<Ord> rules[MK][MK];
int ok[MK][MK];//ok = 0 means good

void brute(int k=1)
{
	if(k==K+1) return (void)(++f);
	for(int i=0;i<k;++i)
		if(ok[k][i]==0)
		{
			for(auto x:rules[k][i])
				++ok[x.k][x.i];
			brute(k+1);
			for(auto x:rules[k][i])
				--ok[x.k][x.i];
		}
}

int main()
{
	scanf("%d%d%d", &N, &M, &K);
	//for(int i=1;i<=K;++i) for(int j=0;j<i;++j) ok[i][j]=1;
	for(int i=0,u,v,w;i<M;++i)
		scanf("%d%d%d", &u, &v, &w), a[u].push_back({v, w});
	for(int i=1;i<=N;++i) std::sort(a[i].begin(), a[i].end());
	for(int i=1;i<=N;++i)
		for(int j=0;j<a[i].size();++j)
			b[a[i][j].n].push_back({j, (int)a[i].size()});
	for(int i=1;i<=N;++i)
	{
		std::sort(b[i].begin(), b[i].end());
		for(int j=0;j+1<b[i].size();++j)
			if(b[i][j]==b[i][j+1])
				ok[b[i][j].k][b[i][j].i]=1;
		b[i].resize(std::distance(b[i].begin(), std::unique(b[i].begin(), b[i].end())));
		for(int j=0;j<b[i].size();++j)
			for(int k=j+1;k<b[i].size();++k)
				if(b[i][j].k<b[i][k].k)
				{
					//add a rule
					rules[b[i][j].k][b[i][j].i].push_back(b[i][k]);
				}
	}
	for(int i=1;i<=K;++i) for(int j=0;j<i;++j)
	{
		std::sort(rules[i][j].begin(), rules[i][j].end());
		rules[i][j].resize(std::distance(rules[i][j].begin(), std::unique(rules[i][j].begin(), rules[i][j].end())));
	}
	//printf("HERE\n");
	brute();
	printf("%d\n", f);
	return 0;
}