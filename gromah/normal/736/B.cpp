#include <cstdio>
#include <algorithm>
using namespace std;

int n;

inline bool Check(int x)
{
	for (int i = 2; i * i <= x; i ++)
		if (x % i == 0) return 0;
	return 1;
}

int main()
{
	scanf("%d", &n);
	if (Check(n)) puts("1");
	else if (n + 1 & 1) puts("2");
	else if (Check(n - 2)) puts("2");
	else puts("3");
	return 0;
}