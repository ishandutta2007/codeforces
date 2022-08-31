#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <algorithm>
#define maxn 5005
using namespace std;
int n;
int xr[2][maxn];
int ans[2][maxn];
int ns[2][maxn];
bool hv[maxn];
int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		printf("? %d %d\n", i, 0);
		fflush(stdout);
		scanf("%d", &xr[1][i]);
	}
	for(int i = 0; i < n; i++)
	{
		printf("? %d %d\n", 0, i);
		fflush(stdout);
		scanf("%d", &xr[0][i]);
	}
	int cnt = 0;
	for(int i = 0; i < n; i++)
	{
		ns[0][0] = i;
		for(int j = 0; j < n; j++)
			ns[1][j] = i ^ xr[0][j];
		for(int j = 0; j < n; j++)
			ns[0][j] = ns[1][0] ^ xr[1][j];
		bool flag = 1;
		memset(hv, 0, sizeof(hv));
		for(int j = 0; j < n; j++)
			if(ns[0][j] >= n || ns[0][j] < 0 || hv[ns[0][j]]) flag = 0;
			else hv[ns[0][j]] = 1;
		memset(hv, 0, sizeof(hv));
		for(int j = 0; j < n; j++)
			if(ns[1][j] >= n || ns[1][j] < 0 || hv[ns[1][j]]) flag = 0;
			else hv[ns[1][j]] = 1;
		if(!flag) continue;
		for(int j = 0; j < n; j++)
			if(ns[1][ns[0][j]] != j) flag = 0;//, cout<<"!"<<i<<" "<<j<<" "<<ns[0][j]<<" "<<ns[1][ns[0][j]]<<endl;
		if(flag)
		{
		//	cout<<"K"<<i<<endl;
			cnt++;
			for(int j = 0; j < n; j++)
				ans[0][j] = ns[0][j], ans[1][j] = ns[1][j];
		}
	}
	printf("!\n%d\n", cnt);
	for(int i = 0; i < n; i++)
		printf("%d ", ans[0][i]);
	printf("\n");
	fflush(stdout);
	return 0;
} 
/*
3
0
2
1
0
1
2
*/