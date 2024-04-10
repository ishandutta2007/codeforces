#include<bits/stdc++.h>
using namespace std;
#define N 5005
typedef long long ll;
const ll inf=0x3f3f3f3f3f3f3f3fll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n;
ll dp[N][N],x[N],t[N];
inline ll Abs(ll x){
	return x>=0?x:-x;
}
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		t[i]=read(),x[i]=read();
	}
	memset(dp,0x3f,sizeof(dp));
	dp[0][0]=0;
	#define update(x,y) x=min(x,y)
	for(int i=0;i<n;++i){
		for(int j=0;j<=n;++j){
			if(dp[i][j]==inf)continue;
			if(!j){
				for(int k=i+2;k<=n;++k){
					if(Abs(x[k]-x[i])+Abs(x[k]-x[i+1])<=t[i+1]-dp[i][j]){
						update(dp[i+1][k],t[i+1]);
					}	
				}
				if(Abs(x[i]-x[i+1])<=t[i+1]-dp[i][j]){
					update(dp[i+1][i+1],dp[i][j]+Abs(x[i]-x[i+1]));
					update(dp[i+1][0],t[i+1]);
				}
			}
			else if(i==j){
				if(Abs(x[i]-x[i+1])<=t[i+1]-dp[i][j]){
					update(dp[i+1][0],t[i+1]);
					update(dp[i+1][i+1],max(dp[i][j]+Abs(x[i]-x[i+1]),t[i]));	
				}
				for(int k=i+2;k<=n;++k){
					if(max(t[i],dp[i][j]+Abs(x[i]-x[k]))+Abs(x[i+1]-x[k])<=t[i+1]){
						update(dp[i+1][k],t[i+1]);
					}	
				}
			}
			else if(i+1==j){
				if(i+1==n)return !printf("YES\n");
				for(int k=i+3;k<=n;++k){
					if(max(t[i+1],dp[i][j]+Abs(x[i]-x[k]))+Abs(x[i+2]-x[k])<=t[i+2]){
						update(dp[i+2][k],t[i+2]);
					}	
				}
				if(Abs(x[i]-x[i+2])<=t[i+2]-dp[i][j]){
					update(dp[i+2][i+2],max(t[i+1],dp[i][j]+Abs(x[i]-x[i+2])));
					update(dp[i+2][0],t[i+2]);
				}	
			}
			else{
				if(Abs(x[i]-x[i+1])<=t[i+1]-dp[i][j]){
					update(dp[i+1][j],t[i+1]);
				}	
			}
		}
	}
	for(int j=0;j<=n;++j){
		if(dp[n][j]<inf)return !printf("YES\n");
	}
	printf("NO\n");
	return 0;
}