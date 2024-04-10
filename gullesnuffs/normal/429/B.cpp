#include <cstdio>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <stack>
#include <iostream>
using namespace std;

int a[1005][1005];

int n, m;
int test[4][2]={{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
int dp[1005][1005][4];

bool inside(int i, int j){
	if(i < 0 || j < 0 || i >= n || j >= m)
		return 0;
	return 1;
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i=0; i < n; ++i)
		for(int j=0; j < m; ++j)
			scanf("%d", a[i]+j);
	for(int k=0; k < 4; ++k){
		for(int i=0; i < n; ++i)
			for(int j=0; j < m; ++j)
				dp[i][j][k]=0;
	}
	for(int k=0; k < 4; ++k){
		int i;
		if(k == 0 || k == 3)
			i=0;
		else
			i=n-1;
		while(true){
			int j;
			if(k < 2)
				j=0;
			else
				j=m-1;
			while(inside(i, j)){
				dp[i][j][k]=0;
				for(int t=0; t < 2; ++t){
					int u=(k+t)%4;
					int x=test[u][0]+i, y=test[u][1]+j;
					if(inside(x, y))
						dp[i][j][k]=max(dp[i][j][k], dp[x][y][k]);
				}
				dp[i][j][k] += a[i][j];
				if(k < 2)
					++j;
				else
					--j;
			}
			if(k == 0 || k == 3)
				++i;
			else
				--i;
			if(!inside(i, 0))
				break;
		}
	}
	int ans=0;
	for(int i=1; i < n-1; ++i)
		for(int j=1; j < m-1; ++j){
			for(int k=0; k < 2; ++k){
				int left, right;
				if(k == 0){
					left=inside(i-1, j)?dp[i-1][j][0]:0;
					left += inside(i, j-1)?dp[i][j-1][1]:0;
					right=inside(i+1, j)?dp[i+1][j][2]:0;
					right += inside(i, j+1)?dp[i][j+1][3]:0;
					ans=max(ans, left+right);
				}
				else{
					left=inside(i, j-1)?dp[i][j-1][0]:0;
					left += inside(i+1, j)?dp[i+1][j][1]:0;
					right=inside(i, j+1)?dp[i][j+1][2]:0;
					right += inside(i-1, j)?dp[i-1][j][3]:0;
					ans=max(ans, left+right);
				}
			}
		}
	printf("%d\n", ans);
	return 0;
}