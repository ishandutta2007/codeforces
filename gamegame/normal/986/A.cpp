#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
int n,m,k,s;
int a[100001];
int ans[101][100001];
bool vis[100001];
vector<int>adj[100001];
int b[101];
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m >> k >> s;
	for(int i=1; i<=n ;i++) cin >> a[i];
	for(int i=1; i<=m ;i++){
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i=1; i<=k ;i++){
		queue<int>q;
		for(int j=1; j<=n ;j++){
			if(a[j]==i){
				q.push(j);
				vis[j]=true;
			}
			else vis[j]=false;
		}
		while(!q.empty()){
			int cur=q.front();
			q.pop();
			for(auto newi:adj[cur]){
				if(!vis[newi]){
					vis[newi]=true;
					ans[i][newi]=ans[i][cur]+1;
					q.push(newi);
				}
			}
		}
		/*for(int j=1; j<=n ;j++){
			cout << ans[i][j] << ' ';
		}
		cout << endl;*/
	}
	for(int i=1; i<=n ;i++){
		for(int j=1; j<=k ;j++) b[j]=ans[j][i];
		sort(b+1,b+k+1);
		int sum=0;
		for(int j=1; j<=s ;j++) sum+=b[j];
		cout << sum << ' ';
	}
}