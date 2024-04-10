#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int mod=998244353;
#define N 2333
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
int n,ans,pw2[N],col[N];
char s[N];
vector<pair<int,int> > G[N];
bool dfs(int u){
	for(auto [v,w]:G[u]){
		if(~col[v]){
			if(col[v]!=col[u]^w)return false;
		}
		else{
			col[v]=col[u]^w;
			dfs(v);
		}
	}
	return true;
}
int Solve(int x){
	if(s[1]=='1')return 0;
	for(int i=1;i<=(n<<1);++i)G[i].clear(),col[i]=-1;
	for(int i=1;i<=n;++i){
		if(n-i+1!=i)G[n-i+1].emplace_back(i,0),G[i].emplace_back(n-i+1,0);
	}
	for(int i=1;i<=x;++i){
		if(x-i+1!=i){
			G[n+x-i+1].emplace_back(n+i,0);
			G[n+i].emplace_back(n+x-i+1,0);
		}
	}
	for(int i=1;i<=x;++i){
		if(s[i]=='0'){
			G[i].emplace_back(n+i,0);
			G[n+i].emplace_back(i,0);
		}
		else if(s[i]=='1'){
			G[i].emplace_back(n+i,1);
			G[n+i].emplace_back(i,1);
		}
	}
	for(int i=x+1;i<=n;++i){
		if(s[i]!='?'){
			if(~col[i]){
				if(col[i]!=s[i]-'0')return 0;
			}
			else{
				col[i]=s[i]-'0';
				if(!dfs(i))return 0;
			}
		}
	}
	
	if(~col[n+x]){
		if(col[n+x]!=1)return 0;
	}
	else{
		col[n+x]=1;
		if(!dfs(n+x))return 0;
	}
	if(~col[1]){
		if(col[1]!=1)return 0;
	}
	else{
		col[1]=1;
		if(!dfs(1))return 0;
	}
	if(~col[n+1]){
		if(col[n+1]!=1)return 0;
	}
	else{
		col[n+1]=1;
		if(!dfs(n+1))return 0;
	}
	int cnt=0;
	for(int i=1;i<=n+x;++i){
		if(!~col[i]){
			++cnt;
			col[i]=0;
			dfs(i);
		}
	}
	return pw2[cnt];
} 
int main(){
	scanf("%s",s+1);
	n=strlen(s+1); 
	reverse(s+1,s+n+1);
	pw2[0]=1;
	for(int i=1;i<=(n<<1);++i){
		pw2[i]=(pw2[i-1]<<1)%mod;
	}
	for(int i=1;i<n;++i){
		ans=(ans+Solve(i))%mod;
	}
	printf("%d\n",ans);
	return 0;
}