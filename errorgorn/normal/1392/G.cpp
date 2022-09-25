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

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int n,m,k;
int p[25];

string s,t;
int mn[1050000];
int mx[1050000];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	memset(mn,63,sizeof(mn));
	memset(mx,128,sizeof(mx));
	
	rep(x,0,25) p[x]=x;
	
	cin>>n>>m>>k;
	cin>>s>>t;
	
	int A=0,B=0;
		
	rep(x,0,k){
		if (s[x]=='1') A|=(1<<p[x]);
		if (t[x]=='1') B|=(1<<p[x]);
	}
	
	mn[A]=min(mn[A],-1);
	mx[B]=-1;
	
	//cout<<A<<" "<<B<<endl;
	
	int a,b;
	rep(x,0,n){
		cin>>a>>b;
		a--,b--;
		
		swap(p[a],p[b]);
		
		int A=0,B=0;
		
		rep(x,0,k){
			if (s[x]=='1') A|=(1<<p[x]);
			if (t[x]=='1') B|=(1<<p[x]);
		}
		
		mn[A]=min(mn[A],x);
		mx[B]=x;
		
		//cout<<A<<" "<<B<<endl;
	}
	
	int ans=-1;
	int l,r;
	rep(x,1<<k,0){
		//cout<<x<<" "<<mn[x]<<" "<<mx[x]<<endl;
		if (mn[x]+m<=mx[x]){
			if (ans<__builtin_popcount(x)){
				ans=__builtin_popcount(x);
				l=mn[x],r=mx[x];
			}
		}
		
		rep(bit,0,k) if (x&(1<<bit)){
			mn[x^(1<<bit)]=min(mn[x^(1<<bit)],mn[x]);
			mx[x^(1<<bit)]=max(mx[x^(1<<bit)],mx[x]);
		}
	}
	
	
	//cout<<ans<<endl;
	
	int ones=0;
	rep(x,0,k){
		if (s[x]=='1') ones++;
		if (t[x]=='1') ones++;
	}
	
	cout<<k-ones+2*ans<<endl;
	cout<<l+2<<" "<<r+1<<endl;
}