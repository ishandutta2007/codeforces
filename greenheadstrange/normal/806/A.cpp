#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
int cal(int a, int b)
{ // kb >= a
	if(a % b) return a / b + 1;
	return a / b;
}
int gcd(int a, int b)
{
	if(!b) return a;
	return gcd(b, a % b);
}
int main()
{
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; i++)
	{
		int x, y, p, q;
		scanf("%d%d%d%d", &x, &y, &p, &q);
		if(q && p) 
		{
			int gg = gcd(p, q);
			p /= gg, q /= gg;
		}
		if(p == q)
			if(x == y) printf("0\n");
			else printf("-1\n");
		else
			if(!p)
				if(!x) printf("0\n");
				else printf("-1\n");
			else
			{
				int k = max(cal(y, q), cal(x, p));
				k = max(k, cal(y - x, q - p));
				printf("%I64d\n", (long long)k * (long long)q - y);
			}
	}
	return 0;
 }