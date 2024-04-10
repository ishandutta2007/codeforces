#include <iostream>
#include <cstdlib> 
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 500005
using namespace std;
// & 0 | 1 ^ 2
int tp[maxn], num[maxn];
int ans[2]; // | ^
int gt(int a, int b)
{
	return (a >> b) & 1;
}
int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		char inp[10];
		scanf("%s", inp);
		if(inp[0] == '&') tp[i] = 0;
		else if(inp[0] == '|') tp[i] = 1;
		else tp[i] = 2;
		scanf("%d", &num[i]);
	}
	for(int i = 0; i < 10; i++)
	{
		int ns[2];
		for(int j = 0; j < 2; j++)
		{
			ns[j] = j;
			for(int k = 1; k <= n; k++)
			{
				if(tp[k] == 0) ns[j] = ns[j] & gt(num[k], i);
				else if(tp[k] == 1) ns[j] = ns[j] | gt(num[k], i);
				else ns[j] = ns[j] ^ gt(num[k], i);
			}
		}	
		if(ns[0] == 0 && ns[1] == 0)
			ans[0] ^= (1 << i), ans[1] ^= (1 << i);
		else if(ns[0] == 1 && ns[1] == 1)
			ans[0] ^= (1 << i);
		else if(ns[0] == 1 && ns[1] == 0)
			ans[1] ^= (1 << i);
	}
	printf("2\n| %d\n^ %d\n", ans[0], ans[1]);
	return 0;
}