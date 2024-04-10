#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<P,int> P1;
typedef pair<P,P> P2;
typedef pair<double,int>Q;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
//#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
ll T,a[200005],A,vall[200005]; int n;
map<ll,int>M; ll ans[200005];
map<ll,vector<int> >vi;
ll gcd(ll a,ll b){
	if(a<b)swap(a,b);
	if(b==0) return a;
	else return gcd(b,a%b);
}
ll modpow(ll x,ll n,ll mod)
{
	ll res=1;
	while(n>0)
	{
		if(n&1) res=res*x%mod;
		x=x*x%mod;
		n>>=1;
	}
	return res;
}
ll extgcd(ll a,ll b,ll &x,ll &y){
	ll g = a; x = 1; y = 0;
	if(b != 0) g = extgcd(b,a%b,y,x),y-=(a/b)*x;
	return g;
}
ll AxB(ll A,ll B,ll C){
	//minimum positive x such that Ax godo b (mod C)
	if(B%gcd(A,C) != 0) return -1;
	ll x,y;
	extgcd(A,C,x,y);
	x = x*B/gcd(A,C)%(C/gcd(A,C));
	return x;
}
int main(){
	cin>>T>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		A += a[i];
	}
	ll cur = 0;
	for(int i=1;i<=n;i++){
		if(i>=2) cur = (a[i]+cur)%T;
		vall[i] = cur;
		if(M.find(cur) != M.end()) continue;
		M[cur] = i;
		vi[cur % gcd(A,T)].pb(i);
	}
	for(map<ll,vector<int> >::iterator it=vi.begin();it!=vi.end();++it){
		vector<int>vec = it->sc;
		ll cyc = it->fi;
		vector<pair<ll,int> >ran;
		for(int i=0;i<vec.size();i++){
			ll dif = vall[vec[i]]-cyc;
			dif = (dif%T+T)%T;
			ll x = AxB(A,dif,T);
			ran.pb(mp(x,vec[i]));
		}
		SORT(ran);
		ll zan = T/gcd(A,T);
		for(int i=0;i<ran.size()-1;i++){
			ans[ran[i].sc] = ran[i+1].fi-ran[i].fi;
			assert(ran[i].fi != ran[i+1].fi);
			zan -= ans[ran[i].sc];
		}
		if(ran.size()){
			ans[ran[ran.size()-1].sc] = zan;
		}
	}
	for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
	cout<<endl;
}