#include <cstdio>
#include <algorithm>
using namespace std;

int n, cur;

int Get(int &x)
{
	int s, i;
	for (s = i = 1; s + i + 1 <= x; i ++)
		s += i + 1;
	x -= s;
	return i;
}

int main()
{
	scanf("%d", &n);
	if (!n) puts("gromah");
	while (n)
	{
		int x = Get(n);
		for (int i = 1; i <= x + 1; i ++)
			printf("%c", 'a' + cur);
		cur ++;
	}
	return 0;
}