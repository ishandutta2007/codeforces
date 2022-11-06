#include<bits/stdc++.h>
using namespace std;
const int N=3e5+11;
int n,m,q;
vector<int> e[N];
vector<int> g[N],rd[N];
int a[N],b[N],d[N];
int vis[N],pre[N];
void bfs(int S){
	for(int i=1;i<=n;++i)vis[i]=0;
	queue<int> Q;
	Q.push(S);
	vis[S]=1;
	pre[S]=0;
	while(!Q.empty()){
		int x=Q.front();
		Q.pop();
		for(int y:e[x]){
			if(vis[y])continue;
			pre[y]=x;
			vis[y]=1;
			Q.push(y);
		}
	}
}
int f[N];
int fa(int x){return f[x]==x?x:f[x]=fa(f[x]);}
int main(){
#ifdef flukehn
	freopen("a.in","r",stdin);
#endif
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)f[i]=i;
	for(int i=1;i<=m;++i){
		int x,y;
		cin>>x>>y;
		if(fa(x)==fa(y))continue;
		f[fa(x)]=fa(y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	cin>>q;
	for(int i=1;i<=q;++i){
		int x,y;
		cin>>x>>y;
		a[i]=x;
		b[i]=y;
		++d[x];
		++d[y];
	}
	int tot=0;
	for(int i=1;i<=n;++i)tot+=d[i]%2;
	if(tot){
		cout<<"NO\n";
		cout<<tot/2<<"\n";
	}else{
		cout<<"YES\n";
		for(int i=1;i<=q;++i){
			g[min(a[i],b[i])].push_back(i);	
		}
		for(int i=1;i<=n;++i){
			if(!g[i].size())continue;
			bfs(i);
			//cerr<<i<<": ";
			//for(int i=1;i<=n;++i)cerr<<pre[i]<<" \n"[i==n];
			for(int w:g[i]){
				int x=a[w]^b[w]^i;
				int y=x;
				//cerr<<w<<" "<<i<<" "<<y<<endl;
				while(y)rd[w].push_back(y),y=pre[y];
				if(a[w]==i)reverse(rd[w].begin(),rd[w].end());
			}
		}
		for(int i=1;i<=q;++i){
			int m=rd[i].size();
			cout<<m<<"\n";
			for(int j=0;j<m;++j)cout<<rd[i][j]<<" \n"[j+1==m];
		}
	}
}