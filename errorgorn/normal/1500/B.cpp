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

#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define lb lower_bound
#define up upper_bound

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

ll n,m,k;
ll arr[500005];
ll brr[500005];
int pos[1000005];
map<int,int> turn;
int mv[500005];

ll cyc;

long long inverse(long long a, long long m){
    long long m0 = m;
    long long y = 0, x = 1;

    if (m == 1)
      return 0;

    while (a > 1)
    {
        // q is quotient
        long long q = a / m;
        long long t = m;

        // m is remainder now, process same as
        // Euclid's algo
        m = a % m, a = t;
        t = y;

        // Update y and x
        y = x - q * y;
        x = t;
    }

    // Make x positive
    if (x < 0)
       x += m0;

    return x;
}


ll test(ll i){
	ll res=0;
	rep(x,0,m){
		ll turns=(i+m-x-1)/m;
		if (mv[x]!=-1){
			res+=turns/cyc;
			if (turns%cyc>mv[x]) res++;
		}
	}
	
	return i-res;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>m>>k;
	
	rep(x,0,n){
		int temp=(x*m)%n;
		if (temp==0 && x!=0) break;
		turn[temp]=x;
	}
	
	rep(x,0,n) cin>>arr[x];
	
	memset(pos,-1,sizeof(pos));
	rep(x,0,n){
		pos[arr[x]]=x;
	}
	
	memset(mv,-1,sizeof(mv));
	rep(x,0,m){
		cin>>brr[x];
		if (pos[brr[x]]==-1) continue;
		int dist=(pos[brr[x]]-x)%n;
		if (dist<0) dist+=n;
		if (!turn.count(dist)) continue;
		
		mv[x]=turn[dist];
	}
	
	//rep(x,0,m) cout<<mv[x]<<" "; cout<<endl;
	
	cyc=n/__gcd(n,m);
	//cout<<cyc<<endl;
	
	//rep(x,0,10) cout<<x<<" "<<test(x)<<endl;
	
	ll lo=0,hi=1e18,mi;
	while (hi-lo>1){
		mi=hi+lo>>1;
		
		if (test(mi)>=k) hi=mi;
		else lo=mi;
	}
	
	cout<<hi<<endl;
}