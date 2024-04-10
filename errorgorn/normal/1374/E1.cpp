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
#define debug(x) cout << #x << " is " << x << endl;

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

ll MAX(ll a){return a;}
ll MIN(ll a){return a;}
template<typename... Args>
ll MAX(ll a,Args... args){return max(a,MAX(args...));}
template<typename... Args>
ll MIN(ll a,Args... args){return min(a,MIN(args...));}

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int n,k;
vector<int> a,b,c;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>k;
	
	int A,B,C;
	rep(x,0,n){
		cin>>A>>B>>C;
		
		if (B==1 && C==1){
			a.push_back(A);
		}
		else if (B==1){
			b.push_back(A);
		}
		else if (C==1){
			c.push_back(A);
		}
	}
	
	sort(all(a));
	reverse(all(a));
	
	sort(all(b));
	reverse(all(b));
	
	sort(all(c));
	reverse(all(c));
	
	int ans=0;
	while (k--){
		if (!a.empty() && !b.empty() && !c.empty()){
			if (a.back()<b.back()+c.back()){
				ans+=a.back();
				a.pop_back();
			}
			else{
				ans+=b.back()+c.back();
				b.pop_back();
				c.pop_back();
			}
		}
		else if (!a.empty()){
			ans+=a.back();
			a.pop_back();
		}
		else if (!b.empty() && !c.empty()){
			ans+=b.back()+c.back();
			b.pop_back();
			c.pop_back();
		}
		else{
			cout<<"-1"<<endl;
			return 0;
		}
	}
	
	cout<<ans<<endl;
}