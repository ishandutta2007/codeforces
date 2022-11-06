#include <cstdio>
#include <algorithm>
using namespace std;

char s[9][9];
bool ok;

int main()
{
	for (int i = 0; i <= 5; i ++)
	{
		scanf("%s", s[i]);
		if (i && (s[i][0] == s[0][0] || s[i][1] == s[0][1]))
			ok = 1;
	}
	puts(ok ? "YES" : "NO");
	return 0;
}