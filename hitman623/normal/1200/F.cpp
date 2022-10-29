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
int n,k[1001],g=1;
vi e[1001];
int vis[1001][5005],ans[1001][5005];
int go(int node,int c){
	if(ans[node][c]) return ans[node][c];
	if(vis[node][c]){
		vi v;
		int cnt=1;
		pii cur={node,c};
		while(1){
			node=e[node][c%sz(e[node])];
			c=(c+k[node])%g;
			c=(c+g)%g;
			v.pb(node);
			if(node==cur.x and c==cur.y) break;
		}
		sort(all(v));
		v.resize(unique(all(v))-v.begin());
		return ans[node][c]=sz(v);
	}
	else{
		vis[node][c]=1;
		int nod=e[node][c%sz(e[node])];
		int cc=(c+k[nod])%g;
		cc=(cc+g)%g;
		return ans[node][c]=go(nod,cc);
	}
}
void solve(){
    cin>>n;
    rep(i,1,n+1) cin>>k[i];
    rep(i,1,n+1){
    	int m;
    	cin>>m;
    	rep(j,0,m){
    		int x;
    		cin>>x;
    		e[i].pb(x);
    	}
    	g=g*m/__gcd(g,m);
    }
    int q;
    cin>>q;
    while(q--){
    	int x,y;
    	cin>>x>>y;
    	y=((y+k[x])%g+g)%g;
    	cout<<go(x,y)<<endl;
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