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
#define up upper_bound

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int n;
int arr[100005];
int f[100005];
int b[100005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n;
	rep(x,1,n+1) cin>>arr[x];
	
	int b1=0,c1=0;
	int b2=0,c2=0;
	
	rep(x,1,n+1){
		if (arr[x-1]<arr[x]) f[x]=f[x-1];
		f[x]++;
		
		if (b1<f[x]) b1=f[x],c1=x;
		else if (b1==f[x]) c1=-1;
	}
	
	rep(x,n+1,1){
		if (arr[x+1]<arr[x]) b[x]=b[x+1];
		b[x]++;
		
		if (b2<b[x]) b2=b[x],c2=x;
		else if (b2==b[x]) c2=-2;
	}
	
	//cout<<b1<<" "<<b2<<" "<<c1<<" "<<c2<<endl;
	
	if (b1==b2){
		 if (c1==c2 && b1%2==1) cout<<1;
		 else cout<<0;
	}
	else cout<<0<<endl;
}