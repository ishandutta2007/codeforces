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

int n;
ll arr[100005];
ll fen[100005];

void update(int i,ll k){
	while (i<100005){
		fen[i]+=k;
		i+=i&-i;
	}
}

void update(int i,int j,ll k){
	update(i,k);
	update(j+1,-k);
}

ll query(int i){
	ll res=0;
	while (i){
		res+=fen[i];
		i-=i&-i;
	}
	return res;
}

ll inc=0;

void add(int i,ll mul){
	inc+=max(query(i+1)-query(i),0LL)*mul;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n;
	rep(x,1,n+1){
		cin>>arr[x];
		update(x,x,arr[x]);
	}
	
	rep(x,1,n){
		add(x,1);
	}
	
	//cout<<inc<<endl;
	cout<<((inc+query(1)+1)>>1)<<endl;
	
	int q;
	ll a,b,c;
	
	cin>>q;
	while (q--){
		cin>>a>>b>>c;
		
		if (a!=1) add(a-1,-1);
		if (b!=n) add(b,-1);
		
		update(a,b,c);
		
		if (a!=1) add(a-1,1);
		if (b!=n) add(b,1);
		
		cout<<((inc+query(1)+1)>>1)<<endl;
	}
}