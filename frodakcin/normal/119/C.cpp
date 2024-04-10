#include <cstdio>
#include <cstring>
#include <algorithm>
#include <array>
#include <vector>

template<typename T> bool ckmax(T& a, const T& b){return a<b?a=b,1:0;}

using ll = long long;

const int MN = 55, MD = 105;

int N, M, K;
struct Subj
{
	public:
		ll a;int d, c, id;
		bool operator < (const Subj& o) const
		{
			return c<o.c;
		}
} a[MN];

ll dp[MN][MN][MD];
int pr[MN][MN][MD];

std::vector<std::array<ll, 2> > f;
void ans(int n, int d)
{
	printf("YES\n");
	for(int i=N;i;--i)
	{
		int v=pr[i][n][d];
		f.push_back({a[n].id, a[n].a+d});
		n=(v>>8&0xff)-1;
		d=v&0xff;
	}
	std::reverse(f.begin(), f.end());
	for(auto x:f) printf("%lld %lld\n", x[0], x[1]);
}

int main()
{
	scanf("%d%d%d", &N, &M, &K);
	for(int i=0;i<M;++i)
	{
		ll a,b; int c;
		scanf("%lld%lld%d", &a, &b, &c);
		::a[i]={a,(int)(b-a),c,i+1};
	}
	std::sort(a, a+M);
	memset(dp, -1, sizeof dp);
	for(int i=0,j;i<M;i=j)
	{
		for(j=i;j<M&&a[i].c==a[j].c;++j)
		{
			if(i)
				for(int x=0;x<i;++x)
					for(int k=0;k<=a[x].d;++k)
						for(int v=1;v<N;++v)
							if(~dp[v][x][k])
							{
								ll nk;

								nk = (a[x].a+k)*K-a[j].a;
								if(0<=nk&&nk<=a[j].d)
									if(ckmax(dp[v+1][j][nk], dp[v][x][k]+nk+a[j].a))
										pr[v+1][j][nk]=x+1<<8|k;

								nk = (a[x].a+k)+K-a[j].a;
								if(0<=nk&&nk<=a[j].d)
									if(ckmax(dp[v+1][j][nk], dp[v][x][k]+nk+a[j].a))
										pr[v+1][j][nk]=x+1<<8|k;
							}
			for(int k=0;k<=a[j].d;++k)
				dp[1][j][k]=a[j].a+k, pr[1][j][k]=0;
		}
		//printf("%d %d\n", i, j);
	}
	int n=-1, d=-1;
	ll best=-1;
	for(int i=0;i<M;++i)
		for(int j=0;j<=a[i].d;++j)
			if(ckmax(best, dp[N][i][j]))
				n=i, d=j;
	if(~best)
		ans(n,d);
	else
		printf("NO\n");
	return 0;
}