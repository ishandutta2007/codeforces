#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define N 300000 + 5

int n, q, tot, ans, Max;
bool Flag[N];
vector <int> Vec[N];

int main()
{
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= q; i ++)
	{
		int type, x;
		scanf("%d%d", &type, &x);
		if (type == 1)
		{
			Vec[x].push_back(++ tot);
			ans ++;
		}
		else if (type == 2)
		{
			for (int i = 0; i < Vec[x].size(); i ++)
			{
				int d = Vec[x][i];
				if (Flag[d]) continue ;
				Flag[d] = 1;
				ans --;
			}
			Vec[x].clear();
		}
		else
		{
			for (int i = Max + 1; i <= x; i ++)
			{
				if (Flag[i]) continue ;
				Flag[i] = 1;
				ans --;
			}
			Max = max(Max, x);
		}
		printf("%d\n", ans);
	}
	return 0;
}