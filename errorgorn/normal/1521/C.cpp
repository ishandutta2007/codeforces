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
#define debug(x) cout << #x << " is " << x << endl

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
int ask1(int i,int j){
	cout<<"? "<<2<<" "<<i<<" "<<j<<" "<<1<<endl;
	int temp;
	cin>>temp;
	return temp;
}

int ask2(int i,int j){
	cout<<"? "<<1<<" "<<i<<" "<<j<<" "<<n-1<<endl;
	int temp;
	cin>>temp;
	return temp;
}

int ans[10005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n;
		rep(x,1,n+1) ans[x]=-1;
		
		int a=min(ask1(1,2),ask1(2,1));
		int b=min(ask1(1,3),ask1(3,1));
		int c=min(ask1(2,3),ask1(3,2));
		
		int idx,best;
		if (a==b) idx=1,best=a;
		else if (a==c) idx=2,best=a;
		else idx=3,best=b;
		
		rep(x,0,18){
			int temp;
			do{
				temp=rng()%n+1;
			} while (temp==idx);
			
			int tempv=max(ask1(idx,temp),2);
			if (tempv<best) idx=temp,best=tempv;
		}
		
		int hi;
		rep(x,1,n+1) if (x!=idx){
			int temp=ask2(idx,x);
			if (temp>best) ans[x]=temp;
			if (temp==n) hi=x;
		}
		
		rep(x,1,n+1) if (ans[x]==-1){
			ans[x]=ask1(x,hi);
		}
		
		cout<<"! "; rep(x,1,n+1) cout<<ans[x]<<" "; cout<<endl;
	}
}