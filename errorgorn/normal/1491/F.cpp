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
#define debug(x) cout << #x << " is " << x << endl

#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define lb lower_bound
#define up upper_bound

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());


int q(vector<int> a,vector<int> b){
	cout<<"? "<<sz(a)<<" "<<sz(b)<<endl;
	for (auto &it:a) cout<<it<<" "; cout<<endl;
	for (auto &it:b) cout<<it<<" "; cout<<endl;
	
	int temp;
	cin>>temp;
	return temp;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	
	while (TC--){
		int n;
		set<int> bad;
		set<int> good;
		cin>>n;
		
		int fin=-1;
		
		vector<int> v={1};
		rep(x,2,n){
			if (q(v,{x})!=0){
				fin=x;
				break;
			}
			v.pub(x);
		}
		
		if (fin==-1) fin=n;
		bad.insert(fin);
		
		rep(x,fin+1,n+1){
			if (q({fin},{x})!=0){
				bad.insert(x);
			}
		}
		
		int idx=0;
		for (int x=1<<13;x;x>>=1){
			if (idx+x<fin){
				vector<int> v;
				rep(y,1,idx+x+1) v.pub(y);
				if (q(v,{fin})==0) idx+=x;
			}
		}
		
		bad.insert(idx+1);
		
		rep(x,1,n+1) if (!bad.count(x)) good.insert(x);
		
		cout<<"! "<<sz(good)<<" ";
		for (auto &it:good) cout<<it<<" "; cout<<endl;
	}
}