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

int n,m;
string grid[105];
bool arr[105][105];

vector<int> v;

bool rev;
void op(int i,int j){
	if (rev) v.push_back(j+1);
	v.push_back(i+1);
	if (!rev) v.push_back(j+1);
	arr[i][j]^=1;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		v.clear();
		
		cin>>n>>m;
		
		rep(x,0,n) cin>>grid[x];
		
		rev=n<m;
		if (n<m) swap(n,m);
		
		rep(x,0,n){
			rep(y,0,m){
				if (rev) arr[x][y]=grid[y][x]=='1';
				else arr[x][y]=grid[x][y]=='1';
			}
		}
		
		rep(x,0,n-2){
			rep(y,0,m-1){
				if (arr[x][y]){
					op(x,y);
					op(x+1,y);
					op(x,y+1);
				}
			}
			if (arr[x][m-1]){
				op(x,m-1);
				op(x+1,m-2);
				op(x+1,m-1);
			}
		}
		
		rep(y,0,m-2){
			if (arr[n-1][y] && arr[n-2][y]){
				op(n-2,y);
				op(n-1,y);
				op(n-1,y+1);
			}
			if (arr[n-1][y]){
				op(n-1,y);
				op(n-1,y+1);
				op(n-2,y+1);
			}
			if (arr[n-2][y]){
				op(n-2,y);
				op(n-1,y+1);
				op(n-2,y+1);
			}
		}
		
		vector<ii> ones;
		vector<ii> zeros;
		
		rep(x,n-2,n){
			rep(y,m-2,m){
				if (arr[x][y]) ones.push_back(ii(x,y));
				else zeros.push_back(ii(x,y));
			}
		}
		
		if (sz(ones)==4){
			rep(x,0,3){
				op(ones.back().fi,ones.back().se);
				zeros.push_back(ones.back());
				ones.pop_back();
			}
		}
		if (sz(ones)==1){
			auto temp=ones.back();
			ones.pop_back();
			
			rep(x,0,2){
				op(zeros.back().fi,zeros.back().se);
				ones.push_back(zeros.back());
				zeros.pop_back();
			}
			
			op(temp.fi,temp.se);
			zeros.push_back(temp);
		}
		if (sz(ones)==2){
			auto temp=ones.back();
			ones.pop_back();
			
			rep(x,0,2){
				op(zeros.back().fi,zeros.back().se);
				ones.push_back(zeros.back());
				zeros.pop_back();
			}
			
			op(temp.fi,temp.se);
			zeros.push_back(temp);
		}
		if (sz(ones)==3){
			rep(x,0,3){
				op(ones.back().fi,ones.back().se);
				zeros.push_back(ones.back());
				ones.pop_back();
			}
		}
		
		/*
		rep(x,0,n){
			rep(y,0,m) cout<<arr[x][y];
			cout<<endl;
		}
		*/
		
		cout<<sz(v)/6<<endl;
		
		rep(x,0,sz(v)/6){
			rep(y,0,6) cout<<v[x*6+y]<<" "; cout<<endl;
		}
	}
}