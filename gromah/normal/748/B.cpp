#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 1000 + 5

int len, cnt, Match[26];
char s[N], t[N];
bool ok = 1;

int main()
{
	scanf("%s%s", s, t);
	len = strlen(s);
	for (int i = 0; i < 26; i ++)
		Match[i] = -1;
	for (int i = 0; ok && i < len; i ++)
	{
		int u = s[i] - 'a', v = t[i] - 'a';
		if (~Match[u] && Match[u] != v || ~Match[v] && Match[v] != u)
			ok = 0;
		else Match[u] = v, Match[v] = u;
	}
	for (int i = 0; i < 26; i ++)
		if (~Match[i] && Match[i] > i) cnt ++;
	if (ok)
	{
		printf("%d\n", cnt);
		for (int i = 0; i < 26; i ++)
			if (~Match[i] && Match[i] > i)
				printf("%c %c\n", i + 'a', Match[i] + 'a');
	}
	else puts("-1");
	return 0;
}