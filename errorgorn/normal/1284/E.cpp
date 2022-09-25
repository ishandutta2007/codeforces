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

typedef complex<ll> point;
#define P(p) const point &p
#define X real
#define Y imag

ll dot(P(i),P(j)){
    return X(i)*X(j)+Y(i)*Y(j);
}

ll cross(P(i),P(j)){
    return X(i)*Y(j)-Y(i)*X(j);
}

int n;
point arr[2505];

ll bad[2505];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	rep(x,0,2505){
		bad[x]=(ll)x*(x-1)*(x-2)/3/2;
	}
	
	cin>>n;
	rep(x,0,n){
		ll a,b;
		cin>>a>>b;
		arr[x]={a,b};
	}
	
	ll ans=(ll)n*(n-1)*(n-2)*(n-3)*(n-4)/4/3/2;
	
	rep(x,0,n){
		vector<int> v;
		
		rep(y,0,n) if (x!=y){
			arr[y]-=arr[x];
			v.push_back(y);
		}
		
		sort(all(v),[](int i,int j){
			if ((X(arr[i])<0) != (X(arr[j])<0)){
				return X(arr[i])<0;
			}
			else{
				return cross(arr[i],arr[j])>0;
			}
		});
		
		rep(x,0,n-1) v.push_back(v[x]);
		
		int curr=1;
		rep(x,0,n-1){
			//rep(y,x,x+n-1) cout<<arr[y]<<" "<<cross(arr[v[x]],arr[v[y]])<<" "; cout<<endl;
			while (curr<x+n-1 && cross(arr[v[x]],arr[v[curr]])>=0) curr++;
			
			//cout<<x+n-1-curr<<endl;
			ans-=bad[x+n-1-curr];
		}
		
		rep(y,0,n) if (x!=y){
			arr[y]+=arr[x];
		}
	}
	
	cout<<ans<<endl;
}