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
int arr[500005];

set<ll> low; //either values are ans or ans+1. ans in low
ll offset1,offset2; //actual f(x) is offset1*val+offset2
ii range;
int ans;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n;
		rep(x,0,n) cin>>arr[x];
		
		low.clear();
		ans=0;
		
		offset1=1,offset2=0;
		range=ii(0,-1); //range contains nothing
		
		rep(x,0,n){
			offset2+=offset1*arr[x];
			offset1*=-1;
			
			swap(range.fi,range.se);
			
			while (!low.empty() && ((*(low.begin())-offset2)*offset1<=0 || arr[x]<=(*(low.begin())-offset2)*offset1)) low.erase(low.begin());
			while (!low.empty() && ((*(low.rbegin())-offset2)*offset1<=0 || arr[x]<=(*(low.rbegin())-offset2)*offset1)) low.erase(--low.end());			
			
			//cout<<"offsets: "<<offset1<<" "<<offset2<<endl;
			//cout<<(range.fi-offset2)*offset1<<" "<<(range.se-offset2)*offset1<<endl;
			
			if (offset1==1){
				range.se=min(range.se,arr[x]-1+offset2);
				range.fi=max(range.fi,1+offset2);
			}
			else{
				range.se=max(range.se,-(arr[x]-1)+offset2);
				range.fi=min(range.fi,-(1)+offset2);
			}
			
			//cout<<(range.fi-offset2)*offset1<<" "<<(range.se-offset2)*offset1<<endl;
			
			if (arr[x]%2==0 && (low.count(offset1*arr[x]/2+offset2) || ((range.fi-offset2)*offset1<=arr[x]/2 && arr[x]/2<=(range.se-offset2)*offset1))){
				low.clear();
				range=ii(offset1*(0)+offset2,offset1*(-1)+offset2);
				ans--;
			}
			if (arr[x]%2==0) low.insert(offset1*arr[x]/2+offset2);
			ans++;
			
			if (low.empty() && range.fi*offset1>range.se*offset1){
				range=ii(offset1*(1)+offset2,offset1*(arr[x]-1)+offset2);
				ans++;
			}
			
			//cout<<"debug: "<<ans<<endl;
			//for (auto &it:low) cout<<(it-offset2)*offset1<<" "; cout<<endl;
			//cout<<(range.fi-offset2)*offset1<<" "<<(range.se-offset2)*offset1<<endl;
		}
		
		cout<<ans<<endl;
	}
}