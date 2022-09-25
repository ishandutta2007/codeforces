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

string s;

int test(char i,char j){
	bool flag=false;
	int res=0;
	
	rep(x,0,sz(s)){
		if ((!flag && s[x]==i) || (flag && s[x]==j)){
			res++;
			flag^=true;
		}
	}
	
	if (i!=j && flag) res--;
	return res;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int TC;
	cin>>TC;
	
	while (TC--){
		cin>>s;
		
		int ans=0;
		rep(x,'0','9'+1) rep(y,'0','9'+1) ans=max(ans,test(x,y));
		
		cout<<sz(s)-ans<<endl;
	}
}