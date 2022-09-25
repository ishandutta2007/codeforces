/*













*/

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

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int mex(int i,int j){
	if (i>j) swap(i,j);
	if (i==0 && j==1) return 2;
	if (i==0) return 1;
	else return 0;
}

int memo[305];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	ii state={1,0};
	
	int T;
	cin>>T;
	while (T--){
		ll s,e;
		cin>>s>>e;
		
		ii win={1,2};
		ii lose={0,1};
		
		while (e){
			if (s>e/2){
				ii curr;
				if (s%2==e%2) curr={win.fi,lose.fi};
				else curr={win.se,lose.se};
				
				//cout<<curr.fi<<" "<<curr.se<<endl;
				
				ii res={0,0};
				if (state.fi==1){
					if (curr.fi!=0) res.fi=1;
					if (curr.se!=0) res.se=1;
				}
				if (state.se==1){
					if (curr.fi==0) res.fi=1;
					if (curr.se==0) res.se=1;
				}
				
				state=res;
				//cout<<state.fi<<" "<<state.se<<endl;
				break;
			}
			else{
				int curr;
				ii temp;
				
				curr=(e%2==0?win.fi:win.se);
				temp.fi=mex(curr,((e/2)%2==e%2?win.se:win.fi));
				temp.se=mex(curr,temp.fi);
				
				win=temp;
				
				curr=(e%2==0?lose.fi:lose.se);
				temp.fi=mex(curr,((e/2)%2==e%2?lose.se:lose.fi));
				temp.se=mex(curr,temp.fi);
				
				lose=temp;
				
				e/=2;
				//cout<<e<<" "<<win.fi<<" "<<win.se<<endl;
			}
		}
	}
	
	cout<<state.se<<" "<<state.fi<<endl;
}