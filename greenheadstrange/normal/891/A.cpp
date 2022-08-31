#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 2005
using namespace std;
int n; 
int a[maxn];
int gcd(int a, int b)
{
	if(!b) return a;
	return gcd(b, a % b);
}
int main() 
{
	scanf("%d", &n);
	int cnt = 0;
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		if(a[i] == 1) cnt++;
	}
	if(cnt) printf("%d\n", n - cnt);
	else
	{
		int l = maxn;
		for(int i = 1; i <= n; i++)
		{
			int ns = 0;
			for(int j = i; j <= n; j++)
			{
				ns = gcd(ns, a[j]);
				if(ns == 1)
					l = min(l, j - i + 1);
			}
		}
		if(l == maxn) printf("%d\n", -1);
		else printf("%d\n", n + l - 2);
	}
	return 0;
}