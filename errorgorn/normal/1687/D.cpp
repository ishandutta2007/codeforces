// Super Idol
//    
//  
//    
//  105C
// 

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define ii pair<ll,ll>
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

#define rep(x,start,end) for(int x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int n;
int arr[1000005];

vector<ii> good;

int p[1000005];
ii range[1000005];
int lvl[1000005]; 

int par(int i){
	if (p[i]==i) return i;
	else return p[i]=par(p[i]);
}

vector<ii> upd;

void solve(int l,int r,int dl,int dr){
	if (dl>dr) return;
	
	//cout<<arr[l]<<" "<<arr[r]<<" "<<dl<<" "<<dr<<endl;
	
	rep(x,dl,dr+1){
		int kl=max(good[x].fi-arr[l],0LL),kr=good[x].se-arr[r];
		if (kl<=kr){
			upd.pub({r-l+1,kl});
			upd.pub({-(r-l+1),kr});
		}
	}
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	good.pub({-1,-1});
	good.pub({-1,-1});
	
	int curr=1;
	rep(x,1,2000205){
		good.pub({curr,curr+x});
		curr+=x*2+1;
	}
	
	//rep(x,2,10) cout<<good[x].fi<<" "<<good[x].se<<endl;
	
	cin>>n;
	rep(x,1,n+1) cin>>arr[x];
	
	rep(x,1,n+1) p[x]=x;
	rep(x,1,n+1) range[x]={x,x};
	rep(x,1,n+1) lvl[x]=1;
	
	vector<ii> proc;
	rep(x,1,n) proc.pub({arr[x+1]-arr[x]+1,x});
	
	sort(all(proc));
	
	for (auto [val,l]:proc){
		int r=l+1;
		
		//cout<<val<<" "<<l<<" "<<r<<endl;
		
		l=par(l),r=par(r);
		solve(range[l].fi,range[l].se,lvl[l]+1,val);
		solve(range[r].fi,range[r].se,lvl[r]+1,val);
		
		p[l]=r;
		range[r].fi=range[l].fi;
		lvl[r]=val;
	}
	
	int idx=par(1);
	solve(1,n,lvl[idx]+1,2000100);
	
	curr=0;
	sort(all(upd),[](ii i,ii j){
		if (i.se!=j.se) return i.se<j.se;
		else return i.fi>j.fi;
	});
	
	for (auto it:upd){
		curr+=it.fi;
		if (curr==n){
			cout<<it.se<<endl;
			return 0;
		}
	}
}