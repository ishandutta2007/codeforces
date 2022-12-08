#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

template<class T> bool mn(T& a, const T& b) {return b<a?a=b,1:0;}

using ll = long long;

const int INF = 1e9;
const int MN = 1e5 + 100;
const int MB = 60;
int N;
ll a[MN], b[MN];
vector<ll> o[2];
ll all[MB];
int dp[2][MN];
bool c;
int p[MN];
int get0(int a, int b) {return b-a-p[b]+p[a];}
int get1(int a, int b) {return p[b]-p[a];}

int main(void)
{
	for(int i =	1;i < MB;i++)
		all[i] = (1LL<<i)-1;
	scanf("%d", &N);
	for(int i = 0;i < N;i++)
		scanf("%lld", a+i);
	sort(a, a+N);
	for(int i = 0;i < N;i++)
		b[i] = a[N-1]-a[i];
	for(int i = 1;i <= N;i++)
		dp[c][i] = INF;
	dp[c][0] = 0;
	for(int i = 0;i < MB;i++, c=!c)
	{
		if(i)
		{
			for(int j = 0;j < N;j++)
				o[b[j]>>i-1&1].push_back(b[j]);
			for(int j = 0, k = 1;k >= 0;o[k--].clear())
				for(ll x : o[k])
					b[j++] = x;
		}
		for(int j = 0;j < N;j++)
			p[j+1] = p[j]+(b[j]>>i&1);
		for(int j = 0;j <= N;j++)
			dp[!c][j] = INF;
		for(int j = 0;j <= N;j++)
		{
			if(dp[c][j]<INF) mn(dp[!c][get1(0,j)], dp[c][j] + get0(0,j) + get1(j,N));
			if(dp[c][j]<INF) mn(dp[!c][j+get1(j,N)], dp[c][j] + get1(0,j) + get0(j,N));
		}
		//if(i <= 5) for(int j = 0;j <= N;j++) printf("%d%c", dp[!c][j], " \n"[j==N]);
	}
	printf("%d\n", dp[c][0]);
	return 0;
}