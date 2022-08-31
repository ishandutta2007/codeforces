#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
int n;
const int N=3e5+1;
const ll mod=998244353;
pair<int,int>a[N];
ll f[N],inf[N];
map<pair<int,int>,int>m1,m2,m3;
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n;
	f[0]=1;
	for(int i=1; i<=n ;i++){
		cin >> a[i].fi >> a[i].se;
		f[i]=f[i-1]*i%mod;
		m1[{a[i].fi,0}]++;
		m2[{a[i].se,0}]++;
		m3[a[i]]++;
	}
	sort(a+1,a+n+1);
	ll w1=1,w2=1,w3=1;
	for(auto cur:m1){
		w1=w1*f[cur.se]%mod;
	}
	for(auto cur:m2){
		w2=w2*f[cur.se]%mod;
	}
	for(auto cur:m3){
		w3=w3*f[cur.se]%mod;
	}
	for(int i=2; i<=n ;i++){
		if(a[i].se<a[i-1].se) w3=0;
	}
	//cout << w1 << ' ' << w2 << ' ' << w3 << endl;
	ll ans=f[n]-w1-w2+w3;
	ans%=mod;
	if(ans<0) ans+=mod;
	cout << ans << endl;
}