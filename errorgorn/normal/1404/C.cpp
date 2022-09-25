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

int n,q;
int arr[300005];

struct Q{
	int l,r;
	int idx;
};

vector<Q> queries;
int ans[300005];

int fen[300005];
void upd(int i,int k){
	while (i<300005){
		fen[i]+=k;
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

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>q;
	rep(x,1,n+1){
		cin>>arr[x];
		
		if (arr[x]>x) arr[x]=1e9;
		else arr[x]=x-arr[x];
	}
	
	int a,b;
	rep(x,0,q){
		cin>>a>>b;
		queries.push_back({a+1,n-b,x});
	}
	
	sort(all(queries),[](Q &i,Q &j){
		return i.r<j.r;
	});
	
	int curr=0;
	for (auto &it:queries){
		while (curr<it.r){
			curr++;
			
			if (query(1)<arr[curr]) continue;
			int lo=1,hi=curr+1,mi;
			
			while (hi-lo>1){
				mi=hi+lo>>1;
				
				if (query(mi)>=arr[curr]) lo=mi;
				else hi=mi;
			}
			//cout<<"update: "<<hi<<" "<<curr<<" "<<query(hi)<<endl; 
			upd(hi,-1);
			upd(1,1);
		}
		
		ans[it.idx]=query(it.l);
	}
	
	rep(x,0,q) cout<<ans[x]<<endl;
}