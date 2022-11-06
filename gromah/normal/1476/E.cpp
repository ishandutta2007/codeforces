#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
#define N 100000 + 5

int n, m, k, cnt, Ok[20], Deg[N], P[N];
vector<int> Go[N];
unordered_map<string, int> Map;
char s[9];

bool TopoSort()
{
	int l = 1, r = 0;
	for (int i = 1; i <= n; i ++)
		if (!Deg[i])
			P[++ r] = i;
	while (l <= r)
	{
		int z = P[l ++];
		for (int x : Go[z])
		{
			Deg[x] --;
			if (!Deg[x])
				P[++ r] = x;
		}
	}
	return r == n;
}

int main()
{
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i ++)
	{
		scanf("%s", s);
		Map.emplace(s, i);
	}
	for (int i = 1, x; i <= m; i ++)
	{
		scanf("%s%d", s, &x);
		string str = s;
		cnt = 0;
		for (int st = 0; st < (1 << k); st ++)
		{
			for (int j = 0; j < k; j ++)
				str[j] = (st >> j & 1) ? '_' : s[j];
			if (Map.count(str) != 0)
				Ok[++ cnt] = Map.at(str);
		}
		for (int i = 1; i <= cnt; i ++)
			if (Ok[i] == x)
				swap(Ok[1], Ok[i]);
		if (cnt == 0 || Ok[1] != x)
		{
			puts("NO");
			return 0;
		}
		for (int i = 2; i <= cnt; i ++)
		{
			Go[x].push_back(Ok[i]);
			Deg[Ok[i]] ++;
		}
	}
	if (!TopoSort())
		puts("NO");
	else
	{
		puts("YES");
		for (int i = 1; i <= n; i ++)
			printf("%d%c", P[i], i == n ? '\n' : ' ');
	}
	return 0;
}