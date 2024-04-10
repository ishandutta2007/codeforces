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

int edges[1000005][10];
int backedge[1000005];
int len[1000005];
int cnt[1000005];
int val[1000005];
char first[1000005];

int n,k;
int arr[200005];
int brr[200005];

int pi[200005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>k;
	
	if (k==1){
		cout<<n<<endl;
		return 0;
	}
	
	rep(x,0,n) cin>>arr[x];
	rep(x,0,k) cin>>brr[x];
	
	rep(x,0,n-1) arr[x]-=arr[x+1];
	rep(x,0,k-1) brr[x]-=brr[x+1];
	
	brr[k-1]=1000000005;
	
	int j=-1;
	pi[0]=-1;
	rep(x,0,k-1){
		while (j>=0 && brr[j]!=brr[x]) j=pi[j];
		j++;
		pi[x+1]=j;
	}
	
	int ans=0;
	
	j=0;
	rep(x,0,n-1){
		while (j>=0 && arr[x]!=brr[j]) j=pi[j];
		j++;
		
		//cout<<j<<endl;
		if (j==k-1) ans++;
	}
	
	cout<<ans<<endl;
}