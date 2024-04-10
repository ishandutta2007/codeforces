// Problem: B. 3-Coloring
// Contest: Codeforces - Codeforces Round #712 (Div. 1)
// URL: https://codeforces.com/contest/1503/problem/B
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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

int n;
vector<ii> one;
vector<ii> two;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n;
	
	rep(x,1,n+1){
		rep(y,1,n+1){
			if ((x+y)%2==1) one.pub(ii(x,y));
			else two.pub(ii(x,y));
		}
	}
	
	rep(x,0,n*n){
		int a;
		cin>>a;
		
		if (a==1){
			if (!two.empty()){
				cout<<2<<" "<<two.back().fi<<" "<<two.back().se<<endl;
				two.pob();
			}
			else{
				cout<<3<<" "<<one.back().fi<<" "<<one.back().se<<endl;
				one.pob();
			}
		}
		else if (a==2){
			if (!one.empty()){
				cout<<1<<" "<<one.back().fi<<" "<<one.back().se<<endl;
				one.pob();
			}
			else{
				cout<<3<<" "<<two.back().fi<<" "<<two.back().se<<endl;
				two.pob();
			}
		}
		else{
			if (!one.empty()){
				cout<<1<<" "<<one.back().fi<<" "<<one.back().se<<endl;
				one.pob();
			}
			else{
				cout<<2<<" "<<two.back().fi<<" "<<two.back().se<<endl;
				two.pob();
			}
		}
	}
}