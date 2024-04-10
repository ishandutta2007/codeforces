#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int,int> P;
#define fi first
#define sc second
int cnt[100005],n,a[100005],k,T[100005];
int main(){
	cin >> n >> k;
	rep(i,n) cin >> a[i];
	rep(i,n){
		vector<P>vec;
		int V = a[i],tr = 1;
		for(int j=2;j*j<=V;j++){
			if(V%j != 0) continue;
			int C = 0;
			while(V%j == 0){ V /= j; C++; }
			C %= k;
			rep(x,C) tr *= j;
		}
		if(V != 1) tr *= V;
		cnt[tr]++; T[i] = tr;
	}
	ll ans = 0;
	rep(i,n){
		vector<P>vec;
		int V = a[i];
		ll rev = 1;
		for(int j=2;j*j<=V;j++){
			if(V%j != 0) continue;
			int C = 0;
			while(V%j == 0){ V /= j; C++; }
			C %= k;
			rep(x,(k-C)%k){
				if(rev >= 0 && 1e6/rev >= j) rev *= j;
				else rev = -1;
			}
		}
		if(V != 1){
			rep(x,(k-1)%k){
				if(rev >= 0 && 1e6/rev >= V) rev *= V;
				else rev = -1;
			}
		}
		if(rev < 100005 && rev >= 1){
			if(T[i] != rev) ans += cnt[rev];
			else ans += cnt[rev]-1;
		}
	}
	assert(ans%2 == 0);
	cout << ans/2 << endl;
}