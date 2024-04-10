#include <cstdio>
#include <algorithm>
using namespace std;
#define N 300000 + 5

int Case, n, L[N][2], R[N][2];
char s[N];

int main()
{
	for (scanf("%d", &Case); Case; Case --)
	{
		scanf("%d", &n);
		scanf("%s", s);
		for (int i = 0; i <= n; i ++)
			for (int j = 0; j < 2; j ++)
				L[i][j] = (i == 0 || (s[i - 1] == 'L') != (j == 0)) ? 0 : L[i - 1][j ^ 1] + 1;
		for (int i = n; i >= 0; i --)
			for (int j = 0; j < 2; j ++)
				R[i][j] = (i == n || (s[i] == 'R') != (j == 0)) ? 0 : R[i + 1][j ^ 1] + 1;
		for (int i = 0; i <= n; i ++)
			printf("%d%c", L[i][0] + R[i][0] + 1, i == n ? '\n' : ' ');
	}
	return 0;
}