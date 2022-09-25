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

int mx,y,w;
ll cnt[100005];
map<double,int> cntx,cnty;

int rev(int i){
	vector<int> dig;
	
	while (i){
		dig.push_back(i%10);
		i/=10;
	}
	
	reverse(all(dig));
	
	int pow=1;
	int res=0;
	
	for (auto &it:dig){
		res+=it*pow;
		pow*=10;
	}
	
	return res;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>mx>>y>>w;
	
	rep(x,1,y+1){
		cnty[(double)rev(x)/x]++;
	}
	
	ii ans=ii(1e9,1e9);
	
	ll curr=0;
	rep(x,1,mx+1){
		double val=(double)x/rev(x);
		cntx[val]++;
		curr+=cnty[val];
		
		bool flag=false;
		while (w<=curr){
			double val=(double)rev(y)/y;
			cnty[val]--;
			curr-=cntx[val];
			
			y--;
			flag=true;
		}
		
		if (flag){
			y++;
			
			double val=(double)rev(y)/y;
			cnty[val]++;
			curr+=cntx[val];
		}
		
		//cout<<x<<" "<<y<<endl;
		//cout<<curr<<endl;
		
		if (w>curr) continue;
		
		if (ans.fi*ans.se>(ll)x*y){
			ans=ii(x,y);
		}
	}
	
	if (ans==ii(1e9,1e9)) cout<<"-1"<<endl;
	else cout<<ans.fi<<" "<<ans.se<<endl;
}