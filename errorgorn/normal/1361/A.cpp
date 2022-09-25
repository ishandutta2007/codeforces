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

int n,m;
vector<int> al[500005];

int ord[500005];
int ans[500005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	
	int a,b;
	rep(x,0,m){
		cin>>a>>b;
		a--,b--;
		al[a].push_back(b);
		al[b].push_back(a);
	}
	
	rep(x,0,n) cin>>ord[x],ans[x]=x;
	
	sort(ans,ans+n,[](int i,int j){
		return ord[i]<ord[j];
	});
	
	rep(x,0,n){
		//debug(ans[x]);
		set<int> s;
		for (auto &it:al[ans[x]]){
			if (ord[it]==ord[ans[x]]){
				cout<<"-1"<<endl;
				return 0;
			}
			else if (ord[it]<ord[ans[x]]){
				s.insert(ord[it]);
			}
		}
		
		//cout<<sz(s)<<endl;
		if (sz(s)!=ord[ans[x]]-1){
			cout<<"-1"<<endl;
			return 0;
		}
	}
	
	rep(x,0,n) cout<<ans[x]+1<<" ";
	
}