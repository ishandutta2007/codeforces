#include<bits/stdc++.h>
using namespace std;
#define N 1005
typedef long long ll;
const int mod=998244353;
const int mod2=1145141;
void inc(int &x,int y){(x+=y)>=mod?x-=mod:233;}
void inc2(int &x,int y){(x+=y)>=mod2?x-=mod2:233;}
int n,a[N],m,d[N],c[N][N],c2[N][N];
vector<int> G[N];
void Solve(){
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		G[i].clear();
		d[i]=0;
		for(int j=1;j<=n+1;++j){
			c[i][j]=c2[i][j]=0;
		}
		c[i][0]=c2[i][0]=a[i];
	}
	for(int i=1;i<=m;++i){
		int u,v;
		cin>>u>>v;
		G[u].push_back(v);
		++d[v];
	}
	queue<int> q;
	int ed=0;
	for(int i=1;i<=n;++i){
		if(!d[i])q.push(i);
		if(G[i].empty()){
			ed=i;
		}
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=0;i<=n;++i){
			if(c[u][i]>0||c2[u][i]>0){
				inc(c[u][i+1],(c[u][i]-1+mod)%mod);
				c[u][i]=1;
				inc2(c2[u][i+1],(c2[u][i]+mod2-1)%mod2);
				c2[u][i]=1;
			}
		}
		for(auto v:G[u]){
			if(!--d[v]){
				q.push(v);
			}
			for(int i=0;i<=n;++i){
				inc(c[v][i+1],c[u][i]);
				inc2(c2[v][i+1],c2[u][i]);
			}
			inc(c[v][n+1],c[u][n+1]);
			inc2(c2[v][n+1],c2[u][n+1]);
		}
	}
	for(int i=n+1;i>=0;--i){
		if(c[ed][i]>0||c2[ed][i]>0||i==0){
			cout<<(i+c[ed][i])%mod<<'\n';
			return;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}