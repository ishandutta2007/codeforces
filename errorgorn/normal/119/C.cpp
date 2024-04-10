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

ll n,m,k;
vector<ii> val[105];
map<ll,ii> memo[105][55];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>m>>k;
	
	ll a,b,c;
	rep(x,0,m){
		cin>>a>>b>>c;
		rep(y,a,b+1){
			val[c].push_back(ii(y,x));
		}
	}
	
	ll px,py,pz;
	ll best=-1;
	
	rep(x,1,101){
		memo[x][1]=memo[x-1][1];
		for (auto &it:val[x]){
			memo[x][1][it.fi]=it;
			if (n==1 && best<it.fi){
				best=it.fi;
				px=x,py=1,pz=it.fi;
			}
		}
		
		rep(y,2,55){
			memo[x][y]=memo[x-1][y];
			for (auto &it:val[x]){
				ll temp=memo[x-1][y-1][it.fi-k].fi;
				if (it.fi%k==0) temp=max(temp,memo[x-1][y-1][it.fi/k].fi);
				
				if (temp==0) continue;
				memo[x][y][it.fi]=ii(temp+it.fi,it.se);
				if (n==y && best<temp+it.fi){
					best=temp+it.fi;
					px=x,py=y,pz=it.fi;
				}
			}
		}
	}
	
	if (best==-1){
		cout<<"NO"<<endl;
		return 0;
	}
	
	cout<<"YES"<<endl;
	vector<ii> v;
	
	while (true){
		//cerr<<px<<" "<<py<<" "<<pz<<" "<<best<<endl;
		
		if (py==1){
			v.push_back({memo[px][py][pz].se,pz});
			break;
		}
		else if (memo[px-1][py][pz].fi==best){
			px--;
		}
		else if (memo[px-1][py-1][pz-k].fi==best-pz){
			v.push_back({memo[px][py][pz].se,pz});
			best-=pz;
			px--,py--,pz-=k;
		}
		else{
			v.push_back({memo[px][py][pz].se,pz});
			best-=pz;
			px--,py--,pz/=k;
		}
	}
	
	reverse(all(v));
	for (auto &it:v){
		tie(a,b)=it;
		cout<<a+1<<" "<<b<<endl;
	}
}