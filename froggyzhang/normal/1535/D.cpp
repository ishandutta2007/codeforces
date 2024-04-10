#include<bits/stdc++.h>
using namespace std;
#define N 533333
typedef long long ll;
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
int n,dp[N],Q;
char s[N];
#define ls u<<1
#define rs u<<1|1
void dfs(int u){
	if(u>=(1<<n)){
		dp[u]=1;
		return;	
	}	
	dfs(ls),dfs(rs);
	if(s[u]=='?')dp[u]=dp[ls]+dp[rs];
	else if(s[u]=='1')dp[u]=dp[ls];
	else dp[u]=dp[rs];
}
void Change(int u){
	if(s[u]=='?')dp[u]=dp[ls]+dp[rs];
	else if(s[u]=='1')dp[u]=dp[ls];
	else dp[u]=dp[rs];
	if(u==1)return;
	Change(u>>1);	
}
int main(){
	n=read();
	scanf("%s",s+1);
	reverse(s+1,s+(1<<n));
	dfs(1);
	Q=read();
	while(Q--){
		int x=(1<<n)-read();
		char c;
		do{c=getchar();}while(c!='?'&&c!='0'&&c!='1');
		s[x]=c;
		Change(x);
		printf("%d\n",dp[1]);
	}
	return 0;
}