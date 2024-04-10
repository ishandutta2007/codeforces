#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

const int MAXN = 100005;

struct Node
{
	int x,y,z,id;
	
	bool operator < (const Node &p)const
	{
		if (x == p.x)
		{
			if (y == p.y)
				return z < p.z;
			return y < p.y;
		}
		return x < p.x;
	}
}p[MAXN],S[MAXN];

int n,top;

int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
	{
		scanf("%d%d%d",&p[i].x,&p[i].y,&p[i].z);
		p[i].id = i;
	}
	sort(p + 1,p + n + 1);
	for (int i = 1;i <= n;i++)
	{
		if (top >= 1 && S[top].x == p[i].x && S[top].y == p[i].y)
		{
			printf("%d %d\n",S[top].id,p[i].id);
			top--;
			continue;
		}
		S[++top] = p[i];
	}
	n = top;
	for (int i = 1;i <= top;i++)
		p[i] = S[i];
	top = 0;
	for (int i = 1;i <= n;i++)
	{
		if (top >= 1 && S[top].x == p[i].x)
		{
			printf("%d %d\n",S[top].id,p[i].id);
			top--;
			continue;
		}
		S[++top] = p[i];
	}
	n = top;
	for (int i = 1;i <= top;i++)
		p[i] = S[i];
	for (int i = 1;i <= n;i += 2)
		printf("%d %d\n",p[i].id,p[i + 1].id);
	return 0;
}