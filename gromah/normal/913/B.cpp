#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define N 1000 + 5

int n, Deg[N], Cnt[N];
bool ok = 1;
vector <int> Vec[N];

void dfs(int x)
{
	Cnt[x] = 0;
	for (int i = 0; i < Vec[x].size(); i ++)
	{
		int d = Vec[x][i];
		Cnt[x] += (Vec[d].size() == 0);
		dfs(d);
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 2, x; i <= n; i ++)
	{
		scanf("%d", &x);
		Vec[x].push_back(i);
	}
	dfs(1);
	for (int i = 1; ok && i <= n; i ++)
		ok = (Vec[i].size() == 0 || Cnt[i] >= 3);
	puts(ok ? "Yes" : "No");
	return 0;
}