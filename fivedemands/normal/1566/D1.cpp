#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=1e9+7;
const int N=2e6+1;
int n,m;
pair<ll,int>a[100001];
int sz;
int use[100001];
void solve(){
	cin >> n >> m;
	for(int i=0; i<n*m ;i++){
		cin >> a[i].fi;
		a[i].se=i;
	}
	sort(a,a+n*m);
	sz=1;
	use[1]=0;
	for(int i=1; i<n*m ;i++){
		if(i%m==0 || a[i].fi!=a[i-1].fi) use[++sz]=i;
	}
	use[++sz]=n*m;
	for(int i=2; i<=sz ;i++){
		reverse(a+use[i-1],a+use[i]);
	}
	ll ans=0;
	for(int i=0; i<n ;i++){
		for(int j=0; j<m ;j++){
			for(int k=0; k<j ;k++){
				if(a[i*m+k].se<a[i*m+j].se) ans++;
			}
		}
	}
	cout << ans << '\n';
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;while(t--) solve();
}