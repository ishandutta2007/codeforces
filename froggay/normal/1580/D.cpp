#include<bits/stdc++.h>
using namespace std;
#define N 4004
typedef long long ll;
int n,m,a[N],siz[N];
ll dp[N][N];
struct node{
	int ch[2];	
}t[N];
#define ls t[u].ch[0]
#define rs t[u].ch[1]
void dfs(int u){
	siz[u]=1;
	if(ls)dfs(ls),siz[u]+=siz[ls];
	if(rs)dfs(rs),siz[u]+=siz[rs];
	#define update(x,y) x=max(x,y)
	if(ls&&rs){
		for(int i=0;i<=siz[ls];++i){
			for(int j=0;j<=siz[rs];++j){
				update(dp[u][i+j],dp[ls][i]+dp[rs][j]-2LL*a[u]*i*j);
				update(dp[u][i+j+1],dp[ls][i]+dp[rs][j]+1LL*(m-1-2*(i+j))*a[u]-2LL*a[u]*i*j);
			}
		}
	}
	else if(ls){
		for(int i=0;i<=siz[ls];++i){
			update(dp[u][i],dp[ls][i]);
			update(dp[u][i+1],dp[ls][i]+1LL*(m-1-2*i)*a[u]);
		}
	}
	else if(rs){
		for(int i=0;i<=siz[rs];++i){
			update(dp[u][i],dp[rs][i]);
			update(dp[u][i+1],dp[rs][i]+1LL*(m-1-2*i)*a[u]);
		}
	}
	else{
		dp[u][0]=0;
		dp[u][1]=1LL*(m-1)*a[u];
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	static int st[N],top;
	for(int i=1;i<=n;++i){
		while(top&&a[i]<=a[st[top]])t[i].ch[0]=st[top--];
		if(top)t[st[top]].ch[1]=i;
		st[++top]=i;
	}
	for(int i=0;i<=n;++i){
		for(int j=0;j<=n;++j){
			dp[i][j]=-1e18;		
		}
	}
	dfs(st[1]);
	cout<<dp[st[1]][m]<<'\n';
	return 0;
}