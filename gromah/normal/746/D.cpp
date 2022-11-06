#include <cstdio>
#include <algorithm>
using namespace std;
#define N 100000 + 5

int n, k, a, b, T[2];
char Ans[N];

int main()
{
	scanf("%d%d%d%d", &n, &k, &a, &b);
	bool ok = 1;
	for (int i = 0; ok && i < n; i ++)
	{
		if (T[0] == k)
		{
			if (!b) ok = 0;
			else b --, T[0] = 0, T[1] = 1, Ans[i] = 'B';
		}
		else if (T[1] == k)
		{
			if (!a) ok = 0;
			else a --, T[0] = 1, T[1] = 0, Ans[i] = 'G';
		}
		else if (a > b)
		{
			a --, T[1] = 0, T[0] ++, Ans[i] = 'G';
		}
		else b --, T[1] ++, T[0] = 0, Ans[i] = 'B';
	}
	if (ok) printf("%s\n", Ans);
	else puts("NO");
	return 0;
}