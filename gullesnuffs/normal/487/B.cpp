#include <bits/stdc++.h>

using namespace std;

int n, s, l;
int a[100005];
int Min[100005][20];
int Max[100005][20];
int dp[100005][20];

int main(){
	cin >> n >> s >> l;
	for(int i=0; i < n; ++i)
		scanf("%d", a+i);
	for(int j=0; j < 20; ++j){
		for(int i=0; i + (1<<j) <= n; ++i){
			if(j == 0){
				Min[i][j]=a[i];
				Max[i][j]=a[i];
			}
			else{
				Min[i][j]=min(Min[i][j-1], Min[i+(1<<(j-1))][j-1]);
				Max[i][j]=max(Max[i][j-1], Max[i+(1<<(j-1))][j-1]);
			}
		}
	}
	for(int j=0; j < 20; ++j)
		for(int i=0; i < n; ++i)
			dp[i][j]=1000000;
	dp[0][0]=0;
	int ans=1000000;
	for(int i=0; i < n; ++i){
		int DP=1000000;
		int tmp=i;
		for(int j=0; j < 20; ++j){
			DP=min(DP, dp[tmp][j]);
			if(tmp&(1<<j))
				tmp^=(1<<j);
		}
		if(DP == 1000000)
			continue;
		int j=i;
		int lo=a[i], hi=a[i];
		for(int k=19; k >= 0; --k){
			if(j+(1<<k) <= n){
				int lonew=min(lo, Min[j][k]);
				int hinew=max(hi, Max[j][k]);
				if(hinew-lonew <= s){
					j += (1<<k);
					lo=lonew;
					hi=hinew;
				}
			}
		}
		int L=i+l, R=j;
		if(j == n && R >= L)
			ans=min(ans, DP+1);
		int k=0;
		while(R >= L){
			dp[L][k]=min(dp[L][k], DP+1);
			dp[R][k]=min(dp[R][k], DP+1);
			if(L&(1<<k))
				L += (1<<k);
			if(R&(1<<k))
				R -= (1<<k);
			else
				R -= (2<<k);
			++k;
		}
	}
	if(ans == 1000000)
		puts("-1");
	else
		printf("%d\n", ans);
}