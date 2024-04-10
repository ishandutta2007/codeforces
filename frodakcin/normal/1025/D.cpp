#include <cstdio>
#include <bitset>

const int MN = 704;

int gcd(int a, int b){return a?gcd(b%a,a):b;}

int N, a[MN];
bool ok;
std::bitset<MN> dp[MN][MN], dpl[MN], dpr[MN], good[MN];

int main()
{
	scanf("%d", &N);
	for(int i=0;i<N;++i)
		scanf("%d", a+i);
	for(int i=0;i<N;++i)
		dpl[i][i]=1, dpr[i][i]=1;
	for(int i=0;i<N;++i)
		for(int j=0;j<N;++j)
			good[i][j]=gcd(a[i], a[j])>1;
	for(int s=1;s<=N;++s)
		for(int i=0,j;i+s<=N;++i)
		{
			j=i+s-1;
			dp[i][j] = dpr[i]&dpl[j];
			if(i && (dp[i][j]&good[i-1]).any()) dpl[j][i-1]=1;
			if(j+1<N && (dp[i][j]&good[j+1]).any()) dpr[i][j+1]=1;
		}
	for(int i=0;!ok&&i<N;++i)
		if(dp[0][N-1][i])
			ok=1;
	if(ok) printf("Yes\n");
	else printf("No\n");
	return 0;
}