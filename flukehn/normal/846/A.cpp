#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a),i##_end=(b);i<=i##_end;i++)
#define per(i,b,a) for(int i=(b),i##_st=(a);i>=i##_st;i--)
typedef long long ll;
inline int rd() {
	int x=0,c=0,f=1;
	for(; c<'0'||c>'9'; c=getchar())f=c!='-';
	for(; c>='0'&&c<='9'; c=getchar())x=x*10+c-'0';
	return f?x:-x;
}
int dp[111][2];
int main(){
	int n=rd(),ans=0,flag=0;
	rep(i,1,n){
		int x=rd();
		if(!x){
			if(!flag)ans++;
			else{
				dp[i][0]=dp[i-1][0]+1;
				dp[i][1]=max(dp[i-1][1],dp[i-1][0]);
			}
		}else{
			flag=1;
			dp[i][0]=dp[i-1][0];
			dp[i][1]=max(dp[i-1][1],dp[i-1][0])+1;
		}
	}
	printf("%d\n",ans+max(dp[n][0],dp[n][1]));
}