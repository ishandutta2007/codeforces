// Super Idol
//    
//  
//    
//  105C
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

int n,q,MOD;
int arr[300005];

int diff[300005];
int bad=0;

void add(int i){
	if (i>=n) return;
	if (diff[i]) bad++;
}

void del(int i){
	if (i>=n) return;
	if (diff[i]) bad--;
}

int fibo[300005];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>q>>MOD;
	
	fibo[0]=0;
	fibo[1]=1;
	rep(x,2,300005) fibo[x]=(fibo[x-2]+fibo[x-1])%MOD;
	
	rep(zzz,0,2){
		rep(x,0,n) cin>>arr[x];
		rep(x,n,0){
			if (x>=1) arr[x]=(arr[x]-arr[x-1]+MOD)%MOD;
			if (x>=2) arr[x]=(arr[x]-arr[x-2]+MOD)%MOD;
		}
		
		if (zzz==0) rep(x,0,n) diff[x]=arr[x];
		else rep(x,0,n) diff[x]=(diff[x]-arr[x]+MOD)%MOD;
	}
	
	rep(x,0,n) add(x);
	
	char c;
	int a,b;
	while (q--){
		cin>>c>>a>>b;
		a--,b--;
		
		int mul;
		if (c=='A') mul=1;
		else mul=MOD-1;
		
		del(a),del(b+1),del(b+2);
		diff[a]=(diff[a]+1*mul)%MOD;
		int len=b-a+1;
		diff[b+1]=(diff[b+1]+fibo[len+1]*(MOD-mul))%MOD;
		diff[b+2]=(diff[b+2]+fibo[len]*(MOD-mul))%MOD;
		add(a),add(b+1),add(b+2);
		
		if (bad==0) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}