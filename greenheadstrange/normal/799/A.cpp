#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n, t, k, d; 
int main()
{
	scanf("%d%d%d%d", &n, &t, &k, &d);
	int tm1 = n / k;
	if(tm1 * k < n) tm1++;
	tm1 *= t;
	int tm2 = 0;
	int ns1 = 0, ns2 = 0;
	int ns = 0;
	for(int i = 1; i <= tm1; i++)
	{
		ns1++;
		if(i > d) ns2++;
		if(ns1 >= t) ns += k, ns1 -= t;
		if(ns2 >= t && i > d) ns2 -= t, ns += k;
		if(i != tm1 && ns >= n)
		{
			puts("YES\n");
			return 0;
		}
	}
	puts("NO\n");
	return 0;
}