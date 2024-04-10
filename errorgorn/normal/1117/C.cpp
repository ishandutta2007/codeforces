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

ll x1,y1;
ll x2,y2;

int n;
string s;

ii pos[100005];

bool can(ll i){
	ii curr={pos[n].fi*(i/n)+pos[i%n].fi,pos[n].se*(i/n)+pos[i%n].se};

	if (abs(x2-curr.fi)+abs(y2-curr.se)<=i) return true;
	else return false;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>x1>>y1;
	cin>>x2>>y2;
	
	x2-=x1;
	y2-=y1;
	
	cin>>n>>s;
	
	rep(x,0,n){
		ii temp=pos[x];
		
		if (s[x]=='U') temp.se++;
		else if (s[x]=='D') temp.se--;
		else if (s[x]=='L') temp.fi--;
		else temp.fi++;
		
		pos[x+1]=temp;
	}
	
	ll lo=-1,hi=1e18,mi;
	
	while (hi-lo>1){
		mi=hi+lo>>1;
		
		if (can(mi)) hi=mi;
		else lo=mi;
	}
	
	if (hi==1000000000000000000) hi=-1;
	cout<<hi<<endl;
}