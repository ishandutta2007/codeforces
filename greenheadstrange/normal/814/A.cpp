#include <iostream>
#include <cstring>
#include <cstdio>
#define maxn 205
using namespace std;
int n, k;
int zrs = 0;
int a[maxn], b[maxn], zpl[maxn];
int main()
{
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		if(!a[i]) zpl[zrs++] = i;
	}
	for(int i = 1; i <= k; i++)
		scanf("%d", &b[i]);
	if(k < zrs) printf("NO\n");
	else
	{
		if(k >= 2) printf("YES\n");
		else 
		{
			a[zpl[0]] = b[1];
			bool flag = false;
			for(int i = n - 1; i >= 1; i--)
				if(a[i] >= a[i + 1]) flag = 1;
			if(flag) printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
 }