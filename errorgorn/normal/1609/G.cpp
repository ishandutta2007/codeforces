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

struct FEN{
	ll fen[100005];
	
	FEN(){
		memset(fen,0,sizeof(fen));
	}
	
	void update(int i,ll j){
		while (i<100005){
			fen[i]+=j;
			i+=i&-i;
		}
	}
	
	ll query(int i){
		ll res=0;
		while (i){
			res+=fen[i];
			i-=i&-i;
		}
		return res;
	}
	
	int search(ll val){
		int pos=0;
		for (int x=1<<16;x;x>>=1){
			if (pos+x<100005 && val>=fen[pos+x]){
				val-=fen[pos+x];
				pos+=x;
			}
		}
		
		return pos;
	}
} fen1,fen2,fen3;


int n,m,q;
ll arr[105];
ll brr[100005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>m>>q;
	rep(x,0,n) cin>>arr[x];
	rep(x,0,m) cin>>brr[x];
	
	rep(x,n,1) arr[x]-=arr[x-1];
	rep(x,m,1) brr[x]-=brr[x-1];
	
	ll a,b,c;
	
	ll curr=(arr[0]+brr[0])*(n+m-1);
	rep(x,1,m) curr+=(brr[x])*(m-x);
	
	rep(x,1,m) fen1.update(x,brr[x]),fen1.update(x+1,-brr[x]),fen2.update(x,brr[x]);
	fen1.update(m,1e18);
	
	while (q--){
		cin>>a>>b>>c;
		
		if (a==1){
			rep(x,0,b) arr[x+(n-b)]+=c;
			if (b==n) curr+=c*(n+m-1);
			
		}
		else{
			if (b==m) curr+=c*(n+m-1),b--;
			curr+=(b)*(b+1)/2*c;
			fen1.update(m-b,c);
			fen3.update(m-b,c);
			fen2.update(m-b,-c*(m-b-1));
		}
		
		ll ans=curr;
		
		ll add=0;
		int y=1;
		rep(x,1,n){
			int idx=fen1.search(arr[x]);
			ans+=fen3.query(idx)*idx+fen2.query(idx);
			
			ans+=arr[x]*(n+m-x-idx-1);
		}
		
		cout<<ans<<endl;
	}
}