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

int n;
ll arr[1000005];
ll brr[1000005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n;
		
		rep(x,0,n) cin>>arr[x];
		rep(x,0,n) cin>>brr[x];
		
		int curr=n-1;
		while (curr>=2){
			if (brr[curr-1]+brr[curr]<arr[curr]){
				cout<<"NO"<<endl;
				goto bad;
			}
			
			ll mna=max(0LL,brr[curr-1]-arr[curr]);
			ll mxa=brr[curr-1]-max(0LL,arr[curr]-brr[curr]);
			ll mnb=max(0LL,brr[curr]-arr[curr]);
			ll mxb=brr[curr]-max(0LL,arr[curr]-brr[curr-1]);
			
			//cout<<mna<<" "<<mxa<<" "<<mnb<<" "<<mxb<<endl;
			
			arr[curr-1]=max(0LL,arr[curr-1]-mna);
			arr[0]=max(0LL,arr[0]-mnb);
			
			ll a=mxa-mna,b=mxb-mnb;
			
			if (a>b){
				arr[curr-1]=max(0LL,arr[curr-1]-(a-b));
				brr[curr-1]=b;
			}
			else{
				arr[0]=max(0LL,arr[0]-(b-a));
				brr[curr-1]=a;
			}
			
			/*
			rep(x,0,curr) cout<<arr[x]<<" ";cout<<endl;
			rep(x,0,curr) cout<<brr[x]<<" ";cout<<endl;
			cout<<endl;
			*/
			
			curr--;
		}
		
		if (arr[0]+arr[1]<=brr[0]+brr[1]) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
		
		bad:;
	}
}