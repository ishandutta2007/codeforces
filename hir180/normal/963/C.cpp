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
int n;
ll w[200005],h[200005],c[200005];
map<ll,ll>W,H;
vector<pair<ll,ll> >wv,hv;
map<pair<ll,ll>,ll>cnt;
ll gcd(ll a,ll b){
	if(a<b)swap(a,b);
	if(b==0) return a;
	else return gcd(b,a%b);
}
int main(){
	scanf("%d",&n);
	ll G = 0;
	rep(i,n){
		scanf("%lld%lld%lld",&w[i],&h[i],&c[i]);
		W[w[i]]+=c[i];
		H[h[i]]+=c[i];
		cnt[mp(w[i],h[i])] = c[i];
		G = gcd(G,c[i]);
	}
	int ws = W.size();
	int wh = H.size();
	if(1LL*ws*wh != n){
		puts("0"); return 0;
	}
	for(map<ll,ll>::iterator it=W.begin();it!=W.end();++it){
		wv.pb(mp(it->fi,it->sc));
	}
	for(map<ll,ll>::iterator it=H.begin();it!=H.end();++it){
		hv.pb(mp(it->fi,it->sc));
	}
	vector<ll>V;
	for(int i=0;i<wv.size();i++){
		for(int j=0;j<hv.size();j++){
			ll a = cnt[mp(wv[i].fi,hv[0].fi)];
			ll b = hv[0].sc;
			ll c = cnt[mp(wv[i].fi,hv[j].fi)];
			ll d = hv[j].sc;
			//a/b = c/d
			ll A = a / gcd(a,b);
			ll B = b / gcd(a,b);
			ll C = c / gcd(c,d);
			ll D = d / gcd(c,d);
			if(A == C && B == D);
			else{
				puts("0"); return 0;
			}
		}
	}
	for(int j=0;j<hv.size();j++){
		for(int i=0;i<wv.size();i++){
			ll a = cnt[mp(wv[0].fi,hv[j].fi)];
			ll b = wv[0].sc;
			ll c = cnt[mp(wv[i].fi,hv[j].fi)];
			ll d = wv[i].sc;
			//a/b = c/d
			ll A = a / gcd(a,b);
			ll B = b / gcd(a,b);
			ll C = c / gcd(c,d);
			ll D = d / gcd(c,d);
			if(A == C && B == D);
			else{
				puts("0"); return 0;
			}
		}
	}
	int ans = 0;
	for(ll i=1;i*i<=G;i++){
		if(G%i == 0) ans++;
		if(G%i == 0 && i*i != G) ans++;
	}
	cout << ans << endl;
}