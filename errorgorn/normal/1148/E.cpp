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

int n;
ii arr[300005];
int brr[300005];

vector<ii> v;
vector<tuple<int,int,int> > ans;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n;
	rep(x,0,n){
		cin>>arr[x].fi;
		arr[x].se=x;
	}
	rep(x,0,n) cin>>brr[x];
	
	sort(arr,arr+n);
	sort(brr,brr+n);
	
	rep(x,0,n){
		if (arr[x].fi<brr[x]) v.push_back(ii(brr[x]-arr[x].fi,arr[x].se));
		else{
			int temp=arr[x].fi-brr[x];
			
			while (temp!=0){
				if (v.empty()){
					cout<<"NO"<<endl;
					return 0;
				}
				
				if (v.back().fi<=temp){
					ans.push_back({v.back().se,arr[x].se,v.back().fi});
					temp-=v.back().fi;
					v.pop_back();
				}
				else{
					ans.push_back({v.back().se,arr[x].se,temp});
					v.back().fi-=temp;
					temp=0;
				}
			}
		}
	}
	
	if (!v.empty()){
		cout<<"NO"<<endl;
		return 0;
	}
	
	cout<<"YES"<<endl;
	cout<<sz(ans)<<endl;
	for (auto &it:ans){
		int a,b,c;
		tie(a,b,c)=it;
		cout<<a+1<<" "<<b+1<<" "<<c<<endl;
	}
}