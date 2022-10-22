// Problem: E. Chaotic Merge
// Contest: Codeforces - Educational Codeforces Round 106 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1499/problem/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
char s[100003],t[100003];
int dp[1003][1003][2];
const int p=998244353;
int F[1003],G[10003];
signed main()
{
    scanf("%s",s+1);
    scanf("%s",t+1);
    int n=strlen(s+1),m=strlen(t+1);
    int ans=0;
    F[1]=1;
    for(int i=2; i<=n; i++)
    {
    	if(s[i]!=s[i-1]) F[i]=F[i-1]+1;
    	else F[i]=1;
    }
    G[1]=1;
    for(int i=2; i<=m; i++) 
    {
    	if(t[i]!=t[i-1]) G[i]=G[i-1]+1;
    	else G[i]=1;
    }
    for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) 
    {
    	if(s[i]!=t[j]) dp[i][j][1]=F[i],dp[i][j][0]=G[j];
    	if(s[i]!=s[i-1]) (dp[i][j][0]+=dp[i-1][j][0])%=p;
    	if(s[i]!=t[j]) (dp[i][j][0]+=dp[i-1][j][1])%=p;
    	if(t[j]!=t[j-1]) (dp[i][j][1]+=dp[i][j-1][1])%=p;
    	if(t[j]!=s[i]) (dp[i][j][1]+=dp[i][j-1][0])%=p;
    	ans+=dp[i][j][0]+dp[i][j][1];
    	//printf("%lld\n",dp[i][j][0]+dp[i][j][1]);
    	ans%=p;
    }
    printf("%lld\n",ans);
	return 0;
}