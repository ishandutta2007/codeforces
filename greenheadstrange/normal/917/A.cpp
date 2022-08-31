#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#define maxn 5005
using namespace std;
char inp[maxn];
bool can[maxn][maxn];
int main()
{
	scanf("%s", inp);
	int n = strlen(inp);
	int ans = 0;
	for(int i = n - 1; i >= 0; i--)
	{
		int ncnt = 0;
		for(int j = i; j >= 0; j--)
		{
			if(inp[j] == '(') ncnt++;
			else ncnt--;
			if(ncnt > 0) 
				break;
			can[j][i] = 1;
		}
	}
	
	for(int i = 0; i < n; i++)
	{	
		int ncnt = 0;
		int nsum = 0;
		for(int j = i; j < n; j++)
		{
			if(inp[j] == '(') 
				ncnt++;
			if(inp[j] == ')')
				nsum--;
			else nsum++;
			if(nsum < 0) break;
			if((j - i) & 1)
				if(ncnt <= (j - i + 1) / 2 && can[i][j])
					ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}