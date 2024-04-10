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

int n,k;
string s;
string t;
vector<ii> ans;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int TC;
	cin>>TC;
	while (TC--){
		ans.clear();
	
		cin>>n>>k;
		cin>>s;
		
		t="";
		rep(x,0,k-1) t+="()";
		rep(x,0,n/2-k+1) t+="(";
		rep(x,0,n/2-k+1) t+=")";
		
		rep(x,0,n){
			if (s[x]!=t[x]){
				rep(y,x+1,n) if (s[x]!=s[y]){
					swap(s[x],s[y]);
					ans.push_back(ii(x,y));
					break;
				}
			}
		}
		
		
		cout<<sz(ans)<<endl;
		for (auto &it:ans) cout<<it.fi+1<<" "<<it.se+1<<endl;
	}
}