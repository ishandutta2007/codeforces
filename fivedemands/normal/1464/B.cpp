#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=998244353;
const int N=2e6+1;
string s;
ll n,m;
ll a[N];
ll bit[N];
ll c01,c10;
ll cost=0;
ll ans=1e18;
void upd(int id,int v){
	for(int i=id; i<=n ;i+=i&-i) bit[i]+=v;
}
ll qr(int x){
	ll res=0;
	for(int i=x; i>=1 ;i-=i&-i) res+=bit[i];
	return res;
}
ll get(int l,int r){
	return qr(r)-qr(l-1);
}
void ping(int x){
	int p1=get(1,x-1);
	int s1=get(x+1,n);
	int p0=x-1-p1;
	int s0=n-x-s1;
	if(a[x]==0){
		cost-=c10*p1;
		cost-=c01*s1;
		upd(x,1);
		cost+=c01*p0;
		cost+=c10*s0;
	}
	else{
		cost-=c01*p0;
		cost-=c10*s0;
		upd(x,-1);
		cost+=c10*p1;
		cost+=c01*s1;
	}
	a[x]^=1;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> s;n=s.size();s='?'+s;
	cin >> c01 >> c10;
	for(int i=1; i<=n ;i++){
		if(s[i]=='1') ping(i);
	}
	ans=cost;
	for(int i=1; i<=n ;i++){
		if(s[i]=='?') ping(i);
		ans=min(ans,cost);
	}
	for(int i=1; i<=n ;i++){
		if(s[i]=='?') ping(i);
		ans=min(ans,cost);
	}
	cout << ans << endl;
}