#include <cstdio>
#include <vector>
#include <cassert>

using namespace std;

template<class T> bool mn(T& a, const T& b) {return b<a?a=b,1:0;}

const int INF = 200;
const int MN = 14;
int N, M, A;
vector<int> a[MN];

bool ex[MN][MN][1<<MN];
int exp[MN][MN][1<<MN];
int dp[1<<MN], dpp[1<<MN];

int main(void)
{
	scanf("%d%d", &N, &M);
	A = (1<<N)-1;
	for(int i = 0, u, v;i < M;i++)
		scanf("%d%d", &u, &v), a[--u].push_back(--v), a[v].push_back(u), ex[u][v][0] = ex[v][u][0] = 1;
	for(int m = 0;m < 1<<N;m++)
		for(int i = 0;i < N;i++)
			if(!(m&1<<i))
				for(int j = 0;j < N;j++)
					if(i!=j&&!(m&1<<j)&&ex[i][j][m])
						for(int x : a[j])
							if(!(m&1<<x)&&(m||x!=i))
								ex[i][x][m|1<<j] = 1, exp[i][x][m|1<<j] = j<<N|m;
	for(int i = 0;i < 1<<N;i++) dp[i] = INF;
	dp[1] = 0;
	for(int i = 1;i < A;i+=2)
		for(int j = A^i, *q=dp+A, v=dp[i]+__builtin_popcount(j)+1;j;j=(j-1)&(A^i), q=dp+(i|j), v=dp[i]+__builtin_popcount(j)+1)
			for(int k = 0;v < *q&&k < N;k++) if(i&1<<k)
				for(int l = k;v < *q&&l < N;l++) if(i&1<<l)
					if(ex[k][l][j])
						*q=v, dpp[i|j] = j|k*N+l<<N;
	assert(dp[A] < INF); printf("%d\n", dp[A]);
	for(int i = A, v, p, np, j, f;dp[i];i^=dpp[i]&A)
	{
		v=dpp[i];
		j = v&A, v>>=N;
		p = v%N, f = v/N, np = -1;
		for(;j;j = exp[f][p][j]&A, p=np)
			printf("%d %d\n", 1+p, 1+(np = exp[f][p][j]>>N));
		printf("%d %d\n", f+1, p+1);
	}
	return 0;
}