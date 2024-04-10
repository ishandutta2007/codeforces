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
#define p 			250
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,q,type[200005],x[200005],y[200005],par[200005],target,vis[200005],last,special[200005],par2[200005];
vector<pair<pii,int>> edges;
int fp(int node){
	if(par[node]==node) return node;
	else return par[node]=fp(par[node]);
}
void merge(int xx,int yy){
	xx=fp(xx);
	yy=fp(yy);
	par[xx]=yy;
}
int fp2(int node){
	if(par2[node]==node) return node;
	else return par2[node]=fp2(par2[node]);
}
void merge2(int xx,int yy){
	xx=fp2(xx);
	yy=fp2(yy);
	par2[xx]=yy;
}
void solve(){
    cin>>n>>q;
    rep(i,0,q)  cin>>type[i]>>x[i]>>y[i];
   	rep(i,0,q){
   		if(i%p==0){
   			vi nodes;
   			rep(j,i,min(i+p,q)) nodes.pb(x[j]),nodes.pb(y[j]),nodes.pb(x[j]%n+1),nodes.pb(y[j]%n+1);
   			sort(all(nodes));
   			nodes.resize(unique(all(nodes))-nodes.begin());
   			rep(j,1,n+1) par[j]=j,special[j]=0;
   			set<pii> extras;
   			for(auto j:nodes) special[j]=1;
   			for(auto &j:edges){
   				if(j.y==0) continue;
				if(special[j.x.x] and special[j.x.y]){
					extras.insert(j.x);
					j.y=0;
				}
				else merge(j.x.x,j.x.y);
   			}
   			rep(ii,i,min(q,i+p)){
   				x[ii]=(x[ii]+last-1)%n+1;
   				y[ii]=(y[ii]+last-1)%n+1;
   				if(x[ii]>y[ii]) swap(x[ii],y[ii]);
   				if(type[ii]==1){
   					if(extras.count({x[ii],y[ii]})) extras.erase(extras.find({x[ii],y[ii]}));
   					else extras.insert({x[ii],y[ii]});
   				}
   				else{
   					for(auto j:nodes) par2[fp(j)]=fp(j);
   					for(auto j:extras) merge2(fp(j.x),fp(j.y));
   					if(fp2(fp(x[ii]))==fp2(fp(y[ii]))) last=1;
   					else last=0;
   					cout<<last;
   				}
   			}
   			for(auto j:extras) edges.pb({j,1});
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