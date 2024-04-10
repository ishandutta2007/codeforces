#include<bits/stdc++.h>
using namespace std;
#define N 1000006
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
int n,A,B,C,D,siz[N],f[N],mark[N];
vector<int> G[N];
void init(int u){
	bool leaf=true;
	for(auto v:G[u]){
		if(v==f[u])continue;
		f[v]=u;
		init(v);
		leaf=false;
		siz[u]+=siz[v];
	}
	if(leaf)++siz[u];
}
void Get(int u,int gu){
	while(u^1){
		mark[u]|=gu;
		u=f[u];
	}
}
vector<int> pro;
int cnt[N];
void dfs(int u,int num,int ban){
	for(auto v:G[u]){
		if(v==f[u])continue;
		if(mark[v]&ban)continue;
		if(mark[v]&num){
			dfs(v,num,ban);
		}
		else{
			if(u^1)++cnt[siz[v]];	
		}
	}	
}
bool check(){
	for(int i=1;i<=n;++i){
		mark[i]=0;	
	}
	Get(A,1),Get(B,2);
	Get(C,4),Get(D,8);
	for(int i=2;i<=n;++i){
		if((mark[i]&3)==3)return false;
	}
	pro.clear();
	for(int i=1;i<=n;++i)cnt[i]=0;
	dfs(1,1,12);
	dfs(1,2,12);
	int res=siz[1]/2-1;
	for(auto v:G[1]){
		if(mark[v]&4)res-=siz[v];
		if(mark[v])continue;
		++cnt[siz[v]];
	}
	if(res<0)return false;
	for(int i=1;i<=n;++i){
		int p=1;
		while(cnt[i]>=p){
			pro.push_back(p*i);
			cnt[i]-=p;
			p<<=1;
		}
		if(cnt[i])pro.push_back(i*cnt[i]);	
	}
	bitset<N/2> dp;
	dp[0]=1;
	for(auto x:pro){
		dp|=dp<<x;	
	}
	return dp[res];
}
int main(){
	n=read();
	A=read(),B=read();
	C=read(),D=read();
	for(int i=2;i<=n;++i){
		int fa=read();
		G[fa].push_back(i);
		G[i].push_back(fa);
	}
	init(1);
	if(siz[1]&1){
		printf("NO\n");
		return 0;
	}
	if(!check()){
		printf("NO\n");
		return 0;
	}
	swap(A,C),swap(B,D);
	if(!check()){
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	return 0;
}