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

const int one[]={1};
const int four[]={3,1,4,2};
const int five[]={5,2,4,1,3};
const int six[]={6,3,5,1,4,2};
const int eight[]={8,4,7,3,6,2,5,1};
const int nine[]={9,6,8,4,2,5,7,3,1};

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int TC;
	cin>>TC;
	while (TC--){
		int n;
		cin>>n;
		
		if (n==2 || n==3){
			cout<<"-1"<<endl;
			continue;
		}
		
		while (n){
			if (n==1){
				for (auto &it:one) cout<<it<<" ";
				break;
			}
			else if (n==4){
				for (auto &it:four) cout<<it<<" ";
				break;
			}
			else if (n==5){
				for (auto &it:five) cout<<it<<" ";
				break;
			}
			else if (n==8){
				for (auto &it:eight) cout<<it<<" ";
				break;
			}
			else if (n==9){
				for (auto &it:nine) cout<<it<<" ";
				break;
			}
			
			n-=6;
			for (auto &it:six) cout<<it+n<<" ";
		}
		
		cout<<endl;
	}
}