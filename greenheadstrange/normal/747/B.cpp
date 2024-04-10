#include <iostream>
#include <cstdio>
#include <cstring>
#define maxn 260 
using namespace std;
char a[maxn];
char nd[4] = {'A', 'G', 'C', 'T'};
int th[4];
int main()
{
	int n;
	scanf("%d", &n);
	scanf("%s", a);
	memset(th, 0, sizeof(th));
	if(n % 4) 
	{
		printf("===");
		return 0;
	}
	for(int i = 0; i < n; i++)
		for(int j = 0; j < 4; j++)
			if(a[i] == nd[j])
				th[j]++;
	for(int i = 0; i < 4; i++)
		if(th[i] > n / 4) 
		{
			printf("===");
			return 0;	
		}
	for(int i = 0; i < n; i++)
	{
		if(a[i] != '?') continue;
		for(int j = 0; j < n; j++)
			if(th[j] < n / 4)
			{
				a[i] = nd[j];
				th[j]++;
				break;
			 } 
	}
	for(int i = 0; i < n; i++)
		printf("%c",a[i]);
	return 0;
}