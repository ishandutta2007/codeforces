#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=998244353;
int n,k;
ll w[81][81];
vector<pair<ll,int> >v[81][81];
vector<int>g;
ll ans=1e18;
int used[81];
void funny(){
	g.push_back(1);
	ll cost=0;
	for(int i=0; i<g.size()-1 ;i++){
		int x=g[i],y=g[i+1];
		int z=0;
		while(used[v[x][y][z].se]) ++z;
		cost+=v[x][y][z].fi;
	}
	ans=min(ans,cost);
	g.pop_back();
}
void maho(int z){
	if(z==0){
		funny();return;
	}
	for(int i=1; i<=n ;i++){
		g.push_back(i);
		used[i]++;
		maho(z-1);
		g.pop_back();
		used[i]--;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for(int i=1; i<=n ;i++){
		for(int j=1; j<=n ;j++){
			cin >> w[i][j];
		}
	}
	for(int i=1; i<=n ;i++){
		for(int j=1; j<=n ;j++){
			for(int k=1; k<=n ;k++){
				v[i][j].push_back({w[i][k]+w[k][j],k});
			}
			v[i][j].push_back({1e15,0});
			sort(v[i][j].begin(),v[i][j].end());
		}
	}
	g.push_back(1);
	used[1]=true;
	maho(k/2-1);
	cout << ans << endl;
}