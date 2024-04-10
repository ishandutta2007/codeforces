#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define maxn 100005
using namespace std;
int n; 
int a[maxn];
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	int m1 = 2147483647, m2 = 2147483647, m3 = 2147483647, s1 = 0, s2 = 0, s3 = 0;
	for(int i = 1; i <= n; i++)
		if(a[i] < m1) m3 = m2, s3 = s2, m2 = m1, s2 = s1, s1 = 1, m1 = a[i];
		else if(a[i] == m1) s1++;
		else if(a[i] < m2)
			m3 = m2, s3 = s2, m2 = a[i], s2 = 1;
		else if(a[i] == m2) s2++;
		else if(a[i] < m3) m3 = a[i], s3 = 1;
		else if(a[i] == m3) s3++;
	if(s1 >= 3)
		printf("%I64d\n",  (long long)s1 * (long long)(s1 - 1) * (long long)(s1 - 2) / 6);
	else if(s1 + s2 >= 3)
	{
		if(s1 == 2) printf("%I64d\n",  (long long)s1 * (long long)(s1 - 1) * (long long)s2 / 2);
		else printf("%I64d\n",  (long long)s1 * (long long)(s2 - 1) * (long long)s2 / 2);
	}
	else printf("%I64d\n", (long long)s1 * (long long)s2 * (long long)s3); 
	return 0;
 }