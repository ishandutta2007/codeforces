#include <cstdio>
#include <algorithm>
using namespace std;
#define N 2000 + 5

int Case, n, A[N], Sum[N];
bool ok;

int main()
{
	for (scanf("%d", &Case); Case; Case--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", A + i);
			Sum[i] = Sum[i - 1] ^ A[i];
		}
		ok = false;
		for (int i = 1; i < n; i++)
			if (Sum[i] == (Sum[n] ^ Sum[i]))
				ok = true;
		for (int i = 1; i < n; i++)
			for (int j = i + 1; j < n; j++)
				if (Sum[i] == (Sum[i] ^ Sum[j]) && Sum[i] == (Sum[n] ^ Sum[j]))
					ok = true;
		puts(ok ? "YES" : "NO");
	}
	return 0;
}