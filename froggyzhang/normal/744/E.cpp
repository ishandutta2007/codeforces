#include<bits/stdc++.h>
using namespace std;
#define N 100010
#define M 33
typedef long long ll;
const int mod=998244853;
const int base=1145141;
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
int n,len[M],tot,fm[N],ans;
int pw[N];
string s[M];
vector<int> id[M];
vector<int> h[M];
vector<int> G[N];
vector<pair<int,int> > nd[N];
inline int Hash(vector<int> &h,int l,int r){
	return (h[r]-(!l?0:1LL*h[l-1]*pw[r-l+1]%mod)+mod)%mod;
}
int ins[N],vis[N];
bool ok;
int L,R;
void dfs(int u){
	if(!ok)return;
	if(!(u==tot||(fm[u]>=L&&fm[u]<=R)))return;
	ins[u]=vis[u]=1;
	for(int i=0;i<(int)G[u].size();++i){
		int v=G[u][i];
		if(nd[u][i].first<L||nd[u][i].first>R||nd[u][i].second<L||nd[u][i].second>R)continue;
		if(ins[v]){
			ok=false;
			break;
		}
		dfs(v);	
	}
	ins[u]=0;
}
bool check(int l,int r){
	L=l,R=r;
	ok=true;
	for(int i=1;i<=tot;++i)ins[i]=vis[i]=0;
	for(int i=1;i<=tot;++i){
		if(!vis[i]){
			dfs(i);
		}
	}
	return ok;
}
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		cin>>s[i];
		len[i]=s[i].length();
		id[i].resize(len[i]);
		h[i].resize(len[i]);
		for(int j=0;j<len[i];++j){
			id[i][j]=++tot;
			fm[tot]=i;
		}
		h[i][0]=s[i][0];
		for(int j=1;j<len[i];++j){
			h[i][j]=(1LL*h[i][j-1]*base+s[i][j])%mod;
		}
	}
	++tot;
	pw[0]=1;
	for(int i=1;i<=100000;++i){
		pw[i]=1LL*pw[i-1]*base%mod;
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			for(int k=0;k<len[i];++k){
				if(!k&&s[i]==s[j])continue;
				int u=!k?tot:id[i][k-1];
				int pos=k+len[j]-1;
				int v=(pos==len[i]-1?tot:(pos<len[i]-1?id[i][pos]:id[j][len[i]-k-1]));
				if(Hash(h[i],k,min(pos,len[i]-1))==Hash(h[j],0,min(len[j]-1,len[i]-k-1))){
					G[u].push_back(v);
					nd[u].emplace_back(i,j);
				}
			}	
		}	
	}
	for(int i=1;i<=n;++i){
		for(int j=i;j<=n;++j){
			if(check(i,j))++ans;
			else break;
		}	
	}
	printf("%d\n",ans);
	return 0;
}