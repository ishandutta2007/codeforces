#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef long long LL;
inline int	read()
{
	int x = 0; char ch = getchar(); bool positive = 1;
	for (; ch < '0' || ch > '9'; ch = getchar())	if (ch == '-')  positive = 0;
	for (; ch >= '0' && ch <= '9'; ch = getchar())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
#define link Link

int N, M, list[100005], next[100005], ans, fail[300005], change[300005][26];
char	buf[300005], t[300005], *s[100005];

void	DFS(int x, int p)
{
	for (char *ch = s[x]; ch != s[x + 1]; ++ ch)
	{
		p = change[p][*ch - 'a'];
		if (p == M)	++ ans;
	}
	for (int i = list[x]; i; i = next[i])
		DFS(i, p);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif

	N = read();
	s[0] = s[1] = s[2] = buf;
	for (int i = 2; i <= N; ++ i)
	{
		int x = read();
		next[i] = list[x], list[x] = i;
		scanf("%s", s[i]);
		s[i + 1] = s[i] + strlen(s[i]);
	}
	scanf("%s", t + 1);
	M = strlen(t + 1);
	for (int i = 1; i <= M; ++ i)	t[i] -= 'a';
	t[M + 1] = 26;
	fail[0] = fail[1] = 0;
	change[0][t[1]] = 1;
	for (int i = 1; i <= M; ++ i)
	{
		fail[i + 1] = change[fail[i]][t[i + 1]];
		for (int ch = 0; ch < 26; ++ ch)
			change[i][ch] = (ch == t[i + 1] ? i + 1 : change[fail[i]][ch]);
	}
	
	ans = 0;
	DFS(1, 0);
	cout << ans << endl;

	return 0;
}