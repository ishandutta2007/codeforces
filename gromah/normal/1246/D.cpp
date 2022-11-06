#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define N 100000 + 5
#define M 1000000 + 5

int n, id, P[N], Dep[N], Size[N], Op[M], Max[N];
vector<int> Vec[N];

void dfs(int z)
{
	static int cnt = 0;
	if (z) putchar(' ');
	printf("%d", z);
	
	for (int i = 1; i <= cnt; i ++)
		Op[++ Op[0]] = z;
	
	cnt = 0;
	for (int d : Vec[z])
		if (d != Max[z])
			dfs(d);
	if (Max[z])
		dfs(Max[z]);
	cnt ++;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i < n; i ++)
	{
		scanf("%d", P + i);
		Vec[P[i]].push_back(i);
		Dep[i] = Dep[P[i]] + 1;
		if (Dep[i] > Dep[id])
			id = i;
	}
	for (int x = id; x; x = P[x])
		Max[P[x]] = x;
	dfs(0);
	puts("");
	printf("%d\n", Op[0]);
	for (int i = 1; i <= Op[0]; i ++)
	{
		if (i > 1) putchar(' ');
		printf("%d", Op[i]);
	}
	puts("");
	return 0;
}