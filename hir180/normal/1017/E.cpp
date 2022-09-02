#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
typedef pair<ll,ll> Q;
bool cmp(Q p,Q q)
{
	if(p.fi != q.fi) return p.fi < q.fi;
	return p.sc < q.sc;
}
ll det(Q a,Q b)
{
	return a.fi*b.sc - a.sc*b.fi;
}
vector<Q> convex_hull(vector<Q>vs)
{
	sort(vs.begin(),vs.end(),cmp);
	int k = 0;
	vector<Q>qs (vs.size()*2);
	
	for(int i=0;i<vs.size();i++)
	{
		while(k>1 && det(mp(qs[k-1].fi-qs[k-2].fi,qs[k-1].sc-qs[k-2].sc),mp(vs[i].fi-qs[k-1].fi,vs[i].sc-qs[k-1].sc))<=0)
		{
			k--;
		}
		qs[k++] = vs[i];
	}
	for(int i=vs.size()-2,t = k;i>=0;i--)
	{
		while(k>t && det(mp(qs[k-1].fi-qs[k-2].fi,qs[k-1].sc-qs[k-2].sc),mp(vs[i].fi-qs[k-1].fi,vs[i].sc-qs[k-1].sc))<=0)
		{
			k--;
		}
		qs[k++] = vs[i];
	}
	qs.resize(k-1);
	return qs;
}
ll dist(Q a,Q b){
	return (a.fi-b.fi)*(a.fi-b.fi)+(a.sc-b.sc)*(a.sc-b.sc);
}
int n,m;
vector<Q>x,y;
ll val[200005][3];
ll modpow(ll x,ll n){
	ll res=1;
	while(n>0){
		if(n&1) res=res*x%mod;
		x=x*x%mod;
		n>>=1;
	}
	return res;
}
int main(){
	cin>>n>>m;
	rep(i,n){
		ll xx,yy; scanf("%lld%lld",&xx,&yy);
		x.pb(mp(xx,yy));
	}
	rep(i,m){
		ll xx,yy; scanf("%lld%lld",&xx,&yy);
		y.pb(mp(xx,yy));
	}
	vector<Q>h1,h2;
	h1 = convex_hull(x);
	h2 = convex_hull(y);
	if(h1.size() != h2.size()){
		puts("NO");
		return 0;
	}
	//
	vector<pair<ll,Q> >L1,L2;
	for(int i=0;i<h1.size();i++){
		Q a = h1[i];
		Q b = h1[(i+1)%h1.size()];
		Q c = h1[(i+2)%h1.size()];
		ll x = dist(a,b);
		ll y = dist(b,c);
		ll z = dist(c,a);
		L1.pb(mp(x,mp(y,z)));
		//cout<<x<<" "<<y<<" "<<z<<endl;
	}
	int sz = L1.size();
	for(int i=0;i<sz;i++){
		L1.pb(L1[i]);
	}
	ll cur = 1;
	vector<ll>prime;
	prime.pb(3) ; prime.pb(5) ;prime.pb(7);
	srand((unsigned)time(NULL));
	int w = rand()%3;
	if(w<0) w+=3;
	ll pp = prime[w];
	for(int i=0;i<L1.size();i++){
		val[i][0] += cur * (L1[i].fi % mod) % mod;
		val[i][1] += cur * (L1[i].sc.fi % mod) % mod;
		val[i][2] += cur * (L1[i].sc.sc % mod) % mod;
		if(i){
			rep(j,3){
				val[i][j] += val[i-1][j];
				val[i][j] %= mod;
			}
		}
		cur = cur * pp % mod;
	}
	for(int i=0;i<h2.size();i++){
		Q a = h2[i];
		Q b = h2[(i+1)%h2.size()];
		Q c = h2[(i+2)%h2.size()];
		ll x = dist(a,b);
		ll y = dist(b,c);
		ll z = dist(c,a);
		//cout<<x<<" "<<y<<" "<<z<<endl;
		L2.pb(mp(x,mp(y,z)));
	}
	cur = 1;
	ll V[3]={};
	for(int i=0;i<L2.size();i++){
		V[0] += cur * (L2[i].fi%mod) % mod;
		V[1] += cur * (L2[i].sc.fi%mod) % mod;
		V[2] += cur * (L2[i].sc.sc%mod) % mod;
		rep(j,3) V[j]%=mod;
		cur = cur * pp % mod;
	}
	cur = 1;
	for(int i=L2.size()-1;i<L1.size();i++){
		ll C[3]={};
		rep(j,3) C[j] = (val[i][j]%mod+mod)%mod;
		if(i != L2.size()-1){
			rep(j,3){
				C[j] = C[j]-val[i-L2.size()][j];
				C[j] = (C[j]%mod+mod)%mod;
			}
		}
		//cout<<C[0]<<" "<<C[1]<<" "<<C[2]<<endl;
		rep(j,3){
			C[j] = C[j]*modpow(cur,mod-2)%mod;
			if(C[j] != V[j]) goto fail;
		}
		for(int j=i+1-L2.size();j<=i;j++){
			pair<ll,Q> x = L1[j];
			pair<ll,Q> y = L2[j+L2.size()-i-1];
			if(x != y) goto fail;
		}
		puts("YES"); return 0;
		fail:;
		cur = cur * pp % mod;
	}
	puts("NO");
}