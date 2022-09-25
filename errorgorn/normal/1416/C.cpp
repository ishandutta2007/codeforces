//
//

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<ll,ll>
#define iii pair<ii,ll>
#define fi first
#define se second
#define endl '\n'
#define debug(x) cout << #x << " is " << x << endl

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int n;
int arr[300005];
int trie[9000005][2];
int cnt[9000005];

ll val[32][2];

int IDX=0;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	memset(trie,-1,sizeof(trie));
	
	cin>>n;
	rep(x,0,n) cin>>arr[x];
	
	rep(x,0,n){
		int curr=0;
		rep(bit,31,0){
			int go=(arr[x]&(1<<bit)?1:0);
			if (trie[curr][go]==-1){
				trie[curr][go]=++IDX;
			}
			
			if (trie[curr][go^1]!=-1) val[bit][go]+=cnt[trie[curr][go^1]];
			
			curr=trie[curr][go];
			cnt[curr]++;
		}
	}
	
	//rep(x,0,5) cout<<val[x][0]<<" "<<val[x][1]<<endl;
	
	ll ans=0;
	ll bm=0;
	
	rep(bit,0,30){
		if (val[bit][0]<=val[bit][1]){
			ans+=val[bit][0];
		}
		else{
			ans+=val[bit][1];
			bm|=(1<<bit);
		}
	}
	
	cout<<ans<<" "<<bm<<endl;
}