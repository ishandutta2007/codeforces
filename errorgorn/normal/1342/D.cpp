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

int n,k;
int w[200005];
int arr[200005];

vector<int> tc[200005];

bool ok (int i){
	rep(x,0,i) tc[x].clear();
	
	rep(x,0,n){
		tc[x%i].push_back(w[x]);
		if (arr[w[x]]<=x/i) return false;
	}
	
	return true;
}

void print_ans(int i){
	cout<<i<<endl;
	rep(x,0,i){
		cout<<tc[x].size()<<" ";
		for (auto &it:tc[x]) cout<<it<<" ";
		cout<<endl;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>k;
	rep(x,0,n) cin>>w[x];
	rep(x,1,k+1) cin>>arr[x];
	
	sort(w,w+n);
	reverse(w,w+n);
	
	if (ok(1)){
		print_ans(1);
	}
	else{
		int lo=1,hi=n,mi;
		
		while (hi-lo>1){
			mi=hi+lo>>1;
			if (ok(mi)) hi=mi;
			else lo=mi;
		}
		
		ok(hi);
		print_ans(hi);
	}
	
}