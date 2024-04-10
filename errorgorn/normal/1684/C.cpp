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

#define rep(x,start,end) for(int x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int n,m;
vector<int> v[200005];

int test(int i){
	set<int> s;
	
	rep(x,0,n) rep(y,0,m-1) if (v[x][y]>v[x][y+1]) s.insert(y);
	
	if (sz(s)>4) return -1;
	
	rep(j,0,m){
		//cout<<"debug: "<<i<<" "<<j<<endl; 
		rep(x,0,n) swap(v[x][i],v[x][j]);
		
		set<int> t=s;
		for (auto it:{i-1,i,j-1,j}){
			if (0<=it && it<m-1){
				t.erase(it);
				rep(x,0,n) if (v[x][it]>v[x][it+1]) t.insert(it);
			}
		}
		
		rep(x,0,n) swap(v[x][i],v[x][j]);
		
		if (sz(t)==0) return j;
	}
	
	return -1;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n>>m;
		rep(x,0,n) v[x]=vector<int>(m);
		rep(x,0,n) rep(y,0,m) cin>>v[x][y];
		
		set<int> s;
		rep(x,0,n){
			rep(y,0,m-1) if (v[x][y]>v[x][y+1]) s.insert(y);
		}
		
		if (sz(s)==0) cout<<1<<" "<<1<<endl;
		else{
			int l=*s.begin();
			
			bool flag=false;
			rep(x,0,2) if (!flag){
				int temp=test(l+x);
				if (temp!=-1){
					cout<<l+x+1<<" "<<temp+1<<endl;
					flag=true;
				}
			}
			if (!flag) cout<<"-1"<<endl;
		}
	}
}