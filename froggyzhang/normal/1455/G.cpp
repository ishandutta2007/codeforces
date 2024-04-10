#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
const ll inf=0x3f3f3f3f3f3f3f3fll;
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
int n,ban,x[N],w[N],f[N];
string opt[N];
vector<int> G[N];
ll d[N];
map<int,ll> dp[N];
multiset<ll> num[N];
void dfs(int u){
	dp[u][x[u]]=0;
	num[u].insert(0);
	for(auto v:G[u]){
		if(opt[v][0]=='s'){
			if(x[v]==ban){
				d[u]+=w[v];	
			}
			else{
				if(dp[u].count(x[v])){
					ll zyk=dp[u][x[v]];
					dp[u][x[v]]=(*num[u].begin())-w[v];	
					num[u].erase(num[u].find(zyk));
				}
				else{
					dp[u][x[v]]=(*num[u].begin())-w[v];	
				}
				num[u].insert(dp[u][x[v]]);
				d[u]+=w[v];
			}
		}
		else{
			if(dp[u].count(x[v])){
				dfs(v);	
				ll tmp=d[v]+dp[u][x[v]];
				if(dp[v].size()<=dp[u].size()){
					ll tmp=d[v]+dp[u][x[v]];
					for(auto [k,t]:dp[v]){
						if(!dp[u].count(k))dp[u][k]=tmp+t;
						else{
							num[u].erase(num[u].find(dp[u][k]));
							dp[u][k]=min(k==x[v]?inf:dp[u][k],tmp+t);
						}
						num[u].insert(dp[u][k]);
					}
				}
				else{
					d[u]+=tmp;
					for(auto [k,t]:dp[u]){
						if(!dp[v].count(k))dp[v][k]=t-tmp;
						else{
							num[v].erase(num[v].find(dp[v][k]));
							if(k^x[v])dp[v][k]=min(dp[v][k],t-tmp);
						}
						num[v].insert(dp[v][k]);
					}	
					swap(dp[u],dp[v]);
					swap(num[u],num[v]);
				}
			}
		}	
	}
}
int main(){
	n=read(),ban=read();;
	int u=0;
	for(int i=1;i<=n;++i){
		cin>>opt[i];
		if(opt[i][0]=='s'){
			G[u].push_back(i);
			x[i]=read(),w[i]=read();
		}
		else if(opt[i][0]=='i'){
			x[i]=read();
			G[u].push_back(i);
			f[i]=u;
			u=i;
		}
		else{
			u=f[u];
		}
	}
	dfs(0);
	printf("%lld\n",d[0]+(*num[0].begin()));
	return 0;
}