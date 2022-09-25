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
set<int> s;
vector<int> v1,v2;

bool canh(int i){
	rep(x,0,i){
		if (v2[x]>v1[n-i+x]) return false;
	}
	return true;
}

bool canl(int i){
	rep(x,0,i){
		if (v2[n-i+x]<v1[x]) return false;
	}
	return true;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		s.clear();
		v1.clear(),v2.clear();
		
		cin>>n;
		rep(x,0,n){
			int t;
			cin>>t;
			t--;
			s.insert(t);
		}
		
		
		rep(x,0,2*n){
			if (s.count(x)) v1.push_back(x);
			else v2.push_back(x);
		}
		
		int lo=0,hi=n+1,mi;
		while (hi-lo>1){
			mi=hi+lo>>1;
			
			if (canh(mi)) lo=mi;
			else hi=mi;
		}
		
		int temp1=lo;
		//cout<<lo<<endl;
		
		lo=0,hi=n+1,mi;
		while (hi-lo>1){
			mi=hi+lo>>1;
			
			if (canl(mi)) lo=mi;
			else hi=mi;
		}
		
		int temp2=lo;
		//cout<<lo<<endl;
		
		cout<<max(temp1+temp2-n+1,0)<<endl;
	}
}