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

int n,k;
set<int> s[1005];

int test(vector<int>i){
	cout<<"? "<<sz(i)<<" ";
	rep(x,0,sz(i)) cout<<i[x]<<" ";
	cout<<endl;
	
	int res;
	cin>>res;
	return res;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
		
	int TC;
	
	cin>>TC;
	while (TC--){
		cin>>n>>k;
		
		int a,b;
		rep(x,0,k){
			s[x].clear();
			
			cin>>a;
			rep(y,0,a){
				cin>>b;
				s[x].insert(b);
			}
		}
		
		vector<int> l,r;
		rep(x,1,n+1) l.push_back(x);
		
		int curr=test(l);
		
		while (sz(l)>1){
			r.clear();
			int half=sz(l)>>1;
			
			while (sz(l)>half){
				r.push_back(l.back());
				l.pop_back();
			}
			
			if (test(l)!=curr) swap(l,r);
		}
		
		vector<int> ans;
		
		rep(x,0,k){
			if (s[x].count(l[0])){
				vector<int> temp;
				rep(y,1,n+1) if (s[x].count(y)==0) temp.push_back(y);
				
				ans.push_back(test(temp));
			}
			else{
				ans.push_back(curr);
			}
		}
		
		cout<<"! ";
		for (auto &it:ans) cout<<it<<" ";
		cout<<endl;
		
		string bruh;
		cin>>bruh;
	}
}