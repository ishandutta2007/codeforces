#include<bits/stdc++.h>
using namespace std;
#define N 1000100
const int mod=1e9+7;
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
int n,m,tot,f[N],dis[N];
queue<vector<int> > q;
vector<pair<int,int> > G[N];
inline void adde(int u,int v,int w){
	G[v].emplace_back(u,w);
}
int main(){
	n=read(),m=read();
	tot=n;
	for(int i=1;i<=m;++i){
		int u=read(),v=read();
		int x=i,nowx=u,nowy=v;
		while(x){
			if(x<10)adde(nowx,v,x),adde(nowy,u,x);
			else adde(nowx,++tot,x%10),nowx=tot,adde(nowy,++tot,x%10),nowy=tot;
			x/=10;
		}
	}
	memset(dis,0x3f,sizeof(dis));
	q.push({1});
	f[1]=0,dis[1]=0;
	while(!q.empty()){
		auto t=q.front();
		q.pop();
		vector<int> h[10];
		for(int c=0;c<10;++c){
			for(auto u:t){
				for(auto [v,w]:G[u]){
					if(w==c&&dis[v]>dis[u]+1){
						dis[v]=dis[u]+1;
						h[c].push_back(v);
						f[v]=(10LL*f[u]+c)%mod;
					}
				}
			}
		}
		for(int i=0;i<10;++i){
			if(!h[i].empty())q.push(h[i]);	
		}
	}
	for(int i=2;i<=n;++i){
		printf("%d\n",f[i]);
	}
	return 0;
}