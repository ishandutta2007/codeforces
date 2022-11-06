#include <cstdio>
#include <algorithm>
using namespace std;

int n, m, s ;

int main()
{
	scanf("%d%d%d", &n, &m, &s);
	int t = min(min(n, m >> 1), s >> 2);
	printf("%d\n", t * 7);
	return 0;
}