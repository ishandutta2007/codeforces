#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <vector>
#include <bitset>
#include <stack>
#include <queue>
#include <set>
#include <map>
 
using namespace std;

int n,r,tot;
int out[1000005];

pair<int,int> gcd(int a,int b)
{
	if (a < b)
		swap(a,b);
	if (!b)
		return make_pair(0,0);
	pair<int,int> r = gcd(a % b,b);
	r.first += a / b;
	r.second += max(0,a / b - 1 - (b == 1));
	return r;
}

void show(int a,int b)
{
	bool f = 0;
	while (b)
	{
		while (a >= b)
		{
			out[++tot] = f;
			a -= b;
		}
		swap(a,b);
		f ^= 1;
	}
	reverse(out + 1,out + tot + 1);
	out[1] ^= 1;
	for (int i = 1;i <= tot;i++)
		putchar(out[i] == out[1] ? 'T' : 'B');
	putchar('\n');
}

int main()
{
	scanf("%d%d",&n,&r);
	int ans = 1e9,p = 0;
	for (int i = 1;i <= r;i++)
	{
		if (__gcd(i,r) != 1)
			continue;
		pair<int,int> t = gcd(i,r);
		if (t.first == n && t.second < ans)
		{
			ans = t.second;
			p = i;
		}
	}
	if (ans != 1e9)
	{
		printf("%d\n",ans);
		show(r,p);
	}
	else
		puts("IMPOSSIBLE");
	return 0;
}