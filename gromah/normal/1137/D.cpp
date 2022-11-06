#include <cstdio>
#include <algorithm>
using namespace std;

bool Get(const char *t)
{
	int x, i;
	char s[11];
	bool ok = false;
	for (scanf("%d", &x); x; x --)
	{
		scanf("%s", s);
		for (i = 0; s[i] && t[i] && s[i] == t[i]; i ++) ;
		if (!s[i] && !t[i])
			ok = true;
	}
	return ok;
}

int main()
{
	do
	{
		puts("next 1 2 3 4");
		fflush(stdout);
		Get("");
		puts("next 1 2 3 4 5 6 7 8 9");
		fflush(stdout);
	} while (!Get("123456789"));
	do
	{
		puts("next 0 1 2 3 4 5 6 7 8 9");
		fflush(stdout);
	} while (!Get("0123456789"));
	puts("done");
	fflush(stdout);
	return 0;
}