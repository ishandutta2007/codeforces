#include<bits/stdc++.h>
using namespace std;
#define N 2020
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
int n,a[N][N],tot,w[N],id[N];
int f[N];
vector<pair<int,int> > E;
inline int getf(int x){
	return f[x]==x?x:f[x]=getf(f[x]);
}
pair<int,int> t[N*N];
mt19937 rnd(time(0));
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			a[i][j]=read();
			t[(i-1)*n+j]=make_pair(i,j);
		}
	}
	for(int i=1;i<=n;++i)w[i]=a[i][i];
	for(int i=1;i<=(n<<1);++i)f[i]=i,id[i]=i;
	tot=n;
	sort(t+1,t+n*n+1,[&](pair<int,int> i,pair<int,int> j){return a[i.first][i.second]<a[j.first][j.second];});
	for(int i=1;i<=n*n;++i){
		int u=t[i].first,v=t[i].second;
		int c=a[u][v];
		u=getf(u),v=getf(v);
		if(u==v)continue;
		if(c==w[u]&&c==w[v]){
			id[v]=u;
			f[v]=u;
		}
		else if(c==w[u])f[v]=u,E.emplace_back(v,u);
		else if(c==w[v])f[u]=v,E.emplace_back(u,v);
		else{
			++tot;
			w[tot]=c;
			f[u]=f[v]=tot;
			E.emplace_back(u,tot);
			E.emplace_back(v,tot);
		}
	}
	for(int u=1;u<=tot;++u){
		while(id[id[u]]^id[u])id[u]=id[id[u]];
	}
	int tmp=0;
	for(int i=1;i<=tot;++i){
		if(id[i]==i){
			++tmp;
			w[tmp]=w[id[i]];
			for(int j=1;j<=tot;++j){
				if(id[j]==i)id[j]=tmp;
			}
		}	
	}
	printf("%d\n",tmp);
	for(int i=1;i<=tmp;++i){
		printf("%d ",w[i]);
	}
	printf("\n%d\n",id[getf(1)]);
	for(auto [u,v]:E){
		printf("%d %d\n",id[u],id[v]);
	}
	return 0;
}