#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
using namespace std;

char a[1000100], b[1000100];
int m, n;

int main()
{
	scanf("%s%s", a, b);
	m = strlen(a);
	n = strlen(b);
	
	if (m != n) puts("NO");
	else
	{
		if (n == 1) 
		{
			puts(a[0] == b[0] ? "YES" : "NO");
			return 0;
		}
		
		int oneA = 0, oneB = 0;
		for (int i = 0; i < n; i++)
		{
			oneA += a[i] == '1';
			oneB += b[i] == '1';
		}
		
		if (!oneA) puts(oneB ? "NO" : "YES");
		else puts(oneB ? "YES" : "NO");
	}
}