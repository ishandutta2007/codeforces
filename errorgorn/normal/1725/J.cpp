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
#define int long long
#define ll long long
#define ii pair<ll,ll>
#define iii tuple<int,int,int>
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

int n;
vector<ii> al[100005];
vector<iii> edges;
unordered_map<int,ii> memo;

bool has[100005];
ii pp[100005];
vector<int> cd[100005];
vector<int> td[100005];

ii dfs(int i,int p,int pw){
	if (memo.count(i<<20|p)) return memo[i<<20|p];
	
	ii res;
	if (!has[i]){
		has[i]=true;
		pp[i]={p,pw};
		
		cd[i]={0,0,0,0};
		td[i]={0,0,0,0};
		
		for (auto [it,w]:al[i]){
			if (it==p) continue;
			
			auto temp=dfs(it,i,w);
			cd[i].pub(temp.fi+w);
			td[i].pub(temp.se);
		}
		
		sort(all(cd[i])); reverse(all(cd[i]));
		sort(all(td[i])); reverse(all(td[i]));
		
		while (sz(cd[i])>4) cd[i].pob();
		while (sz(td[i])>4) td[i].pob();
		
		res={cd[i][0],max(td[i][0],cd[i][0]+cd[i][1])};
	}
	else{
		vector<int> cd=::cd[i];
		vector<int> td=::td[i];
		
		auto temp=dfs(p,i,pw);
		
		if (find(all(cd),temp.fi+pw)!=cd.end()) cd.erase(find(all(cd),temp.fi+pw));
		if (find(all(td),temp.se)!=td.end()) td.erase(find(all(td),temp.se));
		
		temp=dfs(pp[i].fi,i,pp[i].se);
		cd.pub(temp.fi+pp[i].se);
		td.pub(temp.se);
		
		sort(all(cd)); reverse(all(cd));
		sort(all(td)); reverse(all(td));
		
		res={cd[0],max(td[0],cd[0]+cd[1])};
	}
	
	return memo[i<<20|p]=res;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n;
	
	if (n==1){
		cout<<0<<endl;
		return 0;
	}
	
	int a,b,c;
	int tot=0;
	rep(x,1,n){
		cin>>a>>b>>c;
		al[a].pub({b,c});
		al[b].pub({a,c});
		
		edges.pub({a,b,c});
		tot+=c;
	}
	
	int best=1e18;
	for (auto [a,b,c]:edges){
		// cout<<a<<" "<<b<<" "<<c<<endl;
		// cout<<dfs(a,b,c).se<<" "<<dfs(b,a,c).se<<endl;
		
		best=min(best,2*tot-dfs(a,b,c).se-dfs(b,a,c).se-2*c);
	}
	
	rep(x,1,n+1){
		vector<int> cd={0,0,0,0};
		for (auto [it,w]:al[x]) cd.pub(dfs(it,x,w).fi+w);
		
		sort(all(cd)); reverse(all(cd));
		
		int curr=2*tot;
		rep(x,0,4) curr-=cd[x];
		best=min(best,curr);
	}
	
	cout<<best<<endl;
}