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

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

const int MOD=1000000007;

int n,m;
vector<ii> al[500005];

vector<int> ans;

int p[500005];
int s[500005];
bool has[500005];

int par(int i){
	if (p[i]==i) return i;
	else return p[i]=par(p[i]);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	rep(x,0,500005){
		p[x]=x;
		s[x]=1;
	}
	
	cin>>n>>m;
	
	int a,b;
	rep(x,0,n){
		cin>>a;
		if (a==1){
			cin>>a;
			
			a=par(a);
			if (!has[a]){
				has[a]=true;
				ans.push_back(x);
			}
		}
		else{
			cin>>a>>b;
			a=par(a),b=par(b);
			
			if (a==b || (has[a] && has[b])) continue;
			
			ans.push_back(x);
			if (s[a]>s[b]) swap(a,b);
			p[a]=b;
			s[b]+=s[a];
			has[b]|=has[a];
		}
	}
	
	ll z=1;
	rep(x,0,sz(ans)) z=(z*2)%MOD;
	cout<<z<<" "<<sz(ans)<<endl;
	for (auto &it:ans) cout<<it+1<<" "; cout<<endl;
}