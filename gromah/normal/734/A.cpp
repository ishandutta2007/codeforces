#include <cstdio>
#include <algorithm>
using namespace std;
#define N 100000 + 5

int n, del = 0;
char s[N];

int main()
{
	scanf("%d", &n);
	scanf("%s", s);
	for (int i = 0; i < n; i ++)
		del += (s[i] == 'A') ? 1 : -1;
	if (del > 0) puts("Anton");
	else if (del < 0) puts("Danik");
	else puts("Friendship");
	return 0;
}