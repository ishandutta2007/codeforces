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

string s;
vector<int> pos[600005];
map<ii,int> memo;

int hh(string s){
	int res=0;
	int curr=1;
	
	rep(x,0,sz(s)){
		res+=(s[x]-'a'+1)*curr;
		curr*=27;
	}
	
	return res;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>s;
	
	rep(x,1,5){
		for (int y=0;y+x<=sz(s);y++){
			pos[hh(s.substr(y,x))].push_back(y);
		}
	}
	
	int q;
	string a,b;
	int ha,hb;
	
	cin>>q;
	while (q--){
		cin>>a>>b;
		
		ha=hh(a),hb=hh(b);
		
		if (ha==hb){
			if (!pos[ha].empty()) cout<<sz(a)<<endl;
			else cout<<"-1"<<endl;
			continue;	
		}
		else{
			if (sz(pos[ha])>sz(pos[hb]) ||
			   (sz(pos[ha])==sz(pos[hb]) && ha>hb)){
				swap(a,b);
				swap(ha,hb);
			}
			
			if (memo.count(ii(ha,hb))){
				cout<<memo[ii(ha,hb)]<<endl;
				continue;
			}
			
			int best=1e9;
			
			for (auto &it:pos[ha]){
				auto it2=lower_bound(all(pos[hb]),it);
				
				if (it2!=pos[hb].end()) best=min(best,max(sz(a),*it2-it+sz(b)));
				if (it2!=pos[hb].begin()) best=min(best,max(sz(b),it-*prev(it2)+sz(a)));
			}
			
			if (best==1e9) memo[ii(ha,hb)]=-1;
			else memo[ii(ha,hb)]=best;
			
			cout<<memo[ii(ha,hb)]<<endl;
		}
		
	}
}