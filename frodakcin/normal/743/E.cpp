#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

template<typename T> bool ckmax(T& a, const T& b) {return b>a?a=b,1:0;}
template<typename T> bool ckmin(T& a, const T& b) {return b<a?a=b,1:0;}

const int MX = 8;
const int MN = 1e3+10;

int N, p[MN][MX], dp[MN][1<<MX]; // p is also lower bound
std::vector<int> loc[MX];

int check(int v)
{
	memset(dp, -1, sizeof dp);
	dp[0][0]=0;
	for(int i=0;i<N;++i)
		for(int j=0;j<1<<MX;++j)
			if(~dp[i][j])
				for(int k=0;k<MX;++k)
					if(~j>>k&1)
					{
						if(v<=1)
							ckmax(dp[i][j|1<<k], dp[i][j]);
						int x=p[i][k];
						for(int l=std::max(1, v-1);l<=v;++l)
							if(x+l-1<loc[k].size())
								ckmax(dp[loc[k][x+l-1]][j|1<<k], dp[i][j]+l);
					}
	int ans=-1;
	int all=(1<<MX)-1;
	for(int i=0;i<N;++i)
		ckmax(ans, dp[i][all]);
	return ans;
}

int main()
{
	scanf("%d", &N);
	std::vector<int> a(N);
	for(int& x:a) scanf("%d", &x), --x;

	for(int i=0;i<N;++i)
	{
		memcpy(p[i+1], p[i], sizeof*p);
		++p[i+1][a[i]];
		loc[a[i]].push_back(i);
	}

	int l=1, r=N; // l = ok

	for(;r-l>1;)
	{
		int m=l+(r-l)/2;
		if(check(m) == -1)
			r=m;
		else
			l=m;
	}

	int ans=0;
	for(int i=std::max(0, l-3);i<=l;++i)
		ckmax(ans, check(i));
	printf("%d\n", ans);
	return 0;
}