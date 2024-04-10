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
#define debug(x) cout << #x << ": " << x << endl

#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int n,k;
set<ii> l={},r={};
int p[200005];
int dir[200005];
int idx[200005];

int ans[100005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>k;
	
	int pp=0;
	int card,la,lb,ra,rb;
	
	p[0]=p[1]=-1;
	dir[0]=0,dir[1]=1;
	idx[0]=idx[1]=-1;
	
	l.insert(ii(0,0));
	r.insert(ii(0,1));
	int IDX=2;
	
	rep(x,0,n){
		cin>>card>>la>>lb>>ra>>rb;
		
		int lcan=-1;
		if (!r.empty()) lcan=(*r.begin()).se;
		int rcan=-1;
		if (!l.empty()) rcan=(*l.begin()).se;
		
		if (ra<=card && card<=rb){
			if (lcan!=-1){
				l.insert(ii(pp,IDX));
				p[IDX]=lcan;
				dir[IDX]=0;
				idx[IDX]=x;
				IDX++;
			}
			while (!l.empty() && (*l.begin()).fi<la) l.erase(l.begin());
			while (!l.empty() && (*--l.end()).fi>lb) l.erase(--l.end());
		}
		else{
			l.clear();
		}
		
		if (la<=card && card<=lb){
			if (rcan!=-1){
				r.insert(ii(pp,IDX));
				p[IDX]=rcan;
				dir[IDX]=1;
				idx[IDX]=x;
				IDX++;
			}
			while (!r.empty() && (*r.begin()).fi<ra) r.erase(r.begin());
			while (!r.empty() && (*--r.end()).fi>rb) r.erase(--r.end());
		}
		else{
			r.clear();
		}
		
		//for (auto &it:l) cout<<it.fi<<" "; cout<<endl;
		//for (auto &it:r) cout<<it.fi<<" "; cout<<endl;
		
		pp=card;
	}
	
	int curr=-1;
	if (sz(l)){
		cout<<"Yes"<<endl;
		curr=(*l.begin()).se;
	}
	else if (sz(r)){
		cout<<"Yes"<<endl;
		curr=(*r.begin()).se;
	}
	else{
		cout<<"No"<<endl;
		return 0;
	}

	int pos=n;
	while (curr!=-1){
		//cout<<dir[curr]<<" "<<idx[curr]<<endl;
		
		rep(x,max(idx[curr],0),pos) ans[x]=dir[curr]^1;
		pos=idx[curr];
		
		curr=p[curr];
	}
	
	rep(x,0,n) cout<<ans[x]<<" "; cout<<endl;
}