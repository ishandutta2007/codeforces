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

int n,m;
vector<int> v[10];

vector<ll> bm[11];
ll curr=0;

ll masks[45];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>m;
	
	int a,b;
	rep(x,0,m){
		cin>>a;
		rep(y,0,a){
			cin>>b;
			b--;
			v[x].pub(b);
		}
		reverse(all(v[x]));
	}
	
	bm[0].pub(0);
	
	rep(x,0,m){
		ll af=(1LL<<n)-1;
		ll naf=0;
		int extra=0;
		
		for (auto it:v[x]){
			naf^=(1LL<<it);
			if ((curr&(1LL<<it))==0){
				curr|=(1LL<<it);
				extra++;
			}
		}
		
		af^=naf;
		
		rep(y,0,sz(v[x])){
			masks[y+1]=masks[y]|(1LL<<v[x][y]);
		}
		
		for (auto it:bm[x]){
			int num=__builtin_popcountll(it&naf);
			rep(y,0,extra+1){
				bm[x+1].pub((it&af)|masks[num+y]);
			}
		}
	}
	
	rep(x,0,n){
		masks[x+1]=masks[x]|(1LL<<(n-x-1));
	}
	
	bool can=true;
	bool mx=false;
	
	for (auto it:bm[m]){
		int num=__builtin_popcountll(it);
		
		if (num==n) mx=true;
		if (masks[num]!=it) can=false;
	}
	
	if ((can && mx) || n==1){
		cout<<"ACCEPTED"<<endl;
	}
	else{
		cout<<"REJECTED"<<endl;
	}
}