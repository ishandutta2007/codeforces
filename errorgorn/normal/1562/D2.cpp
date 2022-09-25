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

int n,q;
string s;

int arr[300005];
vector<int> v[600005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n>>q;
		cin>>s;
		
		rep(x,0,n) if (x%2){
			if (s[x]=='+') s[x]='-';
			else s[x]='+';
		}
		
		//cout<<s<<endl;
		
		arr[0]=300000;
		rep(x,1,n+1){
			arr[x]=arr[x-1]+(s[x-1]=='+'?1:-1);
		}
		
		rep(x,300000-n,300000+n+1) v[x].clear();
		rep(x,0,n+1) v[arr[x]].pub(x);
		
		int a,b;
		while (q--){
			cin>>a>>b;
			int delta=arr[b]-arr[a-1];
			
			if (delta==0) cout<<0<<endl;
			else if (delta<0){
				delta=-delta;
				if (delta%2==0){
					cout<<2<<endl;
					cout<<*(lower_bound(all(v[arr[a-1]-1]),a))<<" ";
					cout<<*(lower_bound(all(v[arr[a-1]-1-delta/2]),a))<<" ";
					cout<<endl;
				}
				else{
					cout<<1<<endl;
					cout<<*(lower_bound(all(v[arr[a-1]-1-delta/2]),a))<<" ";
					cout<<endl;
				}
			}
			else{
				if (delta%2==0){
					cout<<2<<endl;
					cout<<*(lower_bound(all(v[arr[a-1]+1]),a))<<" ";
					cout<<*(lower_bound(all(v[arr[a-1]+1+delta/2]),a))<<" ";
					cout<<endl;
				}
				else{
					cout<<1<<endl;
					cout<<*(lower_bound(all(v[arr[a-1]+1+delta/2]),a))<<" ";
					cout<<endl;
				}
			}
		}
	}
}