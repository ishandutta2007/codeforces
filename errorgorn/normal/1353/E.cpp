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
#define debug(x) cout << #x << " is " << x << endl;

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

ll MAX(ll a){return a;}
ll MIN(ll a){return a;}
template<typename... Args>
ll MAX(ll a,Args... args){return max(a,MAX(args...));}
template<typename... Args>
ll MIN(ll a,Args... args){return min(a,MIN(args...));}

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>

struct cmp{
	operator() (ii i,ii j){
		if (i.se-i.fi!=j.se-j.fi) return i.se-i.fi<j.se-j.fi;
		return i.fi>j.fi;
	}
};

int n,k;
string s;
int pre[1000005];
ii w[1000005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n>>k;
		cin>>s;
		s="$"+s;
		
		rep(x,1,n+1){
			pre[x]=pre[x-1]+(s[x]=='1');
		}
		
		ll ans=pre[n];
		
		rep(x,n+1,1){
			if (n<x+k){
				w[x]=ii(
					pre[n]-pre[x]+(s[x]=='1'),
					pre[n]-pre[x]+(s[x]=='0')
				);
			}
			else{
				w[x]=ii(
					w[x+k].fi+pre[x+k-1]-pre[x]+(s[x]=='1'),
					min(w[x+k].fi,w[x+k].se)+pre[x+k-1]-pre[x]+(s[x]=='0')
				);
			}
			
			ans=min(ans,w[x].se+pre[x-1]);
		}
		
		cout<<ans<<endl;
	}
}