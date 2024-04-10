#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const int N=1e6+1;

int n;
int p[N][3];
int in[N];
int q[N];
vector<int>adj[N];
bool vis[N];
void solve(){
	cin >> n;
	for(int i=1; i<=n-2 ;i++){
		cin >> p[i][0] >> p[i][1] >> p[i][2];
		for(int j=0; j<3 ;j++){
			in[p[i][j]]++;
			for(int k=0; k<3 ;k++){
				adj[p[i][j]].push_back(p[i][k]);
			}
		}
	}
	q[1]=1;
	for(int i=1; i<=n ;i++){
		if(in[i]==1){
			q[1]=i;
			break;
		}
	}
	vis[q[1]]=true;
	for(auto x:adj[q[1]]){
		if(in[x]==2){
			q[2]=x;
			break;
		}
	}
	vis[q[2]]=true;
	for(int i=3; i<=n ;i++){
		for(auto x:adj[q[i-2]]){
			if(vis[x]) continue;
			q[i]=x;
		}
		vis[q[i]]=true;
	}
	for(int i=1; i<=n ;i++) cout << q[i] << ' ';
	cout << endl;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	//int t;cin >> t;while(t--) solve();
	solve();
}