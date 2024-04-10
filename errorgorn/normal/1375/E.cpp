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

int n;
int arr[1005];

vector<ii> inv;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	rep(x,0,n) cin>>arr[x];
	
	rep(x,0,n) rep(y,x+1,n) if (arr[x]>arr[y]) inv.push_back(ii(x,y));
	
	sort(all(inv),[](ii i,ii j){
		if (i.fi!=j.fi){
			if (arr[i.fi]!=arr[j.fi]) return arr[i.fi]<arr[j.fi];
			else return i.fi<j.fi;
		}
		else return i.se>j.se;
	});
	
	cout<<sz(inv)<<endl;
	for (auto &it:inv) cout<<it.fi+1<<" "<<it.se+1<<endl;
	
	return 0;
	cout<<"debug: "<<endl;
	for (auto &it:inv) swap(arr[it.fi],arr[it.se]);
	rep(x,0,n) cout<<arr[x]<<" ";
}