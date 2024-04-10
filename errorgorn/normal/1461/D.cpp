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
int arr[100005];
set<ll> s;

void dnc(int l,int r){
	int m=arr[l]+arr[r]>>1;
	
	int optm=-1;
	ll sum=0;
	rep(x,l,r+1){
		if (arr[x]<=m) optm=x;
		sum+=arr[x];
	}
	
	s.insert(sum);
	if (optm!=r) dnc(l,optm),dnc(optm+1,r);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n>>q;
		rep(x,0,n) cin>>arr[x];
		sort(arr,arr+n);
		s.clear();
		
		dnc(0,n-1);
		
		int a;
		while (q--){
			cin>>a;
			if (s.count(a)) cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
		}
	}
}