//
//

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#define int long long
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

int l,r;
int arr[132000];
int brr[132000];

vector<int> cand;
int cnt[132000];

const int N=10;
unsigned mask[N];

int cnt1[1<<N];
int cnt2[1<<N];

int conv(int i){
	int res=0;
	rep(x,0,N) res|=__builtin_parity(i&mask[x])<<x;
	return res;
}

void test(){
	rep(x,0,N) mask[x]=rng();
	
	memset(cnt1,0,sizeof(cnt1));
	memset(cnt2,0,sizeof(cnt2));
	rep(x,0,r-l+1) cnt1[conv(arr[x])]++;
	rep(x,0,r-l+1) cnt2[conv(brr[x])]++;
	
	rep(x,0,r-l+1){
		int temp=conv(cand[x]);
		
		bool bad=false;
		rep(x,0,1<<N) if (cnt1[x^temp]!=cnt2[x]){
			bad=true;
			break;
		}
		
		if (!bad) cnt[x]++;
	}
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		cand.clear();
		
		cin>>l>>r;
		rep(x,0,r-l+1) cin>>arr[x];
		rep(x,0,r-l+1) brr[x]=l+x;
		
		rep(x,0,r-l+1) cand.pub(arr[x]^brr[0]);
		
		sort(all(cand));
		rep(x,0,r-l+1) cnt[x]=0;
		
		int K=5;
		rep(x,0,K) test();
		
		rep(x,0,r-l+1) if (cnt[x]==K){
			cout<<cand[x]<<endl;
			break;
		}
	}
}