#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=998244353;
const int N=405;
ll n,m;
int d[N][N];
int cnt[N][N],pnt[N][N];
int freq[N];
ll ans[N][N];
int king[N];
vector<int>adj[N];
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n >> m;
	for(int i=1; i<=n ;i++){
		for(int j=1; j<=n ;j++){
			d[i][j]=1e9;
		}
		d[i][i]=0;
	}
	for(int i=1; i<=m ;i++){
		int u,v;cin >> u >> v;
		d[u][v]=d[v][u]=1;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int k=1; k<=n ;k++)
	for(int i=1; i<=n ;i++)
	for(int j=1; j<=n ;j++)
	d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
	for(int i=1; i<=n ;i++){
		for(int j=1; j<=n ;j++){
			bool ok=true;
			for(int k=0; k<=n ;k++) king[k]=0;
			for(int k=1; k<=n ;k++){
				if(d[i][k]+d[j][k]==d[i][j]){
					if(king[d[i][k]]==0) king[d[i][k]]=k;
					else ok=false;
				}
				
			}
			for(int k=0; k<=d[i][j] ;k++){
				if(king[k]==0) ok=false;
				king[k]=0;
			}
			if(!ok){
				continue;
			}
			ans[i][j]=1;
			for(int k=1; k<=n ;k++){
				if(d[i][k]+d[j][k]==d[i][j]) continue;
				int ways=0;
				for(auto c:adj[k]){
					if(d[i][c]+1==d[i][k] && d[j][c]+1==d[j][k]) ways++;
				}
				ans[i][j]=ans[i][j]*ways%mod;
			}
			
		}
	}
	for(int i=1; i<=n ;i++){
		for(int j=1; j<=n ;j++){
			cout << ans[i][j] << ' ';
		}
		cout << '\n';
	}
}