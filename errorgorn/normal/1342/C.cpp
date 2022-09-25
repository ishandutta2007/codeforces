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

int q,a,b;

int precomp[40005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>a>>b>>q;
		
		precomp[0]=0;
		rep(x,1,a*b){
			precomp[x]=precomp[x-1]+((x%a)%b!=(x%b)%a);
		}
		
		while (q--){
			ll i,j;
			ll ans=0;
			
			cin>>i>>j;
			
			ll temp=(j-i)/(a*b);
			
			ans+=temp*precomp[a*b-1];
			i+=temp*(a*b);
			
			i%=(a*b);
			j%=(a*b);
			
			//cout<<i<<" "<<j<<" "<<ans<<endl;
			
			if (i<=j){
				ans+=precomp[j]-(i?precomp[i-1]:0);
			}
			else{
				ans+=precomp[a*b-1]-precomp[i-1]+precomp[j];
			}
			
			cout<<ans<<" ";
		}
		cout<<endl;
	}
	
}