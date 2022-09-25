#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
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
int fan[1<<17|233];
map<pair<int,int>,int> dp[2][2];
int n,K;
int dfs(int l,int r,int x,int y){
	if(dp[x][y].count(make_pair(l,r)))return dp[x][y][make_pair(l,r)];
	if(l+1==r){
		return fan[l]+fan[r]==x+y?(x+y?1:0):-inf;
	}
	int mx=-inf;
	int mid=(l+r)>>1;
	for(int xa=0;xa<2;++xa){
		for(int ya=0;ya<2;++ya){
			for(int xb=0;xb<2;++xb){
				for(int yb=0;yb<2;++yb){
					if((xa==x&&(xb|yb|ya)==y)||(xb==x&&(xa|ya|yb)==y)){
						mx=max(mx,dfs(l,mid,xa,ya)+dfs(mid+1,r,xb,yb));
					}
				}
			}
		}
	}
	return dp[x][y][make_pair(l,r)]=mx+x+y*2;
}
int main(){
	n=read(),K=read();
	if(!K)return !printf("0\n");
	for(int i=1;i<=K;++i){
		fan[read()]=1;
	}
	int ans=0;
	for(int i=0;i<2;++i){
		for(int j=0;j<2;++j){
			ans=max(ans,dfs(1,1<<n,i,j));
		}
	}
	printf("%d\n",ans+1);
	return 0;
}