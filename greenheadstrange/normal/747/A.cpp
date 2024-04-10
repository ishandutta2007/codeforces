#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n;
	int a, b;
	scanf("%d", &n);
	for(int i = 1; i * i <= n; i++)
	{
		if(n % i) continue;
		a = i, b = n / i;
	}
	printf("%d %d\n", a, b);
	return 0;
}