#include <cstdio>
#include <cstring>
#include <algorithm>

template<typename T> bool ckmax(T& a, const T& b) {return b>a?a=b,1:0;}
template<typename T> bool ckmin(T& a, const T& b) {return b<a?a=b,1:0;}

const int MN = 55;
const int MJ = 30;
const int MK = 70;
const int INF = 0x3f3f3f3f;

char a[MN];
int dp[MN][MJ*2][MK*2];

void tryput(int i, int j, int k, int v)
{
	if(-MJ <= j && j < MJ && -MK <= k && k < MK)
		ckmin(dp[i][j+MJ][k+MK], v);
}

int main()
{
	scanf(" %s", a);
	int N=0;
	for(;a[N];++N) a[N]-='0';
	std::reverse(a, a+N);

	memset(dp, 0x3f, sizeof dp);
	dp[MN-1][MJ][MK+a[0]]=0;

	for(int i=MN-1;i>=1;--i)
	{
		char x=a[i];
		for(int j=-MJ;j<MJ;++j)
			for(int k=-MK;k<MK;++k)
				if(dp[i][j+MJ][k+MK]<INF)
				{
					//printf("%d %d %d %d\n", i, j, k, dp[i][j+MJ][k+MK]);
					for(int d=-6;d<=6;++d)
						tryput(i-1, -x+d*10, k+d, dp[i][j+MJ][k+MK]+(i+1)*std::abs(j+x-d));
				}
	}

	int f=INF;
	for(int j=0;j<MJ*2;++j)
		for(int k=0;k<MK*2;++k)
			if(dp[0][j][k]<INF)
			{
				ckmin(f, dp[0][j][k]+std::abs(j-MJ+k-MK));
				//printf("%d %d %d: %d\n", 0, j-MJ, k-MK, dp[0][j][k]);
			}
	printf("%d\n", f);

	return 0;
}