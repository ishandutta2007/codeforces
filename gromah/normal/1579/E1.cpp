#include <cstdio>
#include <deque>
#include <algorithm>
using namespace std;
#define N 200000 + 5

int Case, n, A[N];
deque<int> Q;

int main()
{
	for (scanf("%d", &Case); Case; Case --)
	{
		scanf("%d", &n);
		Q.clear();
		for (int i = 1; i <= n; i ++)
		{
			scanf("%d", A + i);
			if (i == 1 || A[i] < Q.front())
				Q.push_front(A[i]);
			else Q.push_back(A[i]);
		}
		for (int i = 0; i < n; i ++)
			printf("%d%c", Q[i], i == n - 1 ? '\n' : ' ');
	}
	return 0;
}