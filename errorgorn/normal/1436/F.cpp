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

const int MOD=998244353;

struct dat{
	int a=0,b=0,c=0,d=0;
};

dat merge(dat i,dat j){
	return{
		(i.a*j.d+i.b*j.c+i.c*j.b+i.d*j.a)%MOD,
		(i.b*j.d+i.d*j.b)%MOD,
		(i.c*j.d+i.d*j.c)%MOD,
		(i.d*j.d)%MOD
	};
}

dat add(dat i,dat j){
	return{
		(i.a+j.a)%MOD,
		(i.b+j.b)%MOD,
		(i.c+j.c)%MOD,
		(i.d+j.d)%MOD
	};
}

int n;
bool com[100005];
int mu[100005];
int cnt[100005];

dat same[100005];
dat diff[100005];

int solve(int i){
	dat a={0,0,0,1};
	dat b={0,0,0,0};
	
	for (int x=i;x<100005;x+=i){
		b=add(merge(a,diff[x]),merge(b,same[x]));
		a=merge(a,same[x]);
	}
	
	return b.a;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n;
	rep(x,1,100005) mu[x]=1;
	rep(x,2LL,100005) if (!com[x]){
		for (int y=x;y<100005;y+=x){
			mu[y]*=-1;
			com[y]=true;
		}
		for (int y=x*x;y<100005;y+=x*x){
			mu[y]=0;
		}
	}
	
	int a,b;
	rep(x,0,n){
		cin>>a>>b;
		cnt[a]=b;
	}
	
	rep(x,1LL,100005){
		dat a={0,0,0,1};
		dat b={0,0,0,0};
		
		dat c={x*x%MOD,x,x,2};
		dat d={0,x,0,1};
		
		int p=cnt[x];
		while (p){
			if (p&1){
				b=add(merge(a,d),merge(b,c));
				a=merge(a,c);
			}
			
			d=add(merge(c,d),merge(d,c));
			c=merge(c,c);
			p>>=1;
		}
		
		same[x]=a;
		diff[x]=b;
	}
	
	int ans=0;
	rep(x,1,100005) ans=(ans+(MOD+mu[x])*solve(x))%MOD;
	
	cout<<ans<<endl;
}