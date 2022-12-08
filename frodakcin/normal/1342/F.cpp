#include <cstdio>
#include <cassert>
#include <cstring>
#include <vector>

template<class T> bool ckmax(T *a, T b) {return *a<b?*a=b,1:0;}
template<class T> bool ckmin(T *a, T b) {return b<*a?*a=b,1:0;}
const int MN = 15;
const int INF = 0x44444444;
int dp[MN][MN+1][1<<MN], g[MN][MN+1][1<<MN];
int N, a[MN], p[MN], sm[1<<MN];
int A, B;

int clz(int v) {return v ? __builtin_clz(v) : 32;}
struct action
{
public:
	int a, b;
};
std::vector<action> ans;
void solve()
{
	scanf("%d", &N);
	for(int i = 0;i < N;++i)
		scanf("%d", a+i), sm[1<<i] = a[i];
	for(int i = 0;i < 1<<N;++i)
		if(__builtin_popcount(i)>1)
		{
			int j = 31 - clz(i);
			sm[i] = sm[i^1<<j] + a[j];
			//printf("%x %d\n", i, sm[i]);
		}
	for(int i = 0;i <= N;++i)
		memset(dp[0][i], 0x44, sizeof(dp[0][0][0])*(1<<N));
	dp[0][0][0] = 0;
	for(int b = 0, mb;b < N;++b)
	{
		//printf("ON %d\n", b);
		if(b)
			for(int i = 0;i <= N;++i)
				memcpy(dp[b][i], dp[b-1][i], sizeof(dp[0][0][0])*(1<<N));
		mb = (1<<b+1)-1;
		for(int i = N-1;i >= 0;--i)
			for(int j = 1<<b;j < 1<<N;j = j+1|1<<b)
			{
				for(int sub = j^1<<b, k = sub;;k = k-1&sub)
				{
					int z = dp[b][i][j^k^1<<b];
					if(z>>4 < sm[k|1<<b])
						if(ckmin(dp[b][i+1]+j, sm[k|1<<b]<<4|b))
							g[b][i+1][j] = k<<4|z&0xf;
					if(!k) break;
				}
				//if(dp[b][i+1][j] < INF) printf("SUCCESS AT %d %d %d\n", b, i+1, j);
			}
	}
	A = -1;
	for(int i = N;i >= 0;--i)
		for(int j = 0;j < N;++j)
			if(dp[j][i][(1<<N)-1] < INF)
			{
				A = i, B = j;
				goto found;
			}
found:
	assert(~A);
	//printf("FOUND A,B: %d, %d\n", A, B);
	for(int m = (1<<N)-1, q;A > 0;--A)
	{
		std::vector<int> z(0);
		q = g[B][A][m];
		B = dp[B][A][m]&0xf;
		for(int i = 0;i < N;++i)
			if(q>>i+4&1)
				z.push_back(i);
		for(auto i : z)
			ans.push_back({i, B});
		m ^= q>>4 | 1<<B;
		B = q&0xf;
	}
	memset(p, 0, sizeof(p));
	printf("%u\n", ans.size());
	for(int i = 0;i < ans.size();++i)
	{
		//printf("(%d %d)", ans[i].a, ans[i].b);
		printf("%d %d\n", 1 + ans[i].a - p[ans[i].a], 1 + ans[i].b - p[ans[i].b]);
		for(int j = ans[i].a;j < N;++j)
			++p[j];
	}
	ans.clear();
}

int T;
int main(void)
{
	scanf("%d", &T);
	while(T--)
		solve();
	return 0;
}