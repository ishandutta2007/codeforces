#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 100 + 5

int len;
char s[N];
bool ok;

bool Check(char a, char b, char c)
{
	if (a > b) swap(a, b);
	if (b > c) swap(b, c);
	if (a > b) swap(a, b);
	return a == 'A' && b == 'B' && c == 'C';
}

int main()
{
	scanf("%s", s);
	len = strlen(s);
	for (int i = 1; !ok && i < len - 1; i ++)
		if (Check(s[i - 1], s[i], s[i + 1]))
			ok = 1;
	puts(ok ? "Yes" : "No");
	return 0;
}