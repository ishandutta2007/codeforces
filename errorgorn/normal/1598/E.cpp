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

int n,m,q;
int arr[1005][1005];
vector<ii> da,db;

ll cnt=0;

ll calc(int i,int j){
	ll res=0;
	
	ll cnt=0;
	for (auto &it:da){
		int i2=i+it.fi,j2=j+it.se;
		
		if (i2<1 || n<i2 || j2<1 || m<j2) continue;
		
		if (arr[i2][j2]){
			res+=cnt*(cnt-1)/2;
			cnt=0;
		}
		else cnt++;
	}
	res+=cnt*(cnt-1)/2;
	cnt=0;
	for (auto &it:db){
		int i2=i+it.fi,j2=j+it.se;
		
		if (i2<1 || n<i2 || j2<1 || m<j2) continue;
		
		if (arr[i2][j2]){
			res+=cnt*(cnt-1)/2;
			cnt=0;
		}
		else cnt++;
	}
	res+=cnt*(cnt-1)/2;
	
	return res;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>m>>q;
	
	rep(x,-1005,1005){
		da.pub(ii(-x,x));
		da.pub(ii(-x,x+1));
	}
	rep(x,-1005,1005){
		db.pub(ii(-x,x-1));
		db.pub(ii(-x,x));
	}
	
	ll free=n*m;
	
	rep(x,0,1005) cnt+=calc(x,x);
	
	int a,b;
	rep(x,0,q){
		cin>>a>>b;
		a=n-a+1;
		
		cnt-=calc(a,b);
		
		if (arr[a][b]){
			arr[a][b]=0;
			free++;
		}
		else{
			arr[a][b]=1;
			free--;
		}
		
		cnt+=calc(a,b);
		
		//cout<<cnt<<" "<<free<<endl;
		cout<<cnt+free<<endl;
	}
}