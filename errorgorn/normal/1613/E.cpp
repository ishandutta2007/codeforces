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

int n,m;
string grid[1000005];
queue<ii> q;

const int dx[]={0,0,-1,1};
const int dy[]={-1,1,0,0};

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n>>m;
		rep(x,0,n) cin>>grid[x];
		
		rep(x,0,n) rep(y,0,m) if (grid[x][y]=='L'){
			rep(z,0,4){
				int aa=x+dx[z],bb=y+dy[z];
				if (aa<0 || n<=aa || bb<0 || m<=bb) continue;
				q.push({aa,bb});
			}
		}
		
		int a,b,aa,bb;
		while (!q.empty()){
			tie(a,b)=q.front();
			q.pop();
			if (grid[a][b]!='.') continue;
			
			int cnt=0;
			rep(z,0,4){
				aa=a+dx[z],bb=b+dy[z];
				if (aa<0 || n<=aa || bb<0 || m<=bb) continue;
				if (grid[aa][bb]=='.') cnt++;
			}
			
			if (cnt<=1){
				grid[a][b]='+';
			
				rep(z,0,4){
					aa=a+dx[z],bb=b+dy[z];
					if (aa<0 || n<=aa || bb<0 || m<=bb) continue;
					q.push({aa,bb});
				}
			}
		}
		
		rep(x,0,n) cout<<grid[x]<<endl;
	}
}