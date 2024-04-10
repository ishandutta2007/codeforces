#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector> 
#define maxn 1000005
using namespace std;
int x, y;
int main()
{
	x = 10000;
	y = 10000;
	int n;
	scanf("%d", &n);
	bool flag = true;
	for(int i = 0; i < n; i++)
	{
		int t;
		scanf("%d", &t);
		char inp[10];
		scanf("%s", inp);
		if(x == 10000)
			if(inp[0] != 'S') flag = false;
		if(x == -10000)
			if(inp[0] != 'N') flag = false;
		if(inp[0] == 'N')
		{
			x += t;
			if(x > 10000) flag = false;
		}
		if(inp[0] == 'S')
		{
			x -= t;
			if(x < -10000) flag = false;
		}
		if(inp[0] == 'E')
			y += t;
		if(inp[0] == 'W')
			y -= t;
		y %= 20001;
		if(y <= 0) y += 20000;
	}
	if(x != 10000) flag = false;
	if(flag)
		printf("YES");
	else printf("NO");
	return 0;
}