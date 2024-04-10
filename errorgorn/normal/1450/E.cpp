//
//

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#define ll long long
#define ii pair<ll,ll>
#define iii pair<ii,ll>
#define fi first
#define se second
#define endl '\n'
#define debug(x) cout << #x << " is " << x << endl

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int n,m;
int col[205];
vector<ii> al[205];
ii w[205];
bool inq[205];
queue<int> q;

int best[205];

void dfs_bi(int i){
	for (auto &it:al[i]){
		if (col[it.fi]==-1){
			col[it.fi]=col[i]^1;
			dfs_bi(it.fi);
		}
		else if (col[it.fi]==col[i]){
			cout<<"NO"<<endl;
			exit(0);
		}
	}
}

void sset(int i,ii val){
	ii initial=w[i];
	
	if (w[i]==ii(-1,-1)) w[i]=val;
	else{
		w[i].fi=max(w[i].fi,val.fi);
		w[i].se=min(w[i].se,val.se);
	}
	
	if (w[i]!=initial && !inq[i]){
		inq[i]=true;
		q.push(i);
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>m;
	
	int a,b,c;
	rep(x,0,m){
		cin>>a>>b>>c;
		al[a].push_back(ii(b,c));
		al[b].push_back(ii(a,-c));
	}
	
	memset(col,-1,sizeof(col));
	col[1]=0;
	dfs_bi(1);
	
	int ans=-1;
	ll curr=0;
	
	rep(x,1,n+1){
		while (!q.empty()) q.pop();
		memset(w,-1,sizeof(w));
		memset(inq,false,sizeof(inq));
		w[x]=ii(0,0); //small boy
		inq[x]=true;
		q.push(x);
		
		while (!q.empty()){
			int node=q.front();
			q.pop();
			inq[node]=false;
			for (auto &it:al[node]){
				if (it.se!=0){
					sset(it.fi,ii(w[node].fi+it.se,w[node].se+it.se));
				}
				else{
					sset(it.fi,ii(w[node].fi-1,w[node].se+1));
				}
				
				if (w[it.fi].fi==-1) sset(it.fi,ii(1,w[it.fi].se));
				if (w[it.fi].fi>w[it.fi].se) goto die;
			}
		}
		
		curr=0;
		rep(x,1,n+1) curr=max(curr,w[x].se);
		if (curr>ans){
			ans=curr;
			rep(x,1,n+1) best[x]=w[x].se;
		}
		
		die:;
	}
	
	if (ans==-1){
		cout<<"NO"<<endl;
	}
	else{
		cout<<"YES"<<endl;
		cout<<ans<<endl;
		rep(x,1,n+1) cout<<best[x]<<" "; cout<<endl;
	}
}