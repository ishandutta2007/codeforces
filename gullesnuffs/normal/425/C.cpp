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

int a[100005], b[100005];
int dp[100005][305];
vector<int> pa[100005], pb[100005];

int main(){
	int n, m, s, e;
	scanf("%d%d%d%d", &n, &m, &s, &e);
	for(int i=0; i < n; ++i){
		scanf("%d", a+i);
		//pa[a[i]].push_back(i);
	}
	for(int i=0; i < m; ++i){
		scanf("%d", b+i);
		pb[b[i]].push_back(i);
	}
	for(int i=0; i <= n; ++i)
		for(int j=0; j < 303; ++j)
			dp[i][j]=1000000;
	dp[0][0] = -1;
	int ans=0;
	for(int i=0; i <= n; ++i)
		for(int j=0; j < 303; ++j){
			if(dp[i][j]+i+1+j*e <= s && dp[i][j] < 1000000)
				ans=max(ans, j);
			if(i == n)
				continue;
			int Min=-1, Max=pb[a[i]].size();
			while(Max-Min > 1){
				int test=(Max+Min)/2;
				if(pb[a[i]][test] > dp[i][j])
					Max=test;
				else
					Min=test;
			}
			if(Max < pb[a[i]].size()){
				dp[i+1][j+1]=min(dp[i+1][j+1], pb[a[i]][Max]);
			}
			dp[i+1][j]=min(dp[i+1][j], dp[i][j]);
		}
	printf("%d\n", ans);
	return 0;
}