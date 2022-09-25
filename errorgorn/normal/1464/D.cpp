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

const int MOD=1000000007;

int n;
int arr[1000005];
bool vis[1000005];
vector<int> cyc[3];

ll solve(vector<int> v){
	int cnt[3]={0,0,0};
	int res=0;
	
	for (auto &it:v){
		res+=(it+2)/3-1;
		cnt[it%3]++;
	}
	
	int temp=min(cnt[1],cnt[2]);
	res+=temp;
	cnt[1]-=temp,cnt[2]-=temp;
	return res+cnt[1]/3*2+cnt[2];
}

ll rem(vector<int> cyc[],vector<int> rm,vector<int> v){
	if (rm.empty()){
		rep(x,0,3) for (auto &it:cyc[x]) v.push_back(it);
		return solve(v);
	}
	else{
		int val=rm.back();
		rm.pop_back();
		
		ll res=1e9;
		
		rep(x,0,3){
			if (cyc[x].empty() || cyc[x].back()<val) continue;
			int temp=cyc[x].back();
			cyc[x].pop_back();
			v.push_back(temp-val);
			
			res=min(res,rem(cyc,rm,v));
			v.pop_back();
			cyc[x].push_back(temp);
		}
		
		return res;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n;
		rep(x,1,n+1) cin>>arr[x];
		rep(x,1,n+1) vis[x]=false;
		rep(x,0,3) cyc[x].clear();
		
		int curr=n;
		ll ans=1;
		while (curr>4){
			ans=ans*3%MOD;
			curr-=3;
		}
		if (curr) ans=ans*curr%MOD;
		
		cout<<ans<<" ";
		
		rep(x,1,n+1) if (!vis[x]){
			int curr=x;
			int s=0;
			do{
				vis[curr]=true;
				curr=arr[curr];
				s++;
			} while (!vis[curr]);
			cyc[s%3].push_back(s);
		}
		
		rep(x,0,3) sort(all(cyc[x]));
		
		ans=1e9;
		if (n%3==0){
			vector<int> v;
			rep(x,0,3) for (auto &it:cyc[x]) v.push_back(it);
			ans=solve(v);
		}
		else if (n%3==1){
			//take away 2 2 or 4
			ans=min({rem(cyc,{4},{})+1,
					 rem(cyc,{3,1},{})+3,
					 rem(cyc,{2,2},{})+2,
					 rem(cyc,{2,1,1},{})+4,
					 rem(cyc,{1,1,1,1},{})+6});
		}
		else{
			ans=min({rem(cyc,{2},{})+1,rem(cyc,{1,1},{})+3});
		}
				
		cout<<ans<<endl;
	}
}