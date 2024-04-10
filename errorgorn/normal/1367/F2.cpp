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

int n;
int arr[200005];
map<int,vector<int> > m;


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int TC;
	cin>>TC;
	while (TC--){
		m.clear();
		
		cin>>n;
		rep(x,0,n){
			cin>>arr[x];
			
			if (!m.count(arr[x])){
				m[arr[x]]=vector<int>();
			}
			
			m[arr[x]].push_back(x);
		}
		
		int ans=0;
		
		int lp,rp=n+5;
		int num=0;
		int lnode;
		for (auto &it:m){
			//cout<<it.fi<<endl;
			
			if (rp<it.se[0]){
				rp=it.se.back();
				num+=sz(it.se);
			}
			else{
				rp=it.se.back();
				num=sz(it.se);
				lp=it.se[0];
				lnode=it.fi;
			}
			
			int cnum=num;
			
			if (m.lower_bound(lnode)!=m.begin()){
				map<int,vector<int> >::iterator zzz=prev(m.lower_bound(lnode));
				for (auto &it2:zzz->se){
					if (it2<lp) cnum++;
				}
			}
			
			if (m.lower_bound(it.fi+1)!=m.end()){
				map<int,vector<int> >::iterator zzz=m.lower_bound(it.fi+1);
				for (auto &it2:zzz->se){
					if (rp<it2) cnum++;
				}
			}
			
			if (m.lower_bound(it.fi+1)!=m.end()){
				vector<ii> v;
				
				for (auto &it2:it.se){
					v.push_back(ii(it2,0));
				}
				for (auto &it2:m.lower_bound(it.fi+1)->se){
					v.push_back(ii(it2,1));
				}
				
				sort(all(v));
				
				vector<int> v1(sz(v),0);
				vector<int> v2(sz(v),0);
				
				rep(x,0,sz(v)){
					if (x!=0) v1[x]=v1[x-1];
					if (v[x].se==0) v1[x]++;
				}
				rep(x,sz(v),0){
					if (x!=sz(v)-1) v2[x]=v2[x+1];
					if (v[x].se==1) v2[x]++;
				}
				
				rep(x,1,sz(v)) cnum=max(cnum,v1[x-1]+v2[x]);
			}
			
			ans=max(ans,cnum);
		}
		
		cout<<n-ans<<endl;
	}
}