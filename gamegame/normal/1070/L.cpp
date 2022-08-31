#include<iostream>
using namespace std;
typedef unsigned long long ll;
ll eq[2000][32];
bool res[2000];
int pos[2000];
int ans[2000];
bool vis[2000];
int n,m;
void solve(){
	cin >> n >> m;
	for(int i=0; i<n ;i++){
		for(int j=0; j<=((n-1)>>6) ;j++){
			eq[i][j]=0;
		}
		res[i]=vis[i]=0;
	}
	for(int i=0; i<m ;i++){
		int u,v;
		cin >> u >> v;
		u--,v--;
		eq[u][u>>6]^=(ll)1<<(u&63);
		eq[u][v>>6]^=(ll)1<<(v&63);
		eq[v][u>>6]^=(ll)1<<(u&63);
		eq[v][v>>6]^=(ll)1<<(v&63);
		res[u]^=1;
		res[v]^=1;
	}
	bool magic=true;
	for(int i=0; i<n ;i++) if(res[i]) magic=false;
	if(magic){
		cout << "1\n";
		for(int i=0; i<n ;i++) cout << 1 << ' ';
		cout << '\n';
		return;
	}
	for(int i=0; i<n ;i++){
		pos[i]=n;
		for(int j=0; j<n ;j++){
			if(!vis[j] && (eq[j][i>>6]&((ll)1<<(i&63)))) pos[i]=j;
		}
		if(pos[i]==n) continue;
		vis[pos[i]]=true;
		for(int j=0; j<n ;j++){
			if(!vis[j] && (eq[j][i>>6]&((ll)1<<(i&63)))){
				for(int k=0; k<=((n-1)>>6) ;k++) eq[j][k]^=eq[pos[i]][k];
				res[j]^=res[pos[i]];
			}
		}
	}
	for(int i=n-1; i>=0 ;i--){
		ans[i]=0;
		if(pos[i]==n) continue;
		for(int j=0; j<n ;j++){
			if(eq[pos[i]][j>>6]&((ll)1<<(j&63))) ans[i]^=ans[j];
		}
		ans[i]^=res[pos[i]];
	}
	cout << "2\n";
	for(int i=0; i<n ;i++) cout << ans[i]+1 << ' ';
	cout << '\n';
}
int main(){
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--) solve();
}