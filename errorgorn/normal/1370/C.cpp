/*













*/

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

long long qexp(long long b,long long p,int m){
    long long res=1;
    while (p){
        if (p&1) res=(res*b)%m;
        b=(b*b)%m;
        p>>=1;
    }
    return res;
}


const int witness[]={2,7,61};
bool isPrime(int i){
    ///check for the simple cases
    if (i==1) return false;
    if (i==2) return true;
    if (!(i&1)) return false;
    for (auto &it:witness) if (it==i) return true;

    int s=__builtin_ctz(i-1);
    int k=(i>>s);
    
    long long res;
    for (auto &it:witness){
        res=qexp(it,k,i);
        
        if (res==1 || res==i-1) goto pass;
        for (int x=0;x<s-1;x++){
            res=(res*res)%i;
            if (res==i-1) goto pass;
        }
        return false;
        pass:;
    }
    return true;
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int TC;
	cin>>TC;
	while (TC--){
		int n;
		cin>>n;
		
		if (n==2) cout<<"Ashishgup"<<endl;
		else if (__builtin_popcount(n)==1) cout<<"FastestFinger"<<endl;
		else if (n%2==0 && isPrime(n/2)) cout<<"FastestFinger"<<endl;
		else cout<<"Ashishgup"<<endl;
	}
}