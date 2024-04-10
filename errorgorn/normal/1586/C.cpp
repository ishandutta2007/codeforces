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
#define debug(x) cout << #x << ": " << x << endl

#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define lb lower_bound
#define ub upper_bound

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int n,m,q;
string s[1000005];
int pref[1000005];



int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>m;
	rep(x,0,n) cin>>s[x];
	rep(x,0,n) s[x]="$"+s[x];
	
	rep(x,0,n-1) rep(y,1,m){
		if (s[x+1][y]=='X' && s[x][y+1]=='X') pref[y]=1;
	}
	rep(y,1,m) pref[y]+=pref[y-1];
	
	cin>>q;
	
	
	int a,b;
	while (q--){
		cin>>a>>b;
		
		b--;
		if (b<a) cout<<"YES"<<endl;
		else{
			if (pref[b]-pref[a-1]) cout<<"NO"<<endl;
			else cout<<"YES"<<endl;
		}
	}
}