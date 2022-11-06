#include <cstdio>
#include <algorithm>
using namespace std;
#define N 100000 + 5

int n, A[N], Sum[N];

bool Check()
{
	bool ok = 1;
	for (int i = 1; ok && i <= n; i ++)
		ok = (A[i] == 1 || A[i - 1] == 1);
	if (ok) return 1;
	return 0;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i <= n; i ++)
	{
		scanf("%d", A + i);
		Sum[i] = A[i] + (i ? Sum[i - 1] : 0);
	}
	if (Check()) puts("perfect");
	else
	{
		printf("ambiguous");
		printf("\n0");
		for (int i = 1; i <= n; i ++)
			for (int j = 1; j <= A[i]; j ++)
				printf(" %d", Sum[i - 1]);
		printf("\n0");
		for (int i = 1; i <= n; i ++)
			for (int j = 1; j <= A[i]; j ++)
				printf(" %d", Sum[i - 1] - (A[i - 1] > 1 && j == A[i]));
		puts("");
	}
	return 0;
}