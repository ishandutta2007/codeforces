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

int n;
int p[100005];
int res[100005];
int arr[100005];

void conv(int *a,int *b,int *c){
	int res[100005];
	
	rep(x,1,n+1) res[x]=b[a[x]];
	rep(x,1,n+1) c[x]=res[x];
}

bool has[100005];

vector<int> pos[100005];
set<int> alive;
int ans[100005];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n;
	rep(x,1,n+1) cin>>p[x];
	rep(x,1,n+1) cin>>arr[x];
	
	int num=0;
	rep(x,1,n+1) num=max(num,arr[x]);
	
	int d=0;
	rep(x,1,n+1){
		if (has[p[x]]) d++;
		has[p[x]]=true;
	}
	
	num=(num-n)/d;
	
	//cout<<num<<" "<<d<<endl;
	
	rep(x,1,n+1) res[x]=x;
	while (num){
		if (num&1) conv(res,p,res);
		conv(p,p,p);
		num>>=1;
	}
	
	//rep(x,1,n+1) cout<<res[x]<<" "; cout<<endl;
	
	rep(x,1,n+1) pos[res[x]].pub(x);
	
	memset(has,false,sizeof(has));
	
	vector<int> idx;
	rep(x,1,n+1) if (sz(pos[x])){
		ans[pos[x].front()]=arr[x];
		idx.pub(x);
		has[arr[x]]=true;
	}
	
	sort(all(idx),[](int i,int j){
		return arr[i]>arr[j];
	});
	
	rep(x,1,n+1) if (!has[x]){
		while (!idx.empty() && arr[idx.back()]<x){
			int temp=idx.back(); idx.pob();
			rep(y,1,sz(pos[temp])) alive.insert(pos[temp][y]);
		}
		
		ans[*alive.begin()]=x;
		alive.erase(alive.begin());
	}
	
	rep(x,1,n+1) cout<<ans[x]<<" "; cout<<endl;
}