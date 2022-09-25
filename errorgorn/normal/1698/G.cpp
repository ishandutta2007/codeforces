// Super Idol
//    
//  
//    
//  105C
// 

#include <bits/stdc++.h>
using namespace std;

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

#define rep(x,start,end) for(int x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int mul(int i,int j,int mod){
	int b=63-__builtin_clzll(mod);
	
	int res=0;
	while (j){
		if (j&1) res^=i;
		i<<=1; if (i&(1LL<<b)) i^=mod;
		j>>=1;
	}
	return res;
}

int pow(int p,int mod){
	int b=2;
    int res=1;
    while (p){
    	if (p&1) res=mul(res,b,mod);
    	b=mul(b,b,mod);
    	p>>=1;
    }
    return res;
}

int mod(int i,int j){
	while (i && __builtin_clzll(j)-__builtin_clzll(i)>=0){
		i^=j<<(__builtin_clzll(j)-__builtin_clzll(i));
	}
	return i;
}

int divi(int i,int j){
	int res=0;
	while (i){
		res|=1LL<<(__builtin_clzll(j)-__builtin_clzll(i));
		i^=j<<(__builtin_clzll(j)-__builtin_clzll(i));
	}
	return res;
}

int gcd(int i,int j){
	while (i){
		if (i<j) swap(i,j);
		i=mod(i,j);
	}
	return j;
}

struct XOR_BASIS{
	int val[64];
	int mask[64];
	
	void reset(){
		memset(val,0,sizeof(val));
		memset(mask,0,sizeof(mask));
	}
	
	int add(int i,int j){
		int curr=1LL<<j;
		rep(x,0,64) if (i&(1LL<<x)){
			if (val[x]==0){
				val[x]=i;
				mask[x]=curr;
				return 0;
			}
			else{
				i^=val[x];
				curr^=mask[x];
			}
		}
		
		return curr;
	}
} basis;

void factor(int mod,vector<ii> &ans){ //answer stores in tuples of (poly,occ)
	if (mod==1) return;
	
	int b=63-__builtin_clzll(mod);
	
	basis.reset();
	int lo=2,hi=4;
	rep(x,1,b){
		int temp=basis.add(lo^hi,x);
		
		if (temp!=0){
			factor(gcd(mod,temp),ans);
			factor(gcd(mod,temp^1),ans);
			return;
		}
		
		lo=mul(lo,2,mod);
		hi=mul(hi,4,mod);
	}
	
	int mn=1e9;
	rep(x,1,64) if (mod&(1LL<<x)) mn=min(mn,(int)__builtin_ctz(x));
	
	int f=0,fp=0;
	rep(x,0,64) if (mod&(1LL<<x)){
		int y=x>>mn;
		f|=1LL<<y;
		if (y&1) fp|=1LL<<(y-1);
	}
	
	int g=gcd(f,fp);
	int deg=(b>>mn)-(63-__builtin_clzll(g));
	ans.pub({divi(f,g),b/deg});
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	string s;
	cin>>s;
	
	int idx=0;
	while (idx<sz(s) && s[idx]=='0') idx++;
	
	s.erase(s.begin(),s.begin()+idx++);
	
	if (s.empty()){
		cout<<"-1"<<endl;
		return 0;
	}
	
	int mod=0;
	rep(x,0,sz(s)) if (s[x]=='1') mod|=1LL<<x;
	
	if (mod==1){
		cout<<idx<<" "<<idx+1<<endl;
		return 0;
	}
	
	int order=1;
	vector<ii> flist;
	factor(mod,flist);
	for (auto [poly,occ]:flist){
		int b=63-__builtin_clzll(poly);
		order*=(1LL<<b)-1;
		rep(x,1,occ) order*=1LL<<b;
	}
	
	int ans=5e18;
	for (int x=1;x*x<=order;x++){
		if (order%x==0){
			if (pow(x,mod)==1) ans=min(ans,x);
			if (pow(order/x,mod)==1) ans=min(ans,order/x);
		}
	}
	
	cout<<idx<<" "<<idx+ans<<endl;
}