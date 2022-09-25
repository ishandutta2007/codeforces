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
//#define endl '\n'
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

bool flip=false;

int ask(int a,int b,int c,int d){
	if (!flip) cout<<"? "<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
	else cout<<"? "<<b<<" "<<a<<" "<<d<<" "<<c<<endl;
	
	int temp;
	cin>>temp;
	
	return temp&1;
}

int n;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n;
	
	int can1=-1;
	int can2=-1;
	rep(x,1,n+1){
		if (ask(x,1,x,n)){
			if (can1==-1) can1=x;
			else{
				can2=x;
				break;
			}
		}
	}
	
	if (can1==-1){
		flip=true;
		rep(x,1,n){
			if (ask(x,1,x,n)){
				if (can1==-1) can1=x;
				else{
					can2=x;
					break;
				}
			}
		}
		
		if (can2==-1) can2=n;
	}
	
	int a1,a2;
	
	int lo=1,hi=n+1,mi;
	while (hi-lo>1){
		mi=hi+lo>>1;
		
		if (ask(can1,lo,can1,mi-1)) hi=mi;
		else lo=mi;
	}
	
	if (flip) swap(can1,lo);
	a1=can1,a2=lo;
	
	lo=1,hi=n+1,mi;
	while (hi-lo>1){
		mi=hi+lo>>1;
		
		if (ask(can2,lo,can2,mi-1)) hi=mi;
		else lo=mi;
	}
	
	if (flip) swap(can2,lo);
	cout<<"! "<<a1<<" "<<a2<<" "<<can2<<" "<<lo<<" ";
}