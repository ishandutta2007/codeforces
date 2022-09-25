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

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int TC;
	cin>>TC;
	while (TC--){
		string st;
		cin>>st;
		
		int ans=0;
		
		set<ii> s;
		ii pos=ii(0,0);
		ii path;
		
		rep(x,0,sz(st)){
			if (st[x]=='N'){
				path=ii(pos.fi+1000000,pos.se);	
				pos.fi++;
			}
			else if (st[x]=='E'){
				path=ii(pos.fi,pos.se);
				pos.se++;
			}
			else if (st[x]=='S'){
				pos.fi--;
				path=ii(pos.fi+1000000,pos.se);
			}
			else{
				pos.se--;
				path=ii(pos.fi,pos.se);
			}
			
			if (s.count(path)) ans++;
			else ans+=5;
			s.insert(path);
		}
		
		cout<<ans<<endl;
		
	}
}