#include <cstdio>
#include <algorithm>
using namespace std;

int u, v, sz, Pos[30];
char s[30], ch[2][30];

int main()
{
	scanf("%s", s + 1);
	for (int i = 1; i <= 27; i ++)
	{
		if (!Pos[s[i] - 'A']) Pos[s[i] - 'A'] = i;
			else u = Pos[s[i] - 'A'], v = i;
	}
	if (u == v - 1)
		puts("Impossible");
	else
	{
		int delta = v - u - 1 >> 1, st = v - delta - 1;
		for (int i = 1, cnt = 0; i <= 27; i ++)
		{
			st = st == 27 ? 1 : st + 1;
			if (st == u) continue ;
			ch[sz][cnt ++] = s[st];
			if (cnt == 13) sz ++, cnt = 0;
		}
		reverse(ch[0], ch[0] + 13);
		printf("%s\n%s\n", ch[0], ch[1]);
	}
	
	return 0;
}