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
#define debug(x) cout << #x << " is " << x << endl;

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

ll MAX(ll a){return a;}
ll MIN(ll a){return a;}
template<typename... Args>
ll MAX(ll a,Args... args){return max(a,MAX(args...));}
template<typename... Args>
ll MIN(ll a,Args... args){return min(a,MIN(args...));}

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

ll dat[1000005];
void upd(int i,ll j){
	i++;

	while (i<1000005){
		dat[i]+=j;
		i+=i&-i;
	}
}

ll query(int i){
	ll res=0;
	
	while (i){
		res+=dat[i];
		i-=i&-i;
	}
	
	return res;
}

ll query(int i,int j){
	return query(j+1)-query(i);
}

int n,q;
int arr[1000005];
int l[1000005];
int r[1000005];

vector<int> proc;
vector<int> stk;

ll ans[1000005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>q;
	rep(x,0,n) cin>>arr[x];
	rep(x,0,q) cin>>l[x];
	rep(x,0,q) cin>>r[x];
	rep(x,0,q) l[x]--,r[x]--;
	rep(x,0,q) proc.push_back(x);
	
	//left first
	sort(all(proc),[](int i,int j){
		return r[i]<r[j];
	});
	
	ll curr=-1;
	for (auto &it:proc){
		while (curr<r[it]){
			curr++;
			
			while (!stk.empty() && arr[stk.back()]<arr[curr]){
				upd(stk.back(),curr);
				stk.pop_back();
			}
			
			stk.push_back(curr);
			upd(curr,-curr);
		}
		
		int idx=sz(stk);
		
		rep(x,20,0){
			if (idx>=(1<<x) && stk[idx-(1<<x)]>=l[it]) idx-=(1<<x);
		}
		
		ans[it]+=query(l[it],curr)+(curr+1)*(sz(stk)-idx);
	}
	
	//rep(x,0,q) cout<<ans[x]<<" ";cout<<endl;
	
	//proc right
	memset(dat,0,sizeof(dat));
	stk.clear();
	
	sort(all(proc),[](int i,int j){
		return l[i]>l[j];
	});
	
	curr=n;
	for (auto &it:proc){
		while (curr>l[it]){
			curr--;
			
			while (!stk.empty() && arr[stk.back()]<arr[curr]){
				upd(stk.back(),-curr);
				stk.pop_back();
			}
			
			stk.push_back(curr);
			upd(curr,curr);
		}
		
		int idx=sz(stk);
		
		rep(x,20,0){
			if (idx>=(1<<x) && stk[idx-(1<<x)]<=r[it]) idx-=(1<<x);
		}
		
		ans[it]+=query(curr,r[it])-(curr-1)*(sz(stk)-idx);
	}
	
	//rep(x,0,q) cout<<ans[x]<<" ";cout<<endl;
	
	rep(x,0,q) cout<<ans[x]-(r[x]-l[x]+1)<<" ";cout<<endl;
}