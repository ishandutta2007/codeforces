#include<bits/stdc++.h>
using namespace std;
const int N=5010;
#define x second
#define t first
pair<int,int> v[N];
long long mi[N];
int dp[N][N];
int main() {
	memset(mi,0x3f,sizeof(mi));
	mi[0]=0;
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&v[i].t,&v[i].x);
	sort(v+1,v+n+1);
	for(int i=0;i<n;i++) {
		if(mi[i]<=v[i].t) {
			mi[i+1]=min(mi[i+1],max(mi[i]+abs(v[i+1].x-v[i].x),1ll*v[i].t));
			for(int j=i+2;j<=n;j++)
				if(max(mi[i]+abs(v[j].x-v[i].x),1ll*v[i].t)+abs(v[j].x-v[i+1].x)<=v[i+1].t)
						dp[i+1][j]=1;
		}
		for(int j=i+2;j<=n;j++)
			if(v[i].t+abs(v[i+1].x-v[i].x)<=v[i+1].t)dp[i+1][j]|=dp[i][j];
		if(dp[i][i+1]) {
			mi[i+2]=min(mi[i+2],1ll*max(v[i].t+abs(v[i+2].x-v[i].x),v[i+1].t));
			for(int j=i+3;j<=n;j++) {
			if(max(v[i].t+abs(v[j].x-v[i].x),v[i+1].t)*1ll+abs(v[j].x-v[i+2].x)<=v[i+2].t)
					dp[i+2][j]=1;
			}
		}
	}
	if(mi[n]<=v[n].t||dp[n-1][n])puts("YES");
	else puts("NO");
	return 0;
}