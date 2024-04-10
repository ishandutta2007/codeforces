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

int n;
bool grid[25][25];

void add(int i,int j){
	cout<<i<<" "<<j<<endl;
	
	// rep(x,1,n+1) rep(y,1,n+1){
		// if (x==i || y==j || x-y==i-j) grid[x][y]=true;
	// }
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n;
	
	int m=(n*2+1)/3;
	
	// cout<<n*2-1<<" "<<m*3<<endl;
	cout<<m<<endl;
	
	if (m%2==1){
		int temp=m/2;
		
		int l1=1,r1=l1+temp-(temp%2==1);
		int l2=r1+1,r2=l2+temp-(temp%2==0);
		
		while (l1<=r1){
			add(l1,r1);
			if (l1!=r1) add(r1,l1);
			l1++,r1--;
		}
		while (l2<r2){
			add(l2,r2);
			add(r2,l2);
			l2++,r2--;
		}
	}
	else{
		m--;
		int temp=m/2;
		
		int l1=1,r1=l1+temp-(temp%2==1);
		int l2=r1+1,r2=l2+temp-(temp%2==0);
		
		while (l1<=r1){
			add(l1,r1);
			if (l1!=r1) add(r1,l1);
			l1++,r1--;
		}
		while (l2<r2){
			add(l2,r2);
			add(r2,l2);
			l2++,r2--;
		}
		
		add(n-m/2-1,n-m/2-1);
	}
	
	// rep(x,1,n+1){
		// rep(y,1,n+1) cout<<grid[x][y]; cout<<endl;
	// }
}