// Super Idol
//    
//  
//    
//  105C
// 

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

#define int long long
#define ll long long
#define ii pair<ll,ll>
#define iii pair<ii,ll>
#define fi first
#define se second
#define endl '\n'
#define debug(x) cout << #x << ": " << x << endl

#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define lb lower_bound
#define ub upper_bound

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

#define ld long double

struct UFDS{
	int p[2005];
	
	UFDS(){
		rep(x,0,2005) p[x]=x;
	}
	
	int par(int i){
		if (p[i]==i) return i;
		else return p[i]=par(p[i]);
	}
	
	bool unions(int i,int j){
		i=par(i),j=par(j);
		if (i==j) return false;
		p[i]=j;
		return true;
	}
} ufds;

int n;
ii arr[2005];
int p[2005];

const ld TAU=4*acos(0);

ld calc(int i){
	return atan2((ld)arr[i].fi,(ld)arr[i].se);
}

ld fix(ld i){
	if (i<0) i+=TAU;
	return i;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n;
	rep(x,1,n+1){
		cin>>arr[x].fi>>arr[x].se>>p[x];
	}
	
	int bad=-1;
	rep(x,1,n+1) if (p[x]!=x) bad=x;
	
	if (bad==-1){
		cout<<0<<endl;
		return 0;
	}
	
	rep(x,1,n+1) if (x!=bad){
		arr[x].fi-=arr[bad].fi;
		arr[x].se-=arr[bad].se;
	}
	
	deque<int> idx;
	rep(x,1,n+1) if (x!=bad) idx.pub(x);
	
	sort(all(idx),[](int i,int j){
		return calc(i)<calc(j);
	});
	
	ld mx=0;
	rep(x,0,sz(idx)){
		mx=max(mx,fix(calc(idx[(x+1)%sz(idx)])-calc(idx[x])));
	}
	
	while (fix(calc(idx[0])-calc(idx[sz(idx)-1]))!=mx){
		idx.pub(idx.front());
		idx.pof();
	}
	
	rep(x,1,n+1) ufds.unions(x,p[x]);
	
	vector<ii> ans;
	
	rep(x,0,sz(idx)-1){
		if (ufds.unions(idx[x],idx[x+1])){
			ans.pub({idx[x],idx[x+1]});
			swap(p[idx[x]],p[idx[x+1]]);
		}
	}
	
	rep(x,1,n){
		ans.pub({bad,p[bad]});
		p[bad]=p[p[bad]];
	}
	
	cout<<sz(ans)<<endl;
	for (auto it:ans) cout<<it.fi<<" "<<it.se<<endl;
}