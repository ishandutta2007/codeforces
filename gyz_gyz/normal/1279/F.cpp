#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
using namespace std;
typedef long long ll;
const int N=1e6+10;
int n,k,L,a[N],dp[N],cnt[N];char s[N];
int cal(int m){dp[0]=0;
	rep(i,1,n){
		dp[i]=dp[i-1]+a[i];
		cnt[i]=cnt[i-1];
		if(dp[max(i-L,0)]+m<dp[i]){
			dp[i]=dp[max(i-L,0)]+m;
			cnt[i]=cnt[max(i-L,0)]+1;
		}
	}return cnt[n];
}
int sol(){
	int l=0,r=L,m=(l+r)>>1;
	for(;l<r;m=(l+r)>>1)if(cal(m)>k)l=m+1;else r=m;
	cal(m);return dp[n]-m*k;
}
int main(){
	scanf("%d%d%d",&n,&k,&L);
	scanf("%s",s+1);
	rep(i,1,n)if(s[i]>='A'&&s[i]<='Z')a[i]=1;else a[i]=0;
	int ans=sol();
	rep(i,1,n)a[i]^=1;
	ans=min(ans,sol());
	printf("%d\n",ans);
}