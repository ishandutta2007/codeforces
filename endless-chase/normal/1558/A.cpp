#include <bits/stdc++.h>
#define Accepted 0
using namespace std;
int test, a, b, x, y, cnt;
bool can[222222];
void doit(int x, int y)
{
	for (int i = 0; i <= min(a, x); i++) 
	{
		if (x - i <= b) can[a + x - (i << 1)] = 1;
	} 
}
int main()
{
	scanf("%d", &test);
	while(test--)
	{
		scanf("%d%d", &a, &b);
		for (int i = 0; i <= a + b; i++) can[i] = 0;
		x = (a + b + 1) / 2; y = a + b - x;
		doit(x, y);
		x = (a + b) / 2; y = a + b - x;
		doit(x, y);
		cnt = 0;
		for (int i = 0; i <= a + b; i++)
		{
			if (can[i]) cnt ++;
		}
		printf("%d\n", cnt);
		for (int i = 0; i <= a + b; i++)
		{
			if (can[i]) printf("%d ", i);
		}
		printf("\n");
	}
	return Accepted;
}