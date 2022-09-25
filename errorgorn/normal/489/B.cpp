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

int n1,n2;
vector<int> v1,v2;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int t;
	
	cin>>n1;
	
	rep(x,0,n1){
		cin>>t;
		v1.push_back(t);
	}
	
	cin>>n2;
	
	rep(x,0,n2){
		cin>>t;
		v2.push_back(t);
	}
	
	sort(all(v1));
	sort(all(v2));
	
	int ans=0;
	while (!v1.empty() && !v2.empty()){
		if (v1.back()+1<v2.back()) v2.pop_back();
		else if (v2.back()+1<v1.back()) v1.pop_back();
		else ans++,v1.pop_back(),v2.pop_back();
	}
	
	cout<<ans<<endl;
}