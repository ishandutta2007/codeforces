#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 2005
using namespace std;
int n;
int a[maxn];
int ans = 0;
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	int lst = 0;
	for(int i = 1; i <= n + 1; i++)
	{	// calc fr 
		int ncnt = 0;
		for(int j = 1; j < i; j++)
			if(a[j] == 1) ncnt++;
		for(int j = i; j <= n; j++)
			if(a[j] == 2) ncnt++;
		ans = max(ans, ncnt + lst);
		int ns = 0;
		int mx1 = 0, mx2 = 0;
		for(int j = i - 1; j >= 1; j--)
		{
			if(a[j] == 1) ns--;
			else ns++;
			mx1 = max(mx1, ns);
			lst = max(lst, ns);
		}
		ns = 0;
		for(int j = i; j <= n; j++)
		{
			if(a[j] == 1) ns++;
			else ns--;
			mx2 = max(mx2, ns);
		}
		ans = max(ans, ncnt + mx1 + mx2);
	}
	lst = 0;
	for(int i = n + 1; i >= 1; i--)
	{
		int ncnt = 0;
		for(int j = 1; j < i; j++)
			if(a[j] == 1) ncnt++;
		for(int j = i; j <= n; j++)
			if(a[j] == 2) ncnt++;
		ans = max(ans, ncnt + lst);
		int ns = 0, mx2 = 0;
		for(int j = i; j <= n; j++)
		{
			if(a[j] == 1) ns++;
			else ns--;
			mx2 = max(mx2, ns);
			lst = max(lst, mx2);
		}
	}
	printf("%d\n", ans);
	return 0;
 }