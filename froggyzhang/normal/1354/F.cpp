#include<bits/stdc++.h>
using namespace std;
#define N 80
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
int T,n,m,dp[N][N],pre[N][N],vis[N];
array<int,3> a[N];
vector<int> t,ans;
void dfs(int i,int j){
	if(!i)return;
	dfs(i-1,pre[i][j]);
	if(pre[i][j]^j)t.push_back(get<2>(a[i])),vis[t.back()]=1;
}
void Solve(){
	n=read(),m=read();
	for(int i=1;i<=n;++i){
		get<0>(a[i])=read();
		get<1>(a[i])=read();
		get<2>(a[i])=i;
		vis[i]=0;
	}
	sort(a+1,a+n+1,[&](array<int,3> i,array<int,3> j){return get<1>(i)<get<1>(j);});
	memset(dp,~0x3f,sizeof(dp));
	memset(pre,0,sizeof(pre));
	dp[0][0]=1;
	for(int i=1;i<=n;++i){
		for(int j=0;j<=min(i,m);++j){
			dp[i][j]=dp[i-1][j]+(m-1)*get<1>(a[i]);
			pre[i][j]=j;
			if(j){
				int w=dp[i-1][j-1]+get<0>(a[i])+(j-1)*get<1>(a[i]);
				if(w>dp[i][j]){
					dp[i][j]=w,pre[i][j]=j-1;
				}
			}
		}
	}
	ans.clear();
	t.clear();
	dfs(n,m);
	for(int i=0;i<m-1;++i){
		ans.push_back(t[i]);
	}
	for(int i=1;i<=n;++i){
		if(!vis[i])ans.push_back(i),ans.push_back(-i);
	}
	ans.push_back(t.back());
	printf("%d\n",(int)ans.size());
	for(auto x:ans)printf("%d ",x);
	printf("\n"); 
} 
int main(){
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}