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
#define iii pair<ii,ll>
#define fi first
#define se second
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
int arr[1005];

int ask(int i,int j,int k){
	cout<<"? "<<i+1<<" "<<j+1<<" "<<k+1<<endl;
	int res;
	//res=max({arr[i],arr[j],arr[k]})-min({arr[i],arr[j],arr[k]});
	cin>>res;
	return res;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n;
		
		//rep(x,0,n) cin>>arr[x];
		
		int a=-1,c=-1;
		
		int x=0;
		while (x<n){
			vector<int> p;
			if (a==-1) p={x,(x+1)%n,(x+2)%n,(x+3)%n};
			else if (x==n-1) p={a,c,n-1};
			else p={a,c,x,x+1};
			
			if (a==-1) x+=4;
			else x+=2;
			
			if (sz(p)==3){
				rep(x,0,n) if (x!=p[0] && x!=p[1]){
					p.pub(x);
					break;
				}
			}
			
			vector<ii> v={
				{ask(p[1],p[2],p[3]),p[0]},
				{ask(p[0],p[2],p[3]),p[1]},
				{ask(p[0],p[1],p[3]),p[2]},
				{ask(p[0],p[1],p[2]),p[3]}
			};
			
			sort(all(v));
			
			if (v.front().fi!=v.back().fi) a=v[0].se,c=v[1].se;
			
			//cout<<"debug: "<<x<<" "<<a<<" "<<c<<endl;
		}
		
		cout<<"! "<<a+1<<" "<<c+1<<endl;
	}
}