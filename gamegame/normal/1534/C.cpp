#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const int N=2e6+1;
const ll mod=1e9+7;
ll n,m;
ll a[N],b[N],p[N];
int find(int x){
	if(p[x]!=x) p[x]=find(p[x]);
	return p[x];
}
bool join(int x,int y){
	x=find(x);y=find(y);
	if(x==y) return false;
	p[x]=y;
	return true;
}
void solve(){
	cin >> n;
	for(int i=1; i<=n ;i++) p[i]=i;
	for(int i=1; i<=n ;i++) cin >> a[i];
	int cc=n;
	for(int i=1; i<=n ;i++){
		cin >> b[i];
		if(join(a[i],b[i])) cc--;
	}
	ll ans=1;
	for(int i=1; i<=cc ;i++) ans=ans*2%mod;
	cout << ans << '\n';
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;while(t--) solve();
}