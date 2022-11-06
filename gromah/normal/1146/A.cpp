#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 50 + 5

int n, cnt;
char s[N];

int main()
{
	scanf("%s", s);
	n = strlen(s);
	for (int i = 0; i < n; i ++)
		cnt += s[i] == 'a';
	printf("%d\n", min(cnt * 2 - 1, n));
	return 0;
}