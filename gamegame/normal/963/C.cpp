#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define pb push_back
int n;
ll gcd(ll x,ll y){
	if(y==0) return x;
	else return gcd(y,x%y);
}
vector<pair<ll,ll> >v[200001];
ll w[200001],h[200001],c[200001];
pair<ll,int>w2[200001];
void no(){
	cout << "0\n";
	exit(0);
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<=n ;i++){
		cin >> w[i] >> h[i] >> c[i];
		w2[i]={w[i],i};
	}
	sort(w2+1,w2+n+1);
	for(int i=1; i<=n ;i++){
		if(w2[i].fi==w2[i-1].fi) w[w2[i].se]=w[w2[i-1].se];
		else w[w2[i].se]=i;
		v[w[w2[i].se]].pb({h[w2[i].se],c[w2[i].se]});
	}
	ll g=0;
	sort(v[1].begin(),v[1].end());
	for(auto i:v[1]) g=gcd(i.se,g);
	for(auto &i:v[1]) i.se/=g;
	for(int i=2; i<=n ;i++){
		if(v[i].empty()) continue;
		sort(v[i].begin(),v[i].end());
		if(v[i].size()!=v[1].size()) no();
		if(v[i][0].se%v[1][0].se!=0 || v[i][0].fi!=v[1][0].fi) no();
		ll k=v[i][0].se/v[1][0].se;
		g=gcd(g,k);
		for(int j=0; j<v[i].size() ;j++){
			auto cur=v[i][j],cur2=v[1][j];
			if(cur.se%cur2.se!=0 || cur.se/cur2.se!=k || cur.fi!=cur2.fi) no();
		}
	}
	ll ans=1;
	for(int i=2; i<=1e6 ;i++){
		int cnt=1;
		while(g%i==0){
			g/=i;
			cnt++;
		}
		ans*=cnt;
	}
	if(g!=1) ans*=2;
	cout << ans << endl;
}