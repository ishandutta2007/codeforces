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

int n;
int arr[200005];
int f[200005];
int b[200005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n;
	rep(x,1,n+1) cin>>arr[x];
	
	f[n]=1;
	rep(x,n,1){
		if (arr[x]<arr[x+1]) f[x]=f[x+1]+1;
		else f[x]=1;
	}
	
	b[1]=1;
	rep(x,2,n+1){
		if (arr[x-1]>arr[x]) b[x]=b[x-1]+1;
		else b[x]=1;
	}
	
	int l=1,r=n;
	bool turn=false;
	int p=-1;
	
	while (true){
		if (max(arr[l],arr[r])<=p){
			if (turn) cout<<"Alice"<<endl;
			else cout<<"Bob"<<endl;
			return 0;
		}
		
		if (l==r){
			if (turn) cout<<"Bob"<<endl;
			else cout<<"Alice"<<endl;
			return 0;
		}
		if (arr[l]<=arr[r]){
			if (b[r]%2==1){
				if (turn) cout<<"Bob"<<endl;
				else cout<<"Alice"<<endl;
				return 0;
			}
			if (arr[l]>p){
				turn^=true;
				p=arr[l];
				l++;
			}
			else{
				if (turn) cout<<"Alice"<<endl;
				else cout<<"Bob"<<endl;
				return 0;
			}
		}
		else{
			if (f[l]%2==1){
				if (turn) cout<<"Bob"<<endl;
				else cout<<"Alice"<<endl;
				return 0;
			}
			if (arr[r]>p){
				turn^=true;
				p=arr[r];
				r--;
			}
			else{
				if (turn) cout<<"Alice"<<endl;
				else cout<<"Bob"<<endl;
				return 0;
			}
		}
	}
}