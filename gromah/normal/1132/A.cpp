#include <cstdio>
#include <algorithm>
using namespace std;

int a, b, c, d;

int main()
{
	scanf("%d%d%d%d", &a, &b, &c, &d);
	printf("%d\n", (a == d) && (!c || a));
	return 0;
}