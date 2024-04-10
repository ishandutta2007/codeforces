#include<bits/stdc++.h>
using namespace std;
#define N 52
typedef long long ll;
const int inf=0x3f3f3f3f;
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
char mp[N][N];
int dp[N][N][N][N];
int dfs(int l1,int r1,int l2,int r2){
	int &ans=dp[l1][r1][l2][r2];
	if(~ans)return ans;
	if(l1==r1&&l2==r2)return ans=(mp[l1][l2]=='#');
	ans=max(r1-l1+1,r2-l2+1);
	for(int i=l1;i<r1;++i){
		ans=min(ans,dfs(l1,i,l2,r2)+dfs(i+1,r1,l2,r2));
	}
	for(int i=l2;i<r2;++i){
		ans=min(ans,dfs(l1,r1,l2,i)+dfs(l1,r1,i+1,r2));
	}
	return ans;
}
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		scanf("%s",mp[i]+1);
	}
	memset(dp,-1,sizeof(dp));
	printf("%d\n",dfs(1,n,1,n));
	return 0;
}