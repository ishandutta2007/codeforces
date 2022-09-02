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
#define mod 998244353
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int n;
ll a[505];
bool bad[1500005];
map<ll,int>M;
ll A[505];
ll gcdd(ll a,ll b){
	if(a<b) swap(a,b);
	if(b == 0) return a;
	else return gcdd(b,a%b);
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]; A[i] = a[i];
	}
	for(int i=2;i<=1500000;i++){
		if(bad[i]) continue;
		for(int j=2;i*j<=1500000;j++) bad[i*j] = 1;
	}
	queue<ll>que;
	for(int i=2;i<=1500000;i++){
		if(bad[i]) continue;
		for(int j=1;j<=n;j++){
			if(a[j]%i != 0) continue;
			vector<ll>vec;
			while(a[j]%i == 0){
				vec.pb(i);
				a[j] /= i;
			}
			if(a[j] == 1){
				M[i] += vec.size();
			}
			else{
				M[i] += vec.size();
				M[a[j]] ++; 
				if(a[j] > 1500000 && M[a[j]] == 1) que.push(a[j]); a[j] = 1;
			}
		}
	}
	//zan -> p^2 p*q
	for(int i=1;i<=n;i++){
		if(a[i] == 1) continue;
		ll d = (ll)(sqrt((double)(a[i])));
		for(ll e = max(1ll,d-10);e <= d+10;e++){
			if(e*e == a[i]){
				M[e] += 2; a[i] = 1;
				if(e > 1500000 && M[e] == 2) que.push(e);
			}
		}
	}
	//zan -> p*q
	while(!que.empty()){
		ll q = que.front(); que.pop();
		for(int i=1;i<=n;i++){
			if(a[i]%q != 0) continue;
			ll x = q, y = a[i]/q;
			a[i] = 1;
			if(x == y){
				M[x] += 2;
			}
			else{
				M[x]++;
				M[y]++;
				if(y > 1500000 && M[y] == 1) que.push(y);
			}
		}
	}
	//zan -> p*q
	for(int i=1;i<=n;i++){
		if(a[i] == 1) continue;
		for(int j=i+1;j<=n;j++){
			if(a[j] == 1) continue;
			if(a[i] == a[j]) continue;
			ll s = gcdd(a[i],a[j]);
			if(s != 1){
				if(M.find(s) == M.end()) que.push(s);
			}
		}
	}
	//zan -> p*q
	while(!que.empty()){
		ll q = que.front(); que.pop();
		for(int i=1;i<=n;i++){
			if(a[i]%q != 0) continue;
			ll x = q, y = a[i]/q;
			a[i] = 1;
			if(x == y){
				M[x] += 2;
			}
			else{
				M[x]++;
				M[y]++;
				if(y > 1500000 && M[y] == 1) que.push(y);
			}
		}
	}
	map<ll,int>another;
	for(int i=1;i<=n;i++){
		if(a[i] == 1) continue;
		assert(a[i] == A[i]);
		another[a[i]]++;
	}
	ll ans = 1;
	for(map<ll,int>::iterator it=M.begin();it!=M.end();it++){
		ans = ans*1LL*(it->sc+1)%mod;
	}
	for(map<ll,int>::iterator it=another.begin();it!=another.end();it++){
		ans = ans*1LL*(it->sc+1)%mod*(it->sc+1)%mod;
	}
	cout << (ans%mod+mod)%mod << endl;
}