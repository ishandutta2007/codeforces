#include<bits/stdc++.h>
using namespace std;
#define N 200010
typedef long long ll;
int n,p[N],f[N],rt,vis[N],w[N],sw[N]; 
void Solve(){
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>f[i];
		if(f[i]==i)rt=i;
		vis[i]=w[i]=sw[i]=0;
	}
	for(int i=1;i<=n;++i){
		cin>>p[i];
	}
	int now=0;
	for(int i=1;i<=n;++i){
		int u=p[i];
		if(u^rt&&!vis[f[u]]){
			cout<<-1<<'\n';
			return;
		}
		vis[u]=1;
		if(u==rt)continue;
		++now;
		w[u]=now-sw[f[u]];
		sw[u]=now;
	}
	for(int i=1;i<=n;++i){
		cout<<w[i]<<' ';
	}
	cout<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		Solve();
	}
	return 0;
}