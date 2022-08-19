#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#define maxn 105
using namespace std; 
char s[maxn];
int n, a, b; 
int mxs[5];
bool dfs(int a, int b, int c)
{
	if(!a)
	{
		if(b <= 0 && c <= 0) return 1;
		return 0;
	}
	for(int i = 0; i <= b; i++)	
		if(mxs[i] != -1)
			if(dfs(a - 1, b - i, c - mxs[i])) return 1;
	return 0;
}
int main()
{
	scanf("%d%d%d", &n, &a, &b);
	for(int i = 0; i < 5; i++)
		if(a * i <= n)
			mxs[i] = (n - i * a) / b;
		else mxs[i] = -1;
	for(int i = 1; i <= 6; i++)
		if(dfs(i, 4, 2)) 
		{
			printf("%d\n", i);
			return 0;
		}
	return 0;
}