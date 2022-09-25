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

#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define lb lower_bound
#define up upper_bound

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int n;
int cnt=1;
ll w[400005];
ii tkd[400005][20];
ii tkd2[400005][20];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	memset(tkd,-1,sizeof(tkd));
	memset(tkd2,-1,sizeof(tkd2));
	tkd[1][0]=ii(-1,0);
	tkd2[1][0]=ii(-1,0);
	
	cin>>n;
	
	ll last=0;
	ll a,b;
	rep(x,0,n){
		cin>>a;
		if (a==1){
			cin>>a>>b;
			a^=last,b^=last;
			//cout<<"upd: "<<a<<" "<<b<<endl;
			
			cnt++;
			w[cnt]=b;
			tkd[cnt][0]=ii(a,w[a]);
			ll curr=a;
			ll we=w[a];
			rep(x,0,20){
				if (curr==-1 || tkd[curr][x].se==-1) continue;
				tie(curr,we)=tkd[cnt][x+1]=ii(tkd[curr][x].fi,max(tkd[curr][x].se,we));
			}
			
			curr=cnt;
			rep(x,20,0){
				if (tkd[curr][x].fi!=-1 && tkd[curr][x].se<w[cnt]) curr=tkd[curr][x].fi;
			}
			curr=tkd[curr][0].fi;
			
			//cout<<"parent: "<<curr<<endl;
			
			tkd2[cnt][0]=ii(curr,w[cnt]);
			we=w[cnt];
			rep(x,0,20){
				if (curr==-1 || tkd2[curr][x].se==-1) continue;
				tie(curr,we)=tkd2[cnt][x+1]=ii(tkd2[curr][x].fi,we+tkd2[curr][x].se);
			}
		}
		else{
			cin>>a>>b;
			a^=last,b^=last;
			//cout<<"debug: "<<a<<" "<<b<<" "<<tkd2[a][0].se<<endl;
			
			int ans=0;
			int curr=a;
			rep(x,20,0){
				if (curr!=-1 && tkd2[curr][x].se!=-1 && tkd2[curr][x].se<=b){
					b-=tkd2[curr][x].se;
					curr=tkd2[curr][x].fi;
					ans+=1<<x;
				}
			}
			
			last=ans;
			cout<<ans<<endl;
		}
	}
}