#include <cstdio>
#include <algorithm>
using namespace std;
#define N 19

int Prime[N] = {2, 3, 4, 5, 7, 9, 11, 13, 17, 19, 23, 25, 29, 31, 37, 41, 43, 47, 49};
int cnt = 0;
char s[5];

int main()
{
	for (int i = 0; i < N; i ++)
	{
		printf("%d\n", Prime[i]);
		fflush(stdout);
		scanf("%s", s);
		cnt += (s[0] == 'y');
	}
	if (cnt < 2) puts("prime");
	else puts("composite");
	return 0;
}