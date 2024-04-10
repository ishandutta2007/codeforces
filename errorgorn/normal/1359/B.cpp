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

int n,m,a,b;
string s;
int w[1005];
		
int proc(int i){
	//debug(i);
	return b*(i/2)+a*(i%2);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n>>m>>a>>b;
		
		b=min(b,a*2);
		
		int ans=0;
		rep(iter,0,n){
			cin>>s;
			s='*'+s+'*';
			
			rep(x,1,m+2){
				if (s[x]=='.'){
					w[x]=w[x-1]+1;
				}
				else{
					w[x]=0;
					ans+=proc(w[x-1]);
				}
			}
		}
		
		cout<<ans<<endl;
	}
}