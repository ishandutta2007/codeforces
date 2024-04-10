#include <cstdio>
#include <algorithm>
using namespace std;
#define N 100000 + 5

int Case, n, sum;

int main()
{
	scanf("%d", &Case);
	while (Case --)
	{
		scanf("%d", &n);
		if (n + 1 & 1) sum ++;
		if (sum & 1) puts("1");
		else puts("2");
	}
	return 0;
}