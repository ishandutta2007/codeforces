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

int trans[13][13][13];
int memo[12][12][25][12]; //inv flip len num

void rec(vector<int> v,int inv){
	bool ok=true;
	int mx=0;
	rep(x,0,sz(v)-1){
		mx=max(mx,v[x]);
		if (mx==x) ok=false;
	}
	
	if (sz(v)>1 && ok){
		int num=0;
		rep(x,0,sz(v)-1) if (v[x]>v[x+1]) num++;
		trans[inv][num][sz(v)]++;
	}
	
	if (sz(v)==12) return;
	rep(x,0,sz(v)+1){
		vector<int> t;
		int inv2=inv;
		
		for (auto it:v){
			if (it>=x) t.pub(it+1),inv2++;
			else t.pub(it);
		}
		t.pub(x);
		
		if (inv2>11) continue;
		rec(t,inv2);
	}
}

const int MOD=998244353;

ll qexp(ll b,ll p,int m){
    ll res=1;
    while (p){
        if (p&1) res=(res*b)%m;
        b=(b*b)%m;
        p>>=1;
    }
    return res;
}

ll inv(ll i){
	return qexp(i,MOD-2,MOD);
}

int pinv[105];

int nCk(int n,int k){
	if (n<k) return 0;
	
	int ans=1;
	rep(x,1,k+1) ans=ans*(n-x+1)%MOD*pinv[x]%MOD;
	
	return ans;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	rep(x,0,105) pinv[x]=inv(x);
	
	rec({0},0);
	
	memo[0][0][0][0]=1;
	rep(x,0,12) rep(y,0,12) rep(z,0,25) rep(w,0,12){ //inv flip len num
		rep(a,0,13) rep(b,0,13) rep(c,0,13) if (x+a<12 && y+b<12 && z+c<25 && w+1<12){
			memo[x+a][y+b][z+c][w+1]=(memo[x+a][y+b][z+c][w+1]+memo[x][y][z][w]*trans[a][b][c])%MOD;
		} 
	}
	
	int TC;
	cin>>TC;
	while (TC--){
		int n,A,B;
		cin>>n>>A>>B;
		
		int ans=0;
		rep(x,0,25) rep(y,0,12) if (memo[A][B][x][y]){
			//memo[A][B][x][y] * nCk(n-x+y,y)
			ans=(ans+memo[A][B][x][y]*nCk(n-x+y,y))%MOD;
			//cout<<x<<" "<<y<<" "<<memo[A][B][x][y]<<endl;
		}
		cout<<ans<<endl;
	}
}