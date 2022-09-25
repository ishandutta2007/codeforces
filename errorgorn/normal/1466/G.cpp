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

const int HMOD[]={1000000007};
const int LEN=sizeof(HMOD)/sizeof(int);
const int P=177013;

ll hv[30];
ll ppow[LEN][2000005];
ll ipow[LEN][2000005];

struct roll{
	vector<array<int,LEN> > val;
	
	roll(string s){
		val.push_back(array<int,LEN>()); //should default to 0
		
		rep(x,0,sz(s)){
			auto temp=array<int,LEN>();
			rep(y,0,LEN){
				temp[y]=(val.back()[y]+hv[s[x]-'a']*ppow[y][x])%HMOD[y];
			}
			val.push_back(temp);
		}
	}
	
	array<int,LEN> q(int i,int j){
		auto res=array<int,LEN>();
		
		rep(x,0,LEN){
			res[x]=(val[j+1][x]-val[i][x]+HMOD[x])*ipow[x][i]%HMOD[x];
		}
		return res;
	}
};

const int MOD=1000000007;

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

ll fix(ll i){
	i%=MOD;
	if (i<0) i+=MOD;
	return i;
}


int n,q;
string s[22];
vector<roll> rs;

string t;

int pref[26][100005];

ll p2[100005];
ll ip2[100005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	rep(x,0,30) hv[x]=rng()%HMOD[0]; //whatever
	
	rep(x,0,LEN){
		ppow[x][0]=ipow[x][0]=1;
		rep(y,1,2000005) ppow[x][y]=ppow[x][y-1]*P%HMOD[x];
		ll temp=qexp(P,HMOD[x]-2,HMOD[x]);
		rep(y,1,2000005) ipow[x][y]=ipow[x][y-1]*temp%HMOD[x];
	}
	
	p2[0]=ip2[0]=1;
	rep(x,1,100005) p2[x]=p2[x-1]*2LL%MOD;
	ll temp=inv(2);
	rep(x,1,100005) ip2[x]=ip2[x-1]*temp%MOD;
	
	cin>>n>>q;
	cin>>s[0];
	cin>>t;
	
	rep(x,0,26){
		rep(y,0,n){
			if (t[y]-'a'==x) pref[x][y]=(pref[x][y]+ip2[y])%MOD;
			pref[x][y+1]=pref[x][y];
		}
	}
	
	rep(x,0,n+1){
		rs.push_back(roll(s[x]));
		if (sz(s[x])>1e6+5) break;
		s[x+1]=s[x]+t[x]+s[x];
	}
	
	int idx;
	string st;
	while (q--){
		cin>>idx>>st;
		roll rst=roll(st);
		
		int hi=0;
		while (hi<=min(n,idx) && sz(s[hi])+2<=sz(st)) hi++;
		
		int lh=sz(s[hi]);
		
		if (hi==min(n,idx)+1){
			cout<<0<<endl;
			continue;
		}
		
		ll ans=0;
		rep(x,0,sz(st)){ //[common]x[common]
			if (rs[hi].q(lh-x,lh-1)==rst.q(0,x-1) &&
				rs[hi].q(0,sz(st)-x-2)==rst.q(x+1,sz(st)-1)){
				
				int v=st[x]-'a';
				if (idx>hi)
					ans=fix(ans+(pref[v][idx-1]-(hi?pref[v][hi-1]:0))*p2[idx-1]);
			}
		}
		
		int temp=p2[idx-hi];
		rep(x,0,sz(s[hi])-sz(st)+1){ //totally contained inside common
			if (rs[hi].q(x,x+sz(st)-1)==rst.q(0,sz(st)-1)){
				ans=fix(ans+temp)%MOD;
			}
		}
		
		cout<<ans<<endl;
	}
}