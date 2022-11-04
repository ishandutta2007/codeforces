#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define ld long double
#define F first
#define S second

using namespace :: std;

const ll maxn=1e5+500;
const ll mod=1e9+7;
const ll inf=1e9+500;



ll seg[4*maxn];
ll lazy[maxn*4];
ll s=0;
ll stim[maxn];
ll etim[maxn];
ll tim=0;

vector<ll> ger[maxn];


void shift(ll a,ll l,ll r){
	ll mid=(l+r)/2;
	ll s=lazy[a];
	lazy[a]=0;
	lazy[2*a]+=s;
	lazy[2*a+1]+=s;
	seg[2*a]+=s*(mid-l);
	seg[2*a+1]+=s*(r-mid);
}
void  update(ll L,ll R,ll node,ll l,ll r,ll v){
	if(l<=L && R<=r){
		seg[node]+=v*(R-L);
		lazy[node]+=v;
		return ;
	}	
	if(R<=l || r<=L){
		return;
	}
	ll mid=(L+R)/2;
	shift(node,L,R);
	update(L,mid,2*node,l,r,v);
	update(mid,R,2*node+1,l,r,v);
	seg[node]=seg[2*node]+seg[2*node+1];
}
ll finds(ll L,ll R,ll node,ll l,ll r){
	if(l<=L && R<=r){
		return seg[node];
	}
	if(R<=l || r<=L){
		return 0;
	}
	shift(node,L,R);
	ll mid=(L+R)/2;
	return  finds(L,mid,2*node,l,r)+finds(mid,R,2*node+1,l,r);
}

bool vis[maxn];
ll  par[maxn][20];
void dfs(ll a){
	vis[a]=1;

	tim++;
	stim[a]=tim;
	for(ll i=0;i<ger[a].size();i++){
		ll v=ger[a][i];
		if(vis[v]==0){
			par[v][0]=a;
			dfs(v);
		}	
	}
	etim[a]=tim;
}
bool is_par(ll a,ll b){
	if(a==b){
		return 1;
	}
	if(stim[a]<=stim[b] &&  etim[a]>=etim[b]){
		return 1;
	}
	return 0;
}
ll las(ll a,ll b){
	for(ll i=19;i>=0;i--){
		if(!is_par(par[a][i],b)){
			a=par[a][i];
		}
	}
	return a;
}
ll lca(ll a,ll b){
	if(is_par(a,b)){
		return a;
	}if(is_par(b,a)){
		return b;
	}
	for(ll i=19;i>=0;i--){
		if(!is_par(par[a][i],b)){
			a=par[a][i];
		}
	}
	return par[a][0];
}	


ll ak[maxn];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	ll rot=0;
	ll n,q;
	cin>>n>>q;
	for(ll i=0;i<n;i++){
		cin>>ak[i];
	}
	for(ll i=1;i<n;i++){
		ll v,u;
		cin>>v>>u;
		v--;
		u--;
		ger[u].pb(v);
		ger[v].pb(u);
	}
	dfs(0);
	for(ll i=1;i<20;i++){
		for(ll j=0;j<n;j++){
			par[j][i]=par[par[j][i-1]][i-1];
		}
	}
	ll y=etim[0]+5;
	for(ll i=0;i<n;i++){
		update(0,y,1,stim[i],stim[i]+1,ak[i]);
	}
	for(ll qw=0;qw<q;qw++){
		ll typ;
		cin>>typ;
		if(typ==1){
			ll v;
			cin>>v;
			v--;
			rot=v;
		}if(typ==2){
			ll v,u,x;
			cin>>v>>u>>x;
			v--;
			u--;
			ll lc=(lca(v,u)^lca(u,rot)^lca(v,rot));
			if(is_par(lc,rot)){
				update(0,y,1,stim[0],etim[0]+1,x);
				if(rot!=lc){
					v=las(rot,lc);
					update(0,y,1,stim[v],etim[v]+1,-x);
				}
			}else{
				update(0,y,1,stim[lc],etim[lc]+1,x);
			}
		}if(typ==3){
			ll v;
			cin>>v;
			v--;
			if(is_par(v,rot)){
				if(v==rot){
					cout<<seg[1]<<endl;
				}else{
					ll u=las(rot,v);
					cout<<seg[1]-finds(0,y,1,stim[u],1+etim[u])<<endl;
				}
			}else{
				cout<<finds(0,y,1,stim[v],etim[v]+1)<<endl;
			}
		}
	}

}



















/*    
	  .      _______    __    ___     ________      ________       _________     _________   ________
	  .     /       \  |  |  /  /    /        \    |        \     /         \   |        |  |   __   \
	  .    /   _____/  |  | /  /    /    ___   \   |   ___   \   |   _______/   |  ______|  |  |  \   \
	  .   /   /        |  |/  /    /    /   \   \  |  |   \   \  |  (______     |  |_____   |  |__/   /
	  .   |  |         |     /     |   /     \  |  |  |    |  |   \        \    |        |  |      __/
	  .   |  |         |     \     |   \     /  |  |  |    |  |    \______  \   |  ______|  |      \
	  .   \   \_____   |  |\  \    \    \___/   /  |  |___/   /    _______) |   |  |_____   |   |\  \
	  .    \        \  |  | \  \    \          /   |         /    /         /   |        |  |   | \  \
	  .     \_______/  |__|  \__\    \________/    |________/     \________/    |________|  |___|  \__\
 */