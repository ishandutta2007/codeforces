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

int n;
string a;
string b;

int pos[100005];
vector<int> ans;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int TC;
	cin>>TC;
	while (TC--){
		ans.clear();
	
		cin>>n;
		cin>>a;
		cin>>b;
		
		int lo=0,hi=n-1;
		rep(x,0,n){
			if (x%2==0){
				pos[n-x-1]=lo;
				lo++;
			}
			else{
				pos[n-x-1]=hi;
				hi--;
			}
		}
		
		//rep(x,0,n) cout<<pos[x]<<" ";cout<<endl;
		
		bool parity=(n%2==1);
		
		rep(x,0,n){
			ans.push_back(x);
			if ((a[x]==b[pos[x]])==parity) ans.push_back(0);
			parity^=true;
		}
		
		cout<<sz(ans)<<" ";
		for (auto &it:ans) cout<<it+1<<" ";cout<<endl;
	}
}