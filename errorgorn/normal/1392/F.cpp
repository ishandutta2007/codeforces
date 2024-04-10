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

ll n;
ll arr[1000005];
ll total=0;

vector<ll> stk={-1};
ll pre;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	rep(x,0,n){
		cin>>arr[x];
		total+=arr[x];
		
		if (x==0){
			pre=arr[x];
			continue;
		}
		
		ll curr=arr[x];
		while (stk.back()!=-1 && pre+2<=curr){
			if (x-stk.back()<=curr-pre-1){
				pre++;
				curr-=x-stk.back()-1;
				stk.pop_back();
			}
			else{
				ll temp=stk.back();
				stk.pop_back();
				stk.push_back(temp+curr-pre-1);
				curr=pre+1;
			}
		}
		
		ll times=(curr-pre-1)/(x+1);
		pre+=times;
		curr-=times*x;
		
		if (curr-pre>=2){
			ll tt=curr-pre-1;
			ll temp=stk.back();
			stk.push_back(temp+tt);
			curr-=tt;
		}
		
		if (pre==curr) stk.push_back(x);
		pre=curr;
		
		//for (auto &it:stk) cout<<it<<" "; cout<<endl;
		//cout<<pre<<endl;
	}
	
	rep(x,n,0){
		arr[x]=arr[x+1]-1;
		
		if (stk.back()==x){
			arr[x]++;
			stk.pop_back();
		}
	}
	
	ll ctotal=0;
	
	rep(x,0,n){
		//cout<<arr[x]<<" ";
		ctotal+=arr[x];
	}
	
	rep(x,0,n){
		cout<<arr[x]+(total-ctotal)/n<<" ";
	}
}