// Super Idol
//    
//  
//    
//  105C
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
#define debug(x) cout << #x << ": " << x << endl

#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define lb lower_bound
#define ub upper_bound

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int fen[100005];

void upd(int i,int j){
	while (i<100005){
		fen[i]+=j;
		i+=i&-i;
	}
}

int query(int i){
	int res=0;
	while (i){
		res+=fen[i];
		i-=i&-i;
	}
	return res;
}

int n;
string s,t;
string ss;
vector<int> pos[26];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		rep(x,0,26) pos[x].clear();
		
		cin>>n;
		cin>>s>>t;
		
		ss=s;
		sort(all(ss));
		
		if (ss>=t){
			cout<<"-1"<<endl;
			continue;
		}
		
		s="$"+s;
		t="$"+t;
		
		rep(x,n+1,1){
			pos[s[x]-'a'].pub(x);
		}
		
		rep(x,1,n+1) fen[x]=0;
		rep(x,1,n+1){
			upd(x,1);
		}
		
		ll ans=1e18;
		
		ll curr=0;
		rep(x,1,n+1){
			//cout<<"debug: "<<curr<<endl;
			
			int a=t[x]-'a';
			
			int mn=1e9;
			rep(x,0,a) if (!pos[x].empty()) mn=min(mn,pos[x].back());
			if (mn!=1e9) ans=min(ans,curr+query(mn)-x);
			
			if (pos[a].empty()) break;
			mn=pos[a].back();
			pos[a].pob();
			
			//cout<<"hi: "<<mn<<endl;
			curr+=query(mn)-x;
			upd(1,1);
			upd(mn,-1);
		}
		
		cout<<ans<<endl;
	}
}