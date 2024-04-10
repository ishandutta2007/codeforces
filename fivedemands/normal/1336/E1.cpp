#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
#define fi first
#define se second
int n,m;
int z=15;
ll a[36];
ll b[65536];
ll c[65536];
ll d[65536];
ll ans[36];
vector<int>v[21];
ll pw(ll x,ll y){
	if(y==0) return 1;
	if(y%2) return x*pw(x,y-1)%mod;
	ll res=pw(x,y/2);
	return res*res%mod;
}
void FWHT(ll* P, bool inverse) {
    for (int len = 1; 2 * len <= (1<<z); len <<= 1) {
        for (int i = 0; i < (1<<z); i += 2 * len) {
            for (int j = 0; j < len; j++) {
                ll u = P[i + j];
                ll v = P[i + len + j];
                P[i + j] =( u + v)%mod;
                P[i + len + j] = (u - v+mod)%mod;
            }
        }
    }
    ll god=pw((1<<z),mod-2);
    if (inverse) {
        for (int i = 0; i < (1<<z); i++)
            P[i] = P[i] *god%mod;
    }
}
void conv(){
	FWHT(b,0);
	for(int i=0; i<(1<<z) ;i++){
		d[i]=b[i]*c[i]%mod;
	}
	FWHT(d,1);
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n >> m;
	int bona=0;
	for(int i=1; i<=n ;i++){
		ll x;cin >> x;
		for(int i=m-1; i>=0 ;i--){
			if(x&(1LL<<i)){
				if(a[i]==0){
					a[i]=x;
					break;
				}
				else x^=a[i];
			}
		}
		if(x==0) bona++;
	}
	z=3*m/7;
	for(int i=0; i<(1<<(m-z)) ;i++){
		bool ok=true;
		ll x=0;
		for(int j=z; j<m ;j++){
			if((i&(1LL<<(j-z)))==0) continue;
			if(a[j]==0) ok=false;
			x^=a[j];
		}
		if(!ok) continue;
		int c=0;
		for(int j=z; j<m ;j++){
			if(x&(1LL<<j)) c++;
		}
		x&=(1<<z)-1;
		v[c].push_back(x);
	}
	for(int i=0; i<(1<<z) ;i++){
		ll x=0;
		bool ok=true;
		for(int j=0; j<z ;j++){
			if((i&(1LL<<j))==0) continue;
			if(a[j]==0) ok=false;
			x^=a[j];
		}
		if(!ok) continue;
		c[x]++;
	}
	FWHT(c,0);
	for(int i=0; i<=m-z ;i++){
		for(int j=0; j<(1<<z) ;j++) b[j]=0;
		for(auto c:v[i]) b[c]++;
		conv();
		for(int j=0; j<(1<<z) ;j++){
			ans[i+__builtin_popcount(j)]+=d[j];
		}
	}
	ll god=pw(2,bona);
	for(int i=0; i<=m ;i++) cout << ans[i]*god%mod << ' ';
}