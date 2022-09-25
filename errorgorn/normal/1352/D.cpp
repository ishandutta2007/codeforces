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

int n;
int arr[1005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n;
		rep(x,0,n) cin>>arr[x];
		
		int l=0,r=n-1;
		int a=0,b=0;
		int prev=0;
		int curr;
		int turns=0;
		
		while (l<=r){
			curr=0;
			while (curr<=prev && l<=r){
				curr+=arr[l++];
			}
			
			a+=curr;
			prev=curr;
			turns++;
			if (l>r) break;
			
			curr=0;
			while (curr<=prev && l<=r){
				curr+=arr[r--];
			}
			
			b+=curr;
			prev=curr;
			turns++;
		}
		
		cout<<turns<<" "<<a<<" "<<b<<endl;
	}
}