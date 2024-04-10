#include <cstdio>
#include <cassert>
#include <cstring>
#include <algorithm>
#include <vector>

template<typename T> bool ckmax(T& a, T b){return a<b?a=b,1:0;}
template<typename T> bool ckmin(T& a, T b){return b<a?a=b,1:0;}

const int MN = 80;
int N, K, T, dp[MN][MN], ans;
bool u[MN], pr[MN][MN];
struct minion
{
public:
	int a, b, id;
	void in(){scanf("%d%d", &a, &b);}
	bool operator < (minion o) const {return b < o.b;}
} a[MN];
std::vector<int> seq;
int main(void)
{
	scanf("%d", &T);
	for(;T--;)
	{
		scanf("%d%d", &N, &K);
		for(int i=0;i<N;++i)
			a[i].in(), a[i].id=i+1;
		std::sort(a, a+N);
		memset(dp, -1, sizeof dp);
		dp[0][0]=0;
		for(int i=0;i<N;++i)
			for(int j=0;j<=K;++j)
				if(~dp[i][j])
				{
					if(ckmax(dp[i+1][j], dp[i][j]+(K-1)*a[i].b))//this line changes
						pr[i+1][j]=0;
					if(j+1<=K&&ckmax(dp[i+1][j+1], dp[i][j]+a[i].a+j*a[i].b))
						pr[i+1][j+1]=1;
				}
		seq.clear();
		ans=dp[N][K];
		//printf("ANS: %d\n", ans);
		memset(u, 0, N*sizeof u[0]);
		int k=K;
		for(int i=N;i>0;--i)
		{
			if(pr[i][k])
				u[i-1]=1, seq.push_back(a[i-1].id), --k;
		}
		assert(!k);
		std::reverse(seq.begin(), seq.end());
		int v=seq.back();
		seq.pop_back();
		for(int i=0;i<N;++i)
			if(!u[i])
				seq.push_back(a[i].id), seq.push_back(-a[i].id);
		seq.push_back(v);

		printf("%d\n", seq.size());
		for(int i=0;i<seq.size();++i)
			printf("%d%c", seq[i], " \n"[i+1==seq.size()]);
	}
	return 0;
}