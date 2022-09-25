//
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

const int P=10000019,MOD=1000000007;

int n,k,q;
int val[15005];
int w[15005];
int tl[15005];
int tr[15005];

void solve(vector<int> idx,vector<int> memo,int l,int r){
	int m=l+r>>1;
	
	vector<int> idxl,idxr;
	for (auto it:idx){
		if (tl[it]<=l && r<=tr[it]){
			rep(x,sz(memo),0) if (x>=w[it]) memo[x]=max(memo[x],memo[x-w[it]]+val[it]);
		}
		else if (tr[it]<=m) idxl.pub(it);
		else if (m<tl[it]) idxr.pub(it);
		else idxl.pub(it),idxr.pub(it);
	}
	
	if (l==r){
		int ans=0,curr=1;
		rep(x,1,k+1){
			ans=(ans+curr*memo[x])%MOD;
			curr=(curr*P)%MOD;
		}
		
		cout<<ans<<endl;
	}
	else{
		solve(idxl,memo,l,m);
		solve(idxr,memo,m+1,r);
	}
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>k;
	rep(x,1,n+1) cin>>val[x]>>w[x];
	
	memset(tr,63,sizeof(tr));
	
	cin>>q;
	int T=0,a,b;
	rep(x,0,q){
		cin>>a;
		
		if (a==1){
			cin>>a>>b;
			n++;
			val[n]=a;
			w[n]=b;
			tl[n]=T;
		}
		else if (a==2){
			cin>>a;
			tr[a]=T-1;
		}
		else{
			T++;
		}
	}
	
	vector<int> idx;
	rep(x,1,n+1) idx.pub(x);
	vector<int> memo;
	rep(x,0,k+1) memo.pub(0);
	
	solve(idx,memo,0,T-1);
}