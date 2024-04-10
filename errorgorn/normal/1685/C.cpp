//
//

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#define int long long
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

int n;
string s;
int p[200005];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n;
		cin>>s;
		
		n*=2;
		rep(x,0,n){
			p[x+1]=p[x]+(s[x]=='('?1:-1);
		}
		
		bool good=true;
		rep(x,1,n+1) if (p[x]<0) good=false;
		
		if (good){
			cout<<0<<endl;
			continue;
		}
		
		int l=-1,r=-1;
		rep(x,1,n+1){
			if (p[x]<0){
				if (l==-1) l=x;
				r=x;
			}
		}
		
		int mx1=-1,mx2=-1;
		int idx1=-1,idx2=-1;
		rep(x,0,l) if (mx1<p[x]){
			mx1=p[x];
			idx1=x;
		} 
		
		rep(x,r,n+1) if (mx2<p[x]){
			mx2=p[x];
			idx2=x;
		}
		
		int mx3=-1;
		int idx3;
		rep(x,l,r+1) if (mx3<p[x]){
			mx3=p[x];
			idx3=x;
		}
		
		if (mx3<=mx1+mx2){
			cout<<1<<endl;
			cout<<idx1+1<<" "<<idx2<<endl;
		}
		else{
			cout<<2<<endl;
			cout<<1<<" "<<idx3<<endl;
			cout<<idx3+1<<" "<<n<<endl;
		}
	}
}