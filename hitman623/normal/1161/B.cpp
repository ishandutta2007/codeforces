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
int n,m;
vi divis;
vi a[100005];
vii edges,edges2;
void solve(){
    cin>>n>>m;
    rep(i,0,m){
    	int x,y;
    	cin>>x>>y;
    	x--,y--;
    	int d=min(abs(x-y),n-abs(x-y));
    	if((x+d)%n==y) a[d].pb(x);
    	else a[d].pb(y);
    	if(x>y) swap(x,y);
    	edges.pb({x,y});
    }
 	for(int i=2;i*i<=n;i++){
 		if(n%i==0){
 			divis.pb(i);
 			if(i*i!=n){
 				divis.pb(n/i);
 			}
 		}
 	}
 	sort(all(divis));
 	rep(i,1,n+1) sort(all(a[i]));
 	for(auto d:divis){
 		if(2*d==n) continue;
 		int g=1;
 		rep(i,1,n+1){
 			if(sz(a[i])==0) continue;
 			int f=1;
 			int w=(a[i][0]+d)%n;
 			int pos=lower_bound(all(a[i]),w)-a[i].begin();
 			if(pos<sz(a[i]) and a[i][pos]==w){
 				rep(j,0,sz(a[i])){
 					if((a[i][j]+d)%n!=a[i][pos]){
 						f=0;
 						break;
 					}
 					pos=(pos+1)%sz(a[i]);
 				}
 			}
 			else f=0;
 			if(f==0){
 				g=0;
 				break;
 			}
 		}
 		if(g){
 			cout<<"Yes"<<endl;
 			return;
 		}
 	}
 	if(n%2==0){
 		int d=n/2;
 		for(auto i:edges){
 			int u=(i.x+d)%n,v=(i.y+d)%n;
 			if(u>v) swap(u,v);
 			edges2.pb({u,v});
 		}
 		sort(all(edges));
 		sort(all(edges2));
 		if(edges2==edges){
 			cout<<"Yes"<<endl;
 			return;
 		}
 	}
 	cout<<"No"<<endl;
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