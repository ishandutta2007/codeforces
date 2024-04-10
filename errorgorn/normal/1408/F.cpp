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
#define iii pair<ll,ii>
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
vector<int> v[20];
vector<ii> ans;

void die(){
	cout<<sz(ans)<<endl;
	for (auto &it:ans) cout<<it.fi<<" "<<it.se<<endl;
	exit(0);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n;
	
	int idx=1;
	int big=-1;
	int grp=0;
	rep(x,20,0){
		int s=1<<x;
		if (s<=n){
			rep(y,0,s) v[x].push_back(idx++);
			rep(y,0,x){
				rep(z,0,s){
					if ((z&(1<<y))==0) ans.push_back(ii(v[x][z],v[x][z|(1<<y)]));
				}
			}
			n-=s;
			grp++;
			
			if (big==-1) big=x;
		}
	}
	
	if (grp<=2) die();
	
	vector<int> temp={v[big].back()};
	v[big].pop_back();
	rep(x,0,big){
		if (v[x].empty()){
			rep(y,0,1<<x){
				temp.push_back(v[big].back());
				v[big].pop_back();
			}
		}
		else{
			for (auto &it:v[x]) temp.push_back(it);
		}
		
		rep(y,0,1<<x) ans.push_back(ii(temp[y],temp[y|(1<<x)]));
	}
	die();
}