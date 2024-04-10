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

bool check(string s){
	int c=0;
	
	for (auto &it:s){
		if (it=='(') c++;
		else c--;
		
		if (c<0) return false;
	}
	
	return c==0;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		int n;
		cin>>n;
		string s;
		cin>>s;
		
		int o=0,z=0;
		
		for (auto &it:s){
			if (it=='1') o++;
			else z++;
		}
		
		if (o%2==1 || z%2==1){
			cout<<"NO"<<endl;
			continue;
		}
		
		string a1,a2;
		
		int cnt=0;
		bool flag=false;
		
		for (auto &it:s){
			if (it=='1'){
				char temp=(cnt++<o/2?'(':')');
				
				a1.pub(temp);
				a2.pub(temp);
			}
			else{
				if (flag){
					a1.pub('(');
					a2.pub(')');
				}
				else{
					a2.pub('(');
					a1.pub(')');
				}
				
				flag^=true;
			}
		}
		
		if (check(a1) && check(a2)){
			cout<<"YES"<<endl;
			cout<<a1<<endl<<a2<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
		
		
	}
}