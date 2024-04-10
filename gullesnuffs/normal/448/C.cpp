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
#include <cassert>
using namespace std;

int h[5005];
int a[5005];
int dp[5005][5005];
int hpos[5005];

int main(){
	int n;
	scanf("%d", &n);
	for(int i=0; i < n; ++i){
		scanf("%d", a+i);
		h[i]=a[i];
	}
	h[n]=0;
	sort(h, h+(n+1));
	for(int i=0; i <= n; ++i)
		for(int j=0; j <= n; ++j)
			dp[i][j]=999999;
	dp[0][0]=0;
	for(int i=0; i < n; ++i)
		for(int j=0; j <= n; ++j)
			if(a[i] == h[j])
				hpos[i] = j;
	for(int i=0; i < n; ++i){
		for(int j=0; j <= n; ++j){
			if(h[j] < a[i]){
				dp[i+1][j]=min(dp[i+1][j], dp[i][j]+1);
			}
			else{
				if(h[j] == a[i]){
					dp[i+1][j]=min(dp[i+1][j], dp[i][j]);
					if(!j || h[j-1] != h[j]){
						for(int k=0; k < j; ++k){
							dp[i+1][j]=min(dp[i+1][j], dp[i][k]+h[j]-h[k]);
						}
					}
				}
				dp[i+1][hpos[i]]=min(dp[i+1][hpos[i]], dp[i][j]);
			}/*
			int Min=min(h[j], a[i]);
			int Max=max(h[j], a[i]);
			dp[i+1][Min]=min(dp[i+1][Min], dp[i][j]+(a[i] > h[j]));
			if(h[j] < Max)
				dp[i+1][Max]=min(dp[i+1][Max], dp[i][j]+(Max-h[j]));*/
		}
	}
	int ans=999999;
	for(int i=0; i <= n; ++i)
		ans=min(ans, dp[n][i]);
	printf("%d\n", ans);
	return 0;
}