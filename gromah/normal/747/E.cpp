#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
#define N 1000000 + 5
#define M 250000 + 5

int n, Max;
char s[N];
vector <char> Vec[M];

inline int getint(int u, int v)
{
	int res = 0;
	for (; u < v; u ++)
		res = res * 10 + s[u] - '0';
	return res;
}

inline int Next_comma(int st)
{
	for (; s[st] != ','; st ++) ;
	return st;
}

inline int dfs(int pos, int dep)
{
	Max = max(Max, dep);
	int x = Next_comma(pos);
	if (Vec[dep].size()) Vec[dep].push_back(' ');
	for (int i = pos; i < x; i ++)
		Vec[dep].push_back(s[i]);
	int y = Next_comma(x + 1);
	int sz = getint(x + 1, y ++);
	for (int i = 1; i <= sz; i ++)
		y = dfs(y, dep + 1);
	return y;
}

int main()
{
	scanf("%s", s);
	n = strlen(s);
	s[n ++] = ',';
	for (int i = 0; i < n; i = dfs(i, 1)) ;
	printf("%d\n", Max);
	for (int i = 1; i <= Max; i ++)
	{
		for (int j = 0; j < Vec[i].size(); j ++)
			printf("%c", Vec[i][j]);
		puts("");
	}
	return 0;
}