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

vector<int> primes;

bool isprime(int i){
    if (i==1) return false;
    else if (i==2) return true;
    else if (!(i&1)) return false;
    for (int x=3;x<=sqrt(i);x+=2){
        if (!(i%x)) return false;
    }
    return true;
}

ll test(ll i){
	cout<<"? "<<i<<endl;
	ll res;
	cin>>res;
	return res;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	rep(x,1,650) if (isprime(x)) primes.push_back(x);
	
	int TC;
	cin>>TC;
	while (TC--){
		long double tot=1;
		ll dis=1;
	
		for (auto &it:primes){
			//cout<<it<<endl;
		
			if (tot*it>1e18){
				dis*=test((ll)(tot+0.5));
				tot=it;
			}
			else{
				tot*=it;
			}
		}
	
		dis*=test((ll)(tot+0.5));
		
		vector<int> distinct;
		for (auto &it:primes){
			if (dis%it==0) distinct.push_back(it);
		}
		
		dis=1;
		
		for (int x=0;x<sz(distinct);x+=2){
			ll curr=1;
			ll tester=1;
			
			while (curr*distinct[x]<1e9){
				curr*=distinct[x];
			}
			
			tester*=curr;
			
			if (x+1<sz(distinct)){
				curr=1;
				while (curr*distinct[x+1]<1e9){
					curr*=distinct[x+1];
				}
				tester*=curr;
			}
			
			dis*=test(tester);
		}
		
		ll ans=1;
		
		for (auto &it:primes){
			int num=1;
			
			while (dis%it==0){
				num++;
				dis/=it;
			}
			
			ans*=num;
		}
		
		if (ans<=4) cout<<"! "<<8<<endl;
		else cout<<"! "<<ans*2<<endl;
	}
}