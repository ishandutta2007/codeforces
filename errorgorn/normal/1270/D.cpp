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

int n,k;
bool flipped[505];

ii test(){
	cout<<"? ";
	rep(x,0,505) if (flipped[x]) cout<<x<<" ";
	cout<<endl;
	ii res;
	cin>>res.fi>>res.se;
	return res;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>k;
	
	rep(x,1,k+1){
		flipped[x]=true;
	}
	
	ii mid=test();
	
	flipped[mid.fi]=false;
	flipped[k+1]=true;
	
	ii extra=test();
	
	bool larger=(extra.se>mid.se);
	
	int s=0;
	
	flipped[mid.fi]=true;
	
	rep(x,1,k+1) if (x!=mid.fi){
		flipped[x]=false;
		ii val=test();
		flipped[x]=true;
		
		if (val.fi==mid.fi){
			if (!larger) s++;
		}
		else{
			if (larger) s++;
		}
	}
	
	cout<<"! "<<s+1<<endl;
}