#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

bool ckmin(auto& a, const auto& b) {return b<a?a=b,1:0;}

const int MN = 5e3+10;
const int INF = 0x3f3f3f3f;

int N, p[MN], pr[MN*2], a[MN], dp[MN];

struct range
{
	public:
		int r, v;
};
std::vector<range> jump[MN];

int c2(int v) {return v*(v-1)/2;}

void ins(int l, int r)
{
	//printf("%d <-> %d\n", l, r);
	int b=p[r]-p[l];
	int w=c2(r-l)+l*(r-l)-b;
	jump[l].push_back({r, a[l]?w-b:b-w});
}

int main()
{
	memset(pr, -1, sizeof pr);
	memset(dp, 0x3f, sizeof dp);
	scanf("%d", &N);
	pr[N]=0;
	for(int i=0, c=0;i<N;++i)
	{
		scanf("%d", a+i);
		c += 2*a[i]-1;
		//printf("%d: %d\n", i, c);
		p[i+1]=p[i];
		if(a[i])
			p[i+1] += i;
		if(pr[c+N]!=-1)
			ins(pr[c+N], i+1);
		pr[c+N]=i+1;
	}

	dp[0]=0;
	for(int i=0;i<N;++i)
	{
		for(auto x:jump[i])
			ckmin(dp[x.r], dp[i]+x.v);
		if(!a[i])
			ckmin(dp[i+1], dp[i]);
		//printf("%d: %d\n", i, dp[i]);
	}
	printf("%d\n", dp[N]);
	return 0;
}