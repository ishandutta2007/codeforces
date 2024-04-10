#include<bits/stdc++.h>
using namespace std;
#define N 505
const int mod=998244353;
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
int T,n,cnt[N][N],vis[N<<1],a[N<<1][N];
void Solve(){
	n=read();
	for(int i=1;i<=n+n;++i)vis[i]=0;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j)cnt[i][j]=0;
	}
	for(int i=1;i<=n+n;++i){
		for(int j=1;j<=n;++j){
			a[i][j]=read();
			++cnt[j][a[i][j]];	
		}
	}
	int ans=1;
	vector<int> row;
	for(int t=1;t<=n;++t){
		int u=-1;
		for(int i=1;i<=n+n;++i){
			if(vis[i])continue;
			for(int j=1;j<=n;++j){
				if(cnt[j][a[i][j]]==1){
					u=i;break;
				}	
			}	
		}
		if(!~u){
			(ans<<=1)%=mod;
			u=1;
			while(vis[u])++u;	
		}
		vis[u]=1;
		for(int i=1;i<=n+n;++i){
			if(vis[i])continue;
			for(int j=1;j<=n;++j){
				if(a[i][j]==a[u][j]){
					vis[i]=1;
					for(int k=1;k<=n;++k)--cnt[k][a[i][k]];
					break;
				}
			}
		}
		for(int j=1;j<=n;++j)--cnt[j][a[u][j]];
		row.push_back(u);
	}
	printf("%d\n",ans);
	for(auto x:row)printf("%d ",x);
	printf("\n");
}
int main(){
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}