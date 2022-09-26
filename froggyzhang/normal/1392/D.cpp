#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 200020
const int inf=0x3f3f3f3f;
inline int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*f;
}
int T,n;
char s[N];
int calc(char *s){
	static int dp[N];
	dp[0]=0,dp[1]=inf;
	dp[2]=(s[1]!='R')+(s[2]!='L');
	dp[3]=(s[1]!='R')+(s[3]!='L');
	for(int i=4;i<=n;++i){
		dp[i]=min(dp[i-2]+(s[i-1]!='R')+(s[i]!='L'),dp[i-3]+(s[i-2]!='R')+(s[i]!='L'));
		dp[i]=min(dp[i],dp[i-4]+(s[i-3]!='R')+(s[i-2]!='R')+(s[i-1]!='L')+(s[i]!='L'));
	}
	return dp[n];
}
int Solve(){
	n=read();
	scanf("%s",s+1);
	int ans=calc(s);
	s[n+1]=s[1];
	for(int i=1;i<=n;++i){
		s[i]=s[i+1];
	}
	ans=min(ans,calc(s));
	s[n+1]=s[1];
	for(int i=1;i<=n;++i){
		s[i]=s[i+1];
	}
	ans=min(ans,calc(s));
	s[n+1]=s[1];
	for(int i=1;i<=n;++i){
		s[i]=s[i+1];
	}
	ans=min(ans,calc(s));
	return ans;
}
int main(){
	T=read();
	while(T--){
		printf("%d\n",Solve());
	}
	return 0;
}