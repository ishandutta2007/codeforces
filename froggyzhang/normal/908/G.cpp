#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 888
const int mod=1e9+7;
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
int n,a[N],ans;
char s[N];
int dp[N][N];
int dfs(int u,int tot,bool limit,int x){
	if(tot<0)return 0;
	if(u==n+1)return !tot;
	if(dp[u][tot]>=0&&!limit)return dp[u][tot];
	int ans=0;
	int mx=limit?a[u]:9;
	for(int i=0;i<=mx;++i){
		ans=(ans+dfs(u+1,tot-(i>=x),limit&&i==mx,x))%mod;
	}
	if(!limit)dp[u][tot]=ans;
	return ans;
}
int Solve(int x){
	memset(dp,~0x3f,sizeof(dp));
	int ans=0,tmp=0;
	for(int i=0;i<=n;++i){
		ans=(ans+1LL*dfs(1,i,1,x)*tmp%mod)%mod;
		tmp=(10LL*tmp+1)%mod;
	}
	return ans;
}
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;++i){
		a[i]=s[i]-'0';
	}
	for(int i=1;i<=9;++i){
		ans=(ans+Solve(i))%mod;
	}
	cout<<ans<<endl;
	return 0;
}