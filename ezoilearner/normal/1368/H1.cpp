#include<bits/stdc++.h>
using namespace std;
 
#define cout cerr
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
 
typedef long long ll;
typedef pair<int,int> pii;
#define FR first
#define SE second
 
inline void rd(int &x){
    x=0;char ch=getchar();int f=1;
    while(ch<'0'||ch>'9'){
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    x*=f;
}

#define Maxn 100010
int n,m,q,ans,dp[Maxn][2];
char r1[Maxn],r2[Maxn],c1[Maxn],c2[Maxn];
inline int DP(){
	memset(dp,0,sizeof dp);
	rep(i,1,m)dp[1][0]+=(c1[i]!='R'),dp[1][1]+=(c1[i]!='B');
	dp[1][0]+=(r1[1]!='R')+(r2[1]!='R'),dp[1][1]+=(r1[1]!='B')+(r2[1]!='B');
	rep(i,2,n){
		dp[i][0]=min(dp[i-1][0],dp[i-1][1]+m)+(r1[i]!='R')+(r2[i]!='R');
		dp[i][1]=min(dp[i-1][0]+m,dp[i-1][1])+(r1[i]!='B')+(r2[i]!='B');
	}
	rep(i,1,m)dp[n][0]+=(c2[i]!='R'),dp[n][1]+=(c2[i]!='B');
	return min(dp[n][0],dp[n][1]);
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	scanf("%s%s%s%s",r1+1,r2+1,c1+1,c2+1);
	ans=DP();
	swap(n,m),swap(r1,c1),swap(r2,c2);
	return printf("%d\n",min(ans,DP())),0;
}