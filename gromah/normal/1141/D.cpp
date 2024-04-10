#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define N 150000 + 5

int n, ans, P[N][2];
char s[N];
vector <int> Vec[2][27];

int main()
{
	scanf("%d", &n);
	for (int t = 0; t < 2; t ++)
	{
		scanf("%s", s + 1);
		for (int i = 1; i <= n; i ++)
		{
			int j = s[i] == '?' ? 26 : s[i] - 'a';
			Vec[t][j].push_back(i);
		}
	}
	for (int i = 0; i < 26; i ++)
		for (; !Vec[0][i].empty() && !Vec[1][i].empty(); Vec[0][i].pop_back(), Vec[1][i].pop_back())
			ans ++, P[ans][0] = Vec[0][i].back(), P[ans][1] = Vec[1][i].back();
	for (int t = 0; t < 2; t ++)
		for (int j = 0; !Vec[t][26].empty() && j <= 26; j ++)
			for (; !Vec[t][26].empty() && !Vec[t ^ 1][j].empty(); Vec[t][26].pop_back(), Vec[t ^ 1][j].pop_back())
				ans ++, P[ans][t ^ 1] = Vec[t ^ 1][j].back(), P[ans][t] = Vec[t][26].back();
	printf("%d\n", ans);
	for (int i = 1; i <= ans; i ++)
		printf("%d %d\n", P[i][0], P[i][1]);
	return 0;
}