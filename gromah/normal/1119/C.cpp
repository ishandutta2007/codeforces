#include <cstdio>
#include <algorithm>
using namespace std;
#define N 500 + 5

int n, m, A[N][N], B[N][N], R[N], C[N];
bool ok = true;

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m; j ++)
			scanf("%d", A[i] + j);
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m; j ++)
			scanf("%d", B[i] + j);
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m; j ++)
		{
			int t = A[i][j] ^ B[i][j];
			R[i] ^= t, C[j] ^= t;
		}
	for (int i = 1; ok && i <= n; i ++)
		ok = !R[i];
	for (int j = 1; ok && j <= m; j ++)
		ok = !C[j];
	puts(ok ? "Yes" : "No");
	return 0;
}