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

const int INF=2*1e9;

int R,G,B;
vector<int> r,g,b;

ll sq(ll i){return i*i;}

ll eval (ll a,ll b,ll c){
	if (a==-INF || a==INF) return 1e19;
	if (b==-INF || b==INF) return 1e19;
	if (c==-INF || c==INF) return 1e19;
	return sq(a-b)+sq(b-c)+sq(a-c);
}

ll zzz(){
	ll ans=1e19;
	
	int it1=0,it2=0;
	
	rep(x,1,r.size()-1){
		while (b[it1+1]<r[x]) it1++;
		while (g[it2+1]<r[x]) it2++;
		
		ans=MIN(ans,
			eval(r[x],b[it1],g[it2]),
			eval(r[x],b[it1+1],g[it2]),
			eval(r[x],b[it1],g[it2+1]),
			eval(r[x],b[it1+1],g[it2+1]));
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int TC;
	cin>>TC;
	while (TC--){
		r.clear(),g.clear(),b.clear();
		
		r.push_back(-INF),r.push_back(INF);
		g.push_back(-INF),g.push_back(INF);
		b.push_back(-INF),b.push_back(INF);
		
		cin>>R>>G>>B;
		
		int temp;
		
		rep(x,0,R) cin>>temp,r.push_back(temp);
		rep(x,0,G) cin>>temp,g.push_back(temp);
		rep(x,0,B) cin>>temp,b.push_back(temp);
		
		sort(all(r));
		sort(all(g));
		sort(all(b));
		
		ll ans=1e19;
		
		ans=min(ans,zzz());
		swap(r,g);
		ans=min(ans,zzz());
		swap(r,b);
		ans=min(ans,zzz());
		
		cout<<ans<<endl; 
	}
}