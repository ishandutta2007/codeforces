#include <cstdio>
#include <algorithm>

template<typename T> bool ckmax(T& a, const T& b) {return a<b?a=b,1:0;}
template<typename T> bool ckmin(T& a, const T& b) {return a>b?a=b,1:0;}

using ll = long long;

const int MN = 1e6+10;
const ll INF = 0x3f3f3f3f3f3f3f3f;

int N, r1, r2, r3, D, a[MN];
ll t[MN][2], dp[MN][3], ans=INF, cur;

int main()
{
	scanf("%d%d%d%d%d", &N, &r1, &r2, &r3, &D);
	for(int i=0;i<N;++i)
	{
		scanf("%d", a+i);
		t[i][0]=(ll)a[i]*std::min(r1, r3)+r3;//pistol + awp
		t[i][1]=(ll)a[i]*std::min(r1, r3)+std::min(r1*2, r3);//pistol/awp + pistol/awp
		ckmin(t[i][1], (ll)r2+std::min({r1, r2, r3}));
		//t[i][0] = visit exactly once
		//t[i][1] = visit twice (or once is okay too)
	}
	for(int i=0;i<N;++i)
	{
		dp[i+1][0]=t[i][0]+std::min(dp[i][0], dp[i][1]);
		dp[i+1][1]=t[i][1]+std::min(dp[i][1], dp[i][2])+D*2;
		dp[i+1][2]=t[i][1]+std::min(dp[i][0], dp[i][1]);
	}
	ans=std::min(dp[N][0], dp[N][1]);
	//printf("%lld\n", ans);

	ll off=std::min(t[N-1][0], t[N-1][1]+D*2);
	for(int i=N-2;i>=0;--i)
	{
		cur += D+t[i][1];
		ckmin(ans, cur+std::min(dp[i][0], dp[i][1])+off);
	}
	printf("%lld\n", ans+(ll)D*(N-1));
	return 0;
}