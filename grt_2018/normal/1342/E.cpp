#include <bits/stdc++.h>
#define PB push_back
#define ST first
#define ND second
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
//mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

using namespace std;

using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;

const int nax = 200*1000+10, mod = 998244353;

int fast_pow(int a,int b) {
	int w = 1;
	while(b>0) {
		if(b&1) {
			w = ((ll)w*a)%mod;
		}
		b/=2;
		a = ((ll)a*a)%mod;
	}
	return w;
}

int fact[nax], inv[nax], pot[nax];
int n;
ll k;

int bin(int a,int b) {
	return (((ll)((ll)fact[a]*inv[b])%mod)*inv[a-b])%mod;
}

int main() {_
	cin >> n >> k;
	if(k >= n) {
		cout << "0";
		return 0;
	}
	int cnt = n - k;
	fact[0] = inv[0] = 1;
	fact[1] = inv[1] = 1;
	pot[1] = cnt-1;
	pot[0] = 1;
	for(int i = 2; i <= n; ++i) {
		fact[i] = ((ll)fact[i-1]*i)%mod;
		inv[i] = fast_pow(fact[i],mod-2);
		pot[i] = ((ll)pot[i-1] * (cnt-1))%mod;
	}
	int ans = bin(n,cnt);
	int sum = 0;
	for(int i = 0; i < cnt; ++i) {
		if(i&1) sum = (sum-(ll)bin(cnt,i)*fast_pow(cnt-i,n))%mod;
		else sum = (sum + (ll)bin(cnt,i)*fast_pow(cnt-i,n))%mod;
		if(sum<0) sum+=mod;
	}
	ans = ((ll)ans*sum)%mod;
	if(cnt != n) ans = (ans*2)%mod;
	cout << ans;
	
}