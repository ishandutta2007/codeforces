#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
	int x1, y1, x2, y2;
	int a, b;
	scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
	scanf("%d%d", &a, &b);
	int ns1 = abs(y2 - y1) / b, ns2 = (x2 - x1) / a;
	if((y2 - y1) % b) puts("NO\n");
	else if((x2 - x1) % a) puts("NO\n");
	else if((ns1 + ns2) & 1) puts("NO\n");
	else puts("YES\n");
	return 0;
 }