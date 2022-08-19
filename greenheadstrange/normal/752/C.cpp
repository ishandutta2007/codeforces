#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue> 
#define maxn 200005
using namespace std;
char move[maxn];
//0 up 1 right 2 down 3 left 
int n;
bool hv[4];
char mv[4] = {'U', 'R', 'D', 'L'};
int main()
{
	scanf("%d", &n);
	scanf("%s", move);
	memset(hv, false, sizeof(hv));
	int ans = 1;
	for(int i = 0; i < n; i++)
	{
		int mvs = 0;
		for(int j = 0; j < 4; j++)
			if(mv[j] == move[i])
				mvs = j;
		if(hv[(mvs + 2) % 4])
		{
			memset(hv, false, sizeof(hv));
			ans++;
		}
		hv[mvs] = true;
	}
	printf("%d\n", ans);
	return 0;
}