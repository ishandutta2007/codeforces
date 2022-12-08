#include <cstdio>
#include <algorithm>
#include <vector>

const int MN = 30;

using ll = long long;

const ll INF = 1e18+10;

int N, Q;
ll min[MN][MN], max[MN][MN], a[MN][MN];
std::vector<int> A, B;

int main()
{
	scanf("%d", &N);
	for(int i=1;i<=N;++i)
	{
		a[1][i]=1, a[i][N]=1;
		min[1][i]=max[1][i]=i;
		min[i][N]=max[i][N]=N+i-1;
	}
	for(int i=2;i<=N;++i)
	{
		a[i][1]=max[i-1][2]-min[i-1][1]+1;
		max[i][1]=max[i-1][1]+a[i][1];
		min[i][1]=min[i-1][1]+a[i][1];
		for(int j=2;j<N;++j)
		{
			a[i][j]=max[i-1][j+1]-std::min(min[i][j-1], min[i-1][j])+1;
			min[i][j]=a[i][j]+std::min(min[i-1][j], min[i][j-1]);
			max[i][j]=a[i][j]+std::max(max[i-1][j], max[i][j-1]);
		}
		max[i][N]=max[i][N-1]+a[i][N];
	}
	for(int i=1;i<=N;++i)
		for(int j=1;j<=N;++j)
			printf("%lld%c", a[i][j], " \n"[j==N]);
	fflush(stdout);
	scanf("%d", &Q);
	for(ll x;Q--;)
	{
		scanf("%lld", &x);
		int i=N, j=N;
		for(int k=0;k<N*2-2;++k)
		{
			A.push_back(i);
			B.push_back(j);
			x-=a[i][j];
			if(i > 1 && x <= max[i-1][j]) --i;
			else --j;
		}
		printf("1 1\n");
		for(int k=A.size()-1;k>=0;--k)
			printf("%d %d\n", A[k], B[k]);
		A.clear(); B.clear();
		fflush(stdout);
	}
	return 0;
}