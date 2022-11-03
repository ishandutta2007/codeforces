#include <bits/stdc++.h>
#define Accepted 0
using namespace std;
int test, c, d;
int main()
{
	scanf("%d", &test);
	while(test--)
	{
		scanf("%d%d", &c, &d);
		if ((c + d) & 1) printf("-1\n");
		else if (c == 0 && d == 0) printf("0\n");
		else if (c == d) printf("1\n");
		else printf("2\n");
	}
	return Accepted;
}