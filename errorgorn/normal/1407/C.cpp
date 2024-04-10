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

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int n;
set<int> rem;
int arr[10005];

vector<int> pos;
	
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	
	cin>>n;
	rep(x,1,n+1) rem.insert(x);
	rep(x,1,n+1) pos.push_back(x);
	
	rep(x,1,n){
		int i1=pos.back();
		pos.pop_back();
		int i2=pos.back();
		pos.pop_back();
		
		int a,b;
		cout<<"? "<<i1<<" "<<i2<<endl;
		cin>>a;
		cout<<"? "<<i2<<" "<<i1<<endl;
		cin>>b;
		
		if (a<b){
			arr[i2]=b;
			pos.push_back(i1);
			rem.erase(b);
		}
		else{
			arr[i1]=a;
			pos.push_back(i2);
			rem.erase(a);
		}
	}
	
	arr[pos.back()]=*rem.begin();
	
	cout<<"! ";
	rep(x,1,n+1) cout<<arr[x]<<" ";
}