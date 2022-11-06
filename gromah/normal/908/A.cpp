#include <cstdio>
#include <algorithm>
using namespace std;
#define N 10000 + 5

int ans;
char s[N];

bool Check(char ch)
{
	if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return 1;
	if (ch == '1' || ch == '3' || ch == '5' || ch == '7' || ch == '9') return 1;
	return 0;
}

int main()
{
	scanf("%s", s);
	for (int i = 0; s[i]; i ++)
		ans += Check(s[i]);
	printf("%d\n", ans);
	return 0;
}