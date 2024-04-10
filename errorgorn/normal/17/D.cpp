#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#define ll long long
#define ii pair<int,int>
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


long long qexp(long long b,long long p,int m){
    long long res=1;
    while (p){
        if (p&1) res=(res*b)%m;
        b=(b*b)%m;
        p>>=1;
    }
    return res;
}


string B,N;

int c;
ll b;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>B>>N>>c;
	
	rep(x,0,B.size()){
		b=(b*10)%c;
		b=(b+B[x]-'0')%c;
	}
	
	ll ans=1;
	
	int idx=N.size()-1;
	while (true){
		if (N[idx]=='0') N[idx]='9';
		else{
			N[idx]--;
			break;
		}
		
		idx--;
	}
	
	rep(x,0,N.size()){
		ans=qexp(ans,10,c);
		ans=(ans*qexp(b,N[x]-'0',c))%c;
	}
	
	ans=(ans*(b-1+c))%c;
	if (ans==0) ans=c;
	
	cout<<ans<<endl;
}