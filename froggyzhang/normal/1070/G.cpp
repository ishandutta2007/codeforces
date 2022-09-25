#include<bits/stdc++.h>
using namespace std;
#define N 123
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
int n,m,c[N],a[N],t[N],L,R;
void Solve(int p){
	static int dp[N],pre[N];
	vector<int> ans;
	if(L<=p){
		memset(dp,0,sizeof(dp));
		memset(pre,0,sizeof(pre));
		dp[p+1]=1;
		for(int i=p;i>=1;--i){
			if(c[i]){
				int hp=c[i];
				for(int j=i;j<=p;++j){
					hp+=a[j];
					if(hp<0)break;
					if(dp[j+1]){
						dp[i]=1,pre[i]=j+1;
						break;
					}
				}
			}
		}
		if(!dp[L])return;
		static int vis[N];
		memset(vis,0,sizeof(vis));
		function<void(int)> dfs = [&](int u) -> void{
			if(u>p)return;
			dfs(pre[u]);
			vis[t[u]]=1;
			ans.push_back(t[u]);
		};
		dfs(L);
		for(int i=p;i>=1;--i){
			if(c[i]&&!vis[t[i]])ans.push_back(t[i]);
		}
	}
	if(R>p){
		memset(dp,0,sizeof(dp));
		memset(pre,0,sizeof(pre));
		dp[p]=1;
		for(int i=p+1;i<=n;++i){
			if(c[i]){
				int hp=c[i];
				for(int j=i;j>p;--j){
					hp+=a[j];
					if(hp<0)break;
					if(dp[j-1]){
						dp[i]=1,pre[i]=j-1;
						break;
					}
				}
			}
		}
		if(!dp[R])return;
		static int vis[N];
		memset(vis,0,sizeof(vis));
		function<void(int)> dfs = [&](int u) -> void{
			if(u<=p)return;
			dfs(pre[u]);
			vis[t[u]]=1;
			ans.push_back(t[u]);
		};
		dfs(R);
		for(int i=p+1;i<=n;++i){
			if(c[i]&&!vis[t[i]])ans.push_back(t[i]);
		}
	}
	printf("%d\n",p);
	for(auto x:ans)printf("%d ",x);
	printf("\n");
	exit(0);
}
int main(){
	n=read(),m=read();
	L=n+1;
	for(int i=1;i<=m;++i){
		int x=read();
		c[x]=read();
		t[x]=i;
		L=min(L,x);
		R=max(R,x);
	}
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	for(int i=L;i<=n;++i){
		Solve(i);
	}
	puts("-1");
	return 0;
}