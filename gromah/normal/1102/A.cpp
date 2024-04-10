#include <cstdio>
#include <algorithm>
using namespace std;

int n;

int main()
{
	scanf("%d", &n);
	printf("%d\n", (n % 4 == 3 || n % 4 == 0) ? 0 : 1);
	return 0;
}