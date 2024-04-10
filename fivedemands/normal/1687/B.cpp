#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const int N=2e6+1;
const ll mod=998244353;
ll n,m;
ll a[N],b[N];
int qr[N];
pair<ll,int>e[N];
ll ask(bool reset){
	cout << "? ";
	for(int i=1; i<=m ;i++) cout << qr[i];
	cout << endl;
	ll res;cin >> res;
	if(!reset) return res;
	for(int i=1; i<=m ;i++) qr[i]=0;
	return res;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n >> m;
	for(int i=1; i<=m ;i++){
		qr[i]=true;
		e[i].fi=ask(1);
		e[i].se=i;
	}
	sort(e+1,e+m+1);
	ll ans=0;
	for(int i=1; i<=m ;i++){
		qr[e[i].se]=true;
		ll res=ask(0);
		if(res==ans+e[i].fi) ans+=e[i].fi;
		else qr[e[i].se]=false;
	}
	cout << "! " << ans << endl;
}