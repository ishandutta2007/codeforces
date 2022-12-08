#include <cstdio>
#include <algorithm>

using namespace std;

using ll = long long;
#define tl(X) static_cast<ll>(X)
#define ti(X) static_cast<int>(X)

const int MOD = 998244353;
const int MN = 1e3 + 10;
const int MK = 1e3 + 10;
const int MV = 1e5 + 100;

int N, K;
int a[MN];
bool c;

ll p[MV+1000];
ll f;
int d[2][MN];
int sum(int a, int b) {int r=a+b; return r<MOD?r:r-MOD;}

int main(void)
{
	scanf("%d%d", &N, &K);
	for(int i = 0;i < N;i++)
		scanf("%d", a + i);
	sort(a, a + N);
	for(int i = 1;(i-1)*(K-1) <= MV;i++)
	{
		for(int j = 0;j <= N;j++)
			d[c][j] = j;
		for(int k = 1;k < K;k++, c=!c)
			for(int j = 0, x = 0;j < N;j++)
			{
				for(;a[j]-a[x]>=i;x++);
				d[!c][j+1] = sum(d[c][x], d[!c][j]);
			}
		p[i] = d[c][N];
		f += tl(p[i-1]-p[i]+MOD)*(i-1)%MOD;
	}
	printf("%d\n", ti(f%MOD));
	return 0;
}