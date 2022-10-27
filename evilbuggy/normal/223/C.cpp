#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod = 1000000007;
const int maxn = 2005;

ll k, ncr[maxn], a[maxn], s[maxn];

ll modPow(ll a, ll b){
	ll ans = 1;
	while(b){
		if(b&1)(ans *= a) %= mod;
		(a *= a) %= mod;
		b >>= 1;
	}
	return ans;
}

ll compute(ll n, ll r){
	if(n < r)return 0;
	ll num = 1, den = 1;
	for(int i = 1; i <= r; i++){
		(num *= (n+1-i)) %= mod;
		(den *= i) %= mod;
	}
	num *= modPow(den, mod - 2);
	return num%mod;
}

void pre(){
	for(int i = 0; i < maxn; i++){
		ncr[i] = compute(k-1+i, i);
	}
}

int main(){
	int n;
	cin>>n>>k;
	pre();
	for(int i = 1; i <= n; i++){
		cin>>a[i];
		s[i] = 0;
		if(k == 0){
			cout<<a[i]<<" ";
		}
	}
	if(k == 0){
		cout<<endl;
		exit(0);
	}
	for(int i = 1; i <= n; i++){
		for(int j = i; j <= n; j++){
			(s[j] += a[i]*ncr[j-i]) %= mod;
		}
	}
	for(int i = 1; i <= n; i++){
		cout<<s[i]<<" ";
	}
	cout<<endl;
}