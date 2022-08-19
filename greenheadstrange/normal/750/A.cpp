#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector> 
#define maxn 1000005
using namespace std;
int n, k; 
int main()
{
	scanf("%d%d", &n, &k);
	int mins = 240 - k;
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		if(mins >= i * 5)
		{
			mins -= i * 5;
			ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}