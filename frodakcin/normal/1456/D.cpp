#include <cstdio>
#include <cstring>
#include <algorithm>

template<typename T> bool ckmax(T& a, const T& b) {return b>a?a=b,1:0;}
template<typename T> bool ckmin(T& a, const T& b) {return b<a?a=b,1:0;}

using ll = long long;

const int MN = 5e3+10;
const ll INF = 0x3f3f3f3f3f3f3f3f;

struct pt
{
	public:
		int t, x;
};

int N;
ll dp[MN][MN];
bool ans;
pt a[MN];

int main()
{
	scanf("%d", &N);
	a[0]={0,0};
	for(int i=1;i<=N;++i)
		scanf("%d%d", &a[i].t, &a[i].x);

	memset(dp, 0x3f, sizeof dp);
	dp[0][0]=0;
	for(int i=0;i<N;++i)
		for(int j=i;j<=N;++j)
			if(dp[i][j] <= a[i].t)
			{
				if(j==i)
				{
					ckmin(dp[i+1][i+1], std::max<ll>(dp[i][i]+std::abs(a[i].x-a[i+1].x), a[i].t));
					for(int k=i+2;k<=N;++k) // substitute k
						ckmin(dp[i+1][k], std::max<ll>(a[i].t, dp[i][i]+std::abs(a[i].x-a[k].x))+std::abs(a[k].x-a[i+1].x));
				}
				else
				{
					if(j==i+1)
					{
						if(i+2<=N)
						{
							ckmin(dp[i+2][i+2], std::max<ll>(a[i+1].t, (ll)a[i].t+std::abs(a[i].x-a[i+2].x))); // skip
							for(int k=i+3;k<=N;++k) // substitute k
								ckmin(dp[i+2][k], std::max<ll>(a[i+1].t, (ll)a[i].t+std::abs(a[i].x-a[k].x))+std::abs(a[k].x-a[i+2].x));
						}
					}
					else
						ckmin(dp[i+1][j], (ll)a[i].t+std::abs(a[i].x-a[i+1].x)); // no skip
				}
			}
	
	ans |= dp[N][N] <= a[N].t;
	ans |= dp[N-1][N] <= a[N-1].t;
	if(ans) printf("YES\n");
	else printf("NO\n");
	return 0;
}

/*
3
999999997 999999997
999999999 1000000000
1000000000 0

5
2 -1
5 1
6 0
7 2
8 -2
*/