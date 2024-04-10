#include <cstdio>
#include <algorithm>
using namespace std;

char s[9], t[9];

inline int Trans(char *ch)
{
	if (ch[0] == 'm') return 0;
	if (ch[0] == 't' && ch[1] == 'u') return 1;
	if (ch[0] == 'w') return 2;
	if (ch[0] == 't' && ch[1] == 'h') return 3;
	if (ch[0] == 'f') return 4;
	if (ch[0] == 's' && ch[1] == 'a') return 5;
	return 6;
}

int main()
{
	scanf("%s%s", s, t);
	int u = Trans(s), v = Trans(t);
	int tmp = (v + 7 - u) % 7;
	if (tmp == 0 || tmp == 2 || tmp == 3) puts("YES");
		else puts("NO");
	return 0;
}