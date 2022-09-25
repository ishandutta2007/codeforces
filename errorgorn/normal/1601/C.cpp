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

int n,m;
int arr[1000005];
int brr[1000005];

vector<int> extra[1000005];

void dnc(int l,int r,int i,int j){
	if (l>r) return;
	
	int m=l+r>>1;
	
	int best=1e9;
	int opt=-1;
	
	int curr=0;
	rep(x,i,j){
		if (brr[m]>arr[x]) curr++;
	}
	
	rep(x,i,j+1){
		if (best>curr){
			best=curr;
			opt=x;
		}
		
		if (brr[m]<arr[x]) curr++;
		if (brr[m]>arr[x]) curr--;
	}
	
	extra[opt].pub(brr[m]);
	dnc(l,m-1,i,opt);
	dnc(m+1,r,opt,j);
}

int fen[2000005];

void update(int i){
	while (i<2000005){
		fen[i]++;
		i+=i&-i;
	}
}

int query(int i){
	int res=0;
	while (i){
		res+=fen[i];
		i-=i&-i;
	}
	return res;
}

int id[2000005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n>>m;
		rep(x,0,n) cin>>arr[x];
		rep(x,0,m) cin>>brr[x];
		
		sort(brr,brr+m);
		
		rep(x,0,n+1) extra[x].clear();
		
		dnc(0,m-1,0,n);
		
		vector<int> ans;
		rep(x,0,n+1){
			sort(all(extra[x]));
			for (auto &it:extra[x]) ans.pub(it);
			if (x!=n) ans.pub(arr[x]);
		}
		
		//for (auto &it:ans) cout<<it<<" "; cout<<endl;
		
		rep(x,0,n+m) id[x]=x;
		sort(id,id+n+m,[&ans](int i,int j){
			if (ans[i]!=ans[j]) return ans[i]>ans[j];
			else return i>j;
		});
		
		rep(x,0,n+m+1) fen[x]=0;
		
		ll res=0;
		rep(x,0,n+m){
			//cout<<"debug: "<<id[x]<<" "<<query(id[x]+1)<<endl;
			res+=query(id[x]+1);
			update(id[x]+1);
		}
		
		cout<<res<<endl;
	}
}