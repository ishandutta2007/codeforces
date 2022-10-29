#include <bits/stdc++.h>

#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,m,c,q,par[100005];
map<int,vi> a[100005];
set<int> adj[100005];
int fp(int x){
	if(x==par[x]) return x;
	else return par[x]=fp(par[x]);
}
void merge(int x,int y){
	x=fp(x);
	y=fp(y);
	if(x==y) return;
	if(sz(adj[x])>sz(adj[y])) swap(x,y);
	par[x]=y;
	for(auto i:adj[x]) adj[y].insert(i);
}
void solve(){
	cin>>n>>m>>c>>q;
	rep(i,1,n+1) par[i]=i;
	rep(i,0,m){
		int x,y,z;
		cin>>x>>y>>z;
		a[x][z].pb(y);
		a[y][z].pb(x);
		adj[x].insert(y);
		adj[y].insert(x);
	}
	rep(i,1,n+1){
		for(auto j:a[i]){
			rep(k,1,sz(j.y)){
				merge(j.y[k-1],j.y[k]);
			}
		}
	}
	rep(i,0,q){
		char ch;
		cin>>ch;
		if(ch=='?'){
			int x,y;
			cin>>x>>y;
			if(fp(x)==fp(y)) cout<<"Yes"<<endl;
			else if(adj[fp(x)].count(y)) cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
		}
		else{
			int x,y,z;
			cin>>x>>y>>z;
			if(a[x].count(z)) merge(a[x][z][0],y);
			else a[x][z].pb(y);
			if(a[y].count(z)) merge(a[y][z][0],x);
			else a[y][z].pb(x);
			adj[fp(x)].insert(y);
			adj[fp(y)].insert(x);
		}
	}
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}