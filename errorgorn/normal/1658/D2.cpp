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

const int MOD=998244353;

#define vi vector<int>
void FST(vi& a, bool inv) {
	for (int n = sz(a), step = 1; step < n; step *= 2) {
		for (int i = 0; i < n; i += 2 * step) rep(j,i,i+step) {
			int &u = a[j], &v = a[j + step]; tie(u, v) = ii((u + v)%MOD, (u - v + MOD)%MOD);
		}
	}
}

int n,l,r;
int arr[132000];
int brr[132000];

vector<int> cand;
int cnt[132000];

const int N=10;
unsigned mask[N];

int conv(int i){
	int res=0;
	rep(x,0,N) res|=__builtin_parity(i&mask[x])<<x;
	return res;
}

void test(){
	rep(x,0,N) mask[x]=rng();
	
	vi cnt1(1<<N,0),cnt2(1<<N,0);
	rep(x,0,n) cnt1[conv(arr[x])]++;
	rep(x,0,n) cnt2[conv(brr[x])]++;
	
	int tot=0;
	rep(x,0,1<<N) tot=(tot+cnt1[x]*cnt1[x])%MOD;
	
	FST(cnt1,false);
	FST(cnt2,false);
	rep(x,0,1<<N) cnt1[x]=(cnt1[x]*cnt2[x])%MOD;
	FST(cnt1,true);
	
	tot=tot*(1<<N)%MOD;
	
	rep(x,0,n) if (cnt1[conv(cand[x])]==tot) cnt[x]++;
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
		n=r-l+1;
		rep(x,0,n) cin>>arr[x];
		rep(x,0,n) brr[x]=l+x;
		
		rep(x,0,n) cand.pub(arr[x]^brr[0]);
		
		if (n<=500){ //:rage:
			for (auto it:cand){
				vector<int> s,t;
				rep(x,0,n) s.pub(arr[x]^it);
				rep(x,0,n) t.pub(brr[x]);
				
				sort(all(s));
				sort(all(t));
				
				if (s==t){
					cout<<it<<endl;
					break;
				}
			}
			continue;
		}
		
		sort(all(cand));
		rep(x,0,n) cnt[x]=0;
		
		int K=5;
		rep(x,0,K) test();
		
		rep(x,0,n) if (cnt[x]==K){
			cout<<cand[x]<<endl;
			break;
		}
	}
}