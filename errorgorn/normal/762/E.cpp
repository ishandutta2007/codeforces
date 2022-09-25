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
#define endl '\n'
#define debug(x) cout << #x << " is " << x << endl;

#define rep(x,start,end) for(auto x=start-(start>end);x!=end-(start>end);x+=(start<end?1:-1))
#define all(x) x.begin(),x.end()

ll MAX(ll a){return a;}
ll MIN(ll a){return a;}
template<typename... Args>
ll MAX(ll a, Args... args) { return max(a,MAX(args...)); }
template<typename... Args>
ll MIN(ll a, Args... args) { return min(a,MIN(args...)); }

#define indexed_set tree<ll, null_type, less<ll>,rb_tree_tag,tree_order_statistics_node_update>

int n,k;
vector<iii> v;
indexed_set s[10105];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>k;
	
	int a,b,c;
	for (int x=0;x<n;x++){
		cin>>a>>b>>c;
		c+=20;
		v.push_back(iii(ii(a,b),c));
	}
	
	sort(all(v),[](iii i,iii j){
		return i.first.second>j.first.second;
	});
	
	ll ans=0;
	for (auto &it:v){
		for (int x=it.second-k;x<=it.second+k;x++){
			ans+=s[x].order_of_key(it.first.first+it.first.second+1)-s[x].order_of_key(it.first.first-it.first.second);
		}
		s[it.second].insert(it.first.first);
	}
	
	cout<<ans<<endl;
}