#include<bits/stdc++.h>
using namespace std;
#define N 1005
#define M 2522
const int B=2520;
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
int n,m,a[N],ans[N*M],Q;
int to[N*M];
vector<int> H[N];
inline int ID(int u,int t){
	return (u-1)*B+t+1;
}
int st[N*M],top,ins[N*M];
void dfs(int u){
	st[++top]=u;
	ins[u]=1;
	int v=to[u];
	if(ans[v]){
		ans[u]=ans[v];
		return;
	}
	if(ins[v]){
		static int vis[N];
		static vector<int> bin;
		bin.clear();
		while(true){
			int z=(st[top]-1)/B;
			if(!vis[z]){
				vis[z]=1;
				++ans[u];
				bin.push_back(z);
			}
			if(st[top]==v)break;
			--top;
		}
		for(auto x:bin)vis[x]=0;
		return;
	}
	dfs(v);
	ans[u]=ans[v];
}
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	for(int u=1;u<=n;++u){
		m=read();
		for(int j=0;j<m;++j)H[u].push_back(read());
		for(int i=0;i<B;++i){
			int t=((i+a[u])%B+B)%B;
			to[ID(u,i)]=ID(H[u][t%m],t);
		}
	}
	for(int i=1;i<=n*B;++i){
		if(!ans[i])top=0,dfs(i);	
	}
	Q=read();
	while(Q--){
		int x=read(),y=(read()%B+B)%B;
		printf("%d\n",ans[ID(x,y)]);
	}
	return 0;
}