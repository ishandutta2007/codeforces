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

const ll INF=1e18+100;

ll h,n,q,k;
ll memo[23][10005];

ll pos[100005];
int cost[100005];
bool taken[100005];

set<ii,greater<ii> > s;

vector<ll> step;

ll fix(ll i){
	i%=k;
	if (i<0) i+=k;
	return i;
}

void build(){
	s.clear();
	
	if (!step.empty()){
		rep(x,0,k) memo[sz(step)][x]=memo[sz(step)-1][x];
		
		ll inc=step.back()%k;
		ll gcd=__gcd(inc,k);
		rep(x,0,gcd){
			int curr=x;
			rep(y,0,k/gcd*2){
				memo[sz(step)][(curr+inc)%k]=min(memo[sz(step)][(curr+inc)%k],memo[sz(step)][curr]+step.back());
				curr=(curr+inc)%k;
			}
		}
	}
	
	//rep(x,0,k) cout<<memo[sz(step)][x]<<" "; cout<<endl;
	
	rep(x,0,n) if (!taken[x]){
		if (memo[sz(step)][pos[x]%k]<=pos[x]){
			s.insert(ii(cost[x],-x));
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	memset(memo,63,sizeof(memo));
	memo[0][0]=0;
	
	cin>>h>>n>>q>>k;
	
	rep(x,0,n) cin>>pos[x]>>cost[x],pos[x]--;
	
	build();
	
	ll a,b;
	while (q--){
		cin>>a;
		
		if (a==1){
			cin>>a;
			
			step.push_back(a);
			build();
		}
		else if (a==2){
			cin>>a>>b;
			a--;
			
			if (s.count(ii(cost[a],-a))){
				s.erase(ii(cost[a],-a));
				s.insert(ii(cost[a]-b,-a));
			}
			cost[a]-=b;
		}
		else{
			if (s.empty()){
				cout<<0<<endl;
				continue;
			}
			
			taken[-(*s.begin()).se]=true;
			cout<<(*s.begin()).fi<<endl;
			s.erase(s.begin());
		}
	}
}