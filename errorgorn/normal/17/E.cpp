#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#define ll long long
#define ii pair<int,int>
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

const int MOD=51123987;

int n;
string s;

struct custom_map{
	vector<ii> v;
	
	custom_map(){}
	
	void clear(){v.clear();}
	
	bool count(int i){
		for (auto &it:v) if (it.fi==i) return true;
		return false;
	}
	
	int set(int i,int j){
		v.push_back(ii(i,j));
	}
	
	int get(int i){
        for (auto &it:v) if (it.fi==i) return it.se;
    }
};

custom_map edges[2000005];
int backedge[2000005];
int len[2000005];
int depth[2000005];

int PREV;
int INDEX;

ll l[2000005];
ll r[2000005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>s;
	
	for (int x=0;x<2000005;x++) edges[x].clear();
	
	PREV=0;
	INDEX=1;
	backedge[0]=0,backedge[1]=0;
	len[0]=-1,len[1]=0;
	depth[0]=0,depth[1]=0;

	rep(x,0,n){
		while (s[x-len[PREV]-1]!=s[x]) 
			PREV=backedge[PREV];
		
		if (!edges[PREV].count(s[x]-'a')) 
			edges[PREV].set(s[x]-'a',++INDEX);
		int curr=edges[PREV].get(s[x]-'a');
		len[curr]=len[PREV]+2;
		
		if (len[curr]==1){
			backedge[curr]=1;
		}
		else{
			int b=backedge[PREV];
			while (s[x-len[b]-1]!=s[x]) b=backedge[b];
			backedge[curr]=edges[b].get(s[x]-'a');
		}
		
		depth[curr]=depth[backedge[curr]]+1;
		r[x]=depth[curr];
		
		PREV=curr;
	}
	
	for (int x=0;x<2000005;x++) edges[x].clear();
	
	PREV=0;
	INDEX=1;
	backedge[0]=0,backedge[1]=0;
	len[0]=-1,len[1]=0;
	depth[0]=0,depth[1]=0;

	reverse(all(s));
	rep(x,0,n){
		while (s[x-len[PREV]-1]!=s[x]) 
			PREV=backedge[PREV];
		
		if (!edges[PREV].count(s[x]-'a'))
			edges[PREV].set(s[x]-'a',++INDEX);
		int curr=edges[PREV].get(s[x]-'a');
		len[curr]=len[PREV]+2;
		
		if (len[curr]==1){
			backedge[curr]=1;
		}
		else{
			int b=backedge[PREV];
			while (s[x-len[b]-1]!=s[x]) b=backedge[b];
			backedge[curr]=edges[b].get(s[x]-'a');
		}

		depth[curr]=depth[backedge[curr]]+1;
		l[n-x-1]=depth[curr];
		
		PREV=curr;
	}
	
	//rep(x,0,n) cout<<l[x]<<" "<<r[x]<<endl;
	
	rep(x,1,n) r[x]=(r[x-1]+r[x])%MOD;
	
	
	ll ans=((r[n-1]-1)*r[n-1]/2)%MOD;
	rep(x,1,n) ans-=(r[x-1]*l[x])%MOD;
	
	ans=(ans%MOD+MOD)%MOD;
	
	cout<<ans<<endl;

}