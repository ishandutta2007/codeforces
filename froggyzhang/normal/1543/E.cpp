#include<bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long ll;
typedef unsigned long long ull;
const int inf=0x3f3f3f3f;
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
int T,n,p[N],id[N],ans[N],dis[N];
vector<int> G[N];
queue<int> q;
void Solve(){
	n=read();
	for(int i=0;i<(1<<n);++i){
		G[i].clear();
		p[i]=-1;
		dis[i]=inf;
	}
	for(int i=1;i<=n*(1<<n-1);++i){
		int u=read(),v=read();
		G[u].push_back(v);
		G[v].push_back(u);
	}
	p[0]=0;
	dis[0]=0;
	int z=0;
	for(auto v:G[0]){
		p[v]=1<<(z++);
		q.push(v);
		dis[v]=1;
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(auto v:G[u]){
			if(!~p[v]){
				q.push(v);
				p[v]=p[u];
				dis[v]=dis[u]+1;
			}
			else if(dis[v]==dis[u]+1)p[v]|=p[u];
		}
	}
	for(int i=0;i<(1<<n);++i){
		id[p[i]]=i;
	}
	for(int i=0;i<(1<<n);++i){
		printf("%d ",id[i]);
	}
	printf("\n");
	if((1<<n)%n==0){
		for(int i=0;i<(1<<n);++i){
			int x=0;
			for(int j=0;j<n;++j){
				if(i>>j&1){
					x^=j;
				}
			}
			ans[id[i]]=x;	
		}
		for(int i=0;i<(1<<n);++i){
			printf("%d ",ans[i]);	
		}
		printf("\n");
	}
	else{
		printf("-1\n");	
	}
}
int main(){
	T=read();
	while(T--){
		Solve();	
	}
	return 0;
}