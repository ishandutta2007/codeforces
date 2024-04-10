#include<bits/stdc++.h>
using namespace std;
#define N 40
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
int T,n,dp[N][N];
char s[N];
bool Solve(int l,int r){
	if(~dp[l][r])return dp[l][r];
	if(l==r){
		return dp[l][r]=s[l]=='a';
	}
	return dp[l][r]=(Solve(l+1,r)&&s[l]=='a'+r-l)|(Solve(l,r-1)&&s[r]=='a'+r-l);
}
void Solve(){
	memset(dp,-1,sizeof(dp));
	scanf("%s",s+1);
	n=strlen(s+1);
	printf(Solve(1,n)?"YES\n":"NO\n");
}
int main(){
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}