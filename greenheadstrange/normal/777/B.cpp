#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 1005 
using namespace std;
int a[maxn], b[maxn], n;
bool uses[maxn];
int ans = 0;
char inp[maxn];

int main()
{
	scanf("%d", &n);
	scanf("%s", inp);
	for(int j = 0; j < n; j++)
		a[j] = inp[j] - '0';
	scanf("%s", inp);
	for(int j = 0; j < n; j++)
		b[j] = inp[j] - '0';
	int mins = 0, maxs = 0;
	memset(uses, false, sizeof(uses));
	sort(a, a + n), sort(b, b + n);
	for(int i = 0; i < n; i++)
	{
		bool flag = false;
		for(int j = 0; j < n; j++)
		{
			if(uses[j]) continue;
			if(b[j] >= a[i])
			{
				flag = true, uses[j] = true;
				break;
			}
		}
		if(!flag)
		{
			mins++;
			for(int j = 0; j < n; j++)
				if(!uses[j]) 
				{
					uses[j] = true;
					break;
				}
		}
	}
	memset(uses, false, sizeof(uses));
	for(int i = 0; i < n; i++)
	{
		bool flag = false;
		for(int j = 0; j < n; j++)
		{
			if(uses[j]) continue;
			if(b[j] > a[i])
			{
				flag = true;
				uses[j] = true;
				break;
			}
		}
		maxs++;
		if(!flag)
		{
			maxs--;
			for(int j = 0; j < n; j++)
				if(!uses[j]) 
				{
					uses[j] = true;
					 break;
				}
		}
	}
	printf("%d\n%d", mins, maxs);
	return 0;
}