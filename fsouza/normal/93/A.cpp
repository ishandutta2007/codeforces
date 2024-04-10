#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int n, m, a, b;

	scanf("%d %d %d %d", &n, &m, &a, &b);
	a--, b--;

	int l1 = a/m, r1 = a%m;
	int l2 = b/m, r2 = b%m;

	if (b == n-1)
		r2 = m-1;

	if (l1 == l2)
		printf("1\n");
	else if (r1 == 0 && r2 == m-1)
		printf("1\n");
	else if (r1 == r2+1 || r1 == 0 || r2 == m-1 || l2 == l1+1)
		printf("2\n");
	else
		printf("3\n");

	return 0;
}