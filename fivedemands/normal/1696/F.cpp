#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=1e9+7;
int n;
bool a[101][101][101];
int d[101];
bool vis[101];
vector<int>adj[101];
int e=0;

int w[101][101];
void add(int u,int v){
	//cout << "add " << u << ' ' << v << endl;
	e++;
	adj[u].push_back(v);
	adj[v].push_back(u);
}
void dfs(int id,int p){
	//cout << "dfs " << id << ' ' << p << endl;
	for(int i=1; i<=n ;i++){
		if(vis[i] || i==p) continue;
		if(a[p][i][id]){
			vis[i]=true;
			add(id,i);
			dfs(i,id);
		}
	}
}
void dfs2(int id,int p,int king){
	for(auto c:adj[id]){
		if(c==p) continue;
		w[king][c]=w[king][id]+1;
		dfs2(c,id,king);
	}
}
void solve(){
	cin >> n;e=0;
	for(int i=1; i<=n ;i++){
		d[i]=0;vis[i]=false;
		for(int j=1; j<=n ;j++){
			w[i][j]=0;
			for(int k=1; k<=n ;k++){
				a[i][j][k]=false;
			}
		}
		adj[i].clear();
	}
	for(int i=1; i<=n ;i++){
		for(int j=1; j<=n-i ;j++){
			for(int k=1; k<=n ;k++){
				char c;cin >> c;
				if(c=='1') a[i][i+j][k]=a[i+j][i][k]=true;
			}
		}
	}
	int mn=1e9;
	for(int i=1; i<=n ;i++){
		for(int j=1; j<=n ;j++){
			bool king=true;
			for(int k=1; k<j ;k++){
				if(a[k][j][i]) king=false;
			}
			d[i]+=king;
		}
		mn=min(mn,d[i]);
	}
	vector<int>cc;
	for(int i=1; i<=n ;i++){
		if(d[i]==mn) cc.push_back(i);
	}
	if(cc.size()>=3){
		cout << "No\n";
		return;
	}
	if(cc.size()==2){
		add(cc[0],cc[1]);
		vis[cc[0]]=vis[cc[1]]=true;
		dfs(cc[0],cc[1]);
		dfs(cc[1],cc[0]);
	}
	else{
		vis[cc[0]]=true;
		for(int i=1; i<=n ;i++){
			if(d[i]==mn+1 && !vis[i]){
				add(cc[0],i);
				vis[i]=true;
				dfs(i,cc[0]);
			}
		}
	}
	if(e!=n-1){
		cout << "No\n";
		return;
	}
	for(int i=1; i<=n ;i++){
		dfs2(i,0,i);
	}
	for(int i=1; i<=n ;i++){
		for(int j=1; j<=n-i ;j++){
			for(int k=1; k<=n ;k++){
				if(a[i][i+j][k]!=(w[i][k]==w[i+j][k])){
					cout << "No\n";
					return;
				}
			}
		}
	}
	cout << "Yes\n";
	for(int i=1; i<=n ;i++){
		for(auto c:adj[i]){
			if(c>i) cout << i << ' ' << c << '\n';
		}
	}
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;while(t--) solve();
}