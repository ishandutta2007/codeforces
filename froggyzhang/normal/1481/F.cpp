#include<bits/stdc++.h>
using namespace std;
#define N 100010
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
int n,f[N],dep[N],mx,cnt[N],x,lc[N];
vector<int> G[N];
bitset<N> dp[1333];
int s[N],vis[N],tot;
vector<int> z[N];
void dfs(int u){
	dep[u]=dep[f[u]]+1;
	++cnt[dep[u]],mx=max(mx,dep[u]);
	if(G[u].empty())++lc[dep[u]];
	for(auto v:G[u]){
		dfs(v);
	}
}
int ok[N];
void Find(int u,int t){
	if(!u)return;
	int o=0;
	for(;o<(int)z[u].size();++o){
		if(s[u]>t||dp[u-1][t])break;
		t-=s[u],ok[z[u][o]]=1;
	}
	Find(u-1,t);
}	
int main(){
	n=read(),x=read();
	for(int i=2;i<=n;++i){
		f[i]=read();
		G[f[i]].push_back(i);
	}
	dfs(1);
	for(int i=1;i<=mx;++i){
		if(vis[cnt[i]]){
			z[vis[cnt[i]]].push_back(i);
		}
		else{
			vis[cnt[i]]=++tot;
			s[tot]=cnt[i];
			z[tot].push_back(i);
		}
	}
	dp[0][0]=1;
	
	for(int i=1;i<=tot;++i){
		dp[i]=dp[i-1];
		int sz=z[i].size();
		for(int g=1;g<=sz;g<<=1){
			sz-=g;
			dp[i]|=(dp[i]<<(g*s[i]));
		}
		if(sz)dp[i]|=dp[i]<<(sz*s[i]);
	}
	if(dp[tot][x]){
		printf("%d\n",mx);
		Find(tot,x);
		for(int i=1;i<=n;++i){
			putchar(ok[dep[i]]?'a':'b');
		}
	}
	else{
		int res=23333333;
		for(int i=x;i>=0;--i){
			if(dp[tot][i]){
				res=i;
				break;
			}
		}
		Find(tot,res);
		int pos=-1;
		for(int i=1;i<=mx;++i){
			if(!ok[i]&&lc[i]>=x-res){
				pos=i;break;
			}
		}
		printf("%d\n",mx+1);
		for(int i=1;i<=n;++i){
			if(dep[i]==pos&&G[i].empty()){
				if(res==x){
					putchar('b');
				}
				else putchar('a'),++res;
			}
			else putchar(ok[dep[i]]?'a':'b');
		}
	}
	return 0;
}