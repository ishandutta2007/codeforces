// Super Idol
//    
//  
//    
//  105C
// 

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

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

int n,l,r;
int cnt[200005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n>>l>>r;
		
		rep(x,1,n+1) cnt[x]=0;
		rep(x,0,l){
			int t;
			cin>>t;
			cnt[t]++;
		}
		rep(x,0,r){
			int t;
			cin>>t;
			cnt[t]--;
		}
		
		int ans=0;
		l=r=0;
		int lx=0,rx=0;
		
		rep(x,1,n+1){
			while (cnt[x]>=2){
				cnt[x]-=2;
				ans++;
				lx++;
			}
			while (cnt[x]<=-2){
				cnt[x]+=2;
				ans++;
				rx++;
			}
			if (cnt[x]>0) l+=cnt[x];
			if (cnt[x]<0) r-=cnt[x];
		}
		
		// cout<<l<<" "<<r<<endl;
		// cout<<lx<<" "<<rx<<endl;
		while (l>r && rx){
			ans--;
			rx--;
			r+=2;
		}
		while (r>l && lx){
			ans--;
			lx--;
			l+=2;
		}
		// cout<<l<<" "<<r<<endl;
		// cout<<lx<<" "<<rx<<endl;
		cout<<ans+(l+r)/2+abs(l-r)/2<<endl;
	}
	
}