#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const ll mod = 1000003;

ll modPow(ll a, ll b){
	ll ret = 1;
	while(b){
		if(b&1)(ret *= a) %= mod;
		(a *= a) %= mod;
		b >>= 1;
	}
	return ret;
}

void GaussMod(vector<vector<ll> > &a){
	int n = a.size();
	int m = a[0].size();
	for(int i = 0; i < n; i++){
		if(a[i][i] == 0){
			for(int j = i+1; j < n; j++){
				if(a[j][i] != 0){
					swap(a[i], a[j]);
					break;
				}
			}
		}
		ll inv = modPow(a[i][i], mod - 2);
		for(int j = 0; j < n; j++){
			if(i == j)continue;
			ll prd = (a[j][i]*inv)%mod;
			for(int k = 0; k < m; k++){
				a[j][k] -= (prd*a[i][k])%mod;
				if(a[j][k] < 0)a[j][k] += mod;
			}
		}
		for(int j = 0; j < m; j++){
			(a[i][j] *= inv) %= mod;
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	ll val;
	vector<vector<ll> > a(11, vector<ll>(12));

	for(int i = 0; i < 11; i++){
		ll st = 1, prd = (1<<i);
		for(int j = 0; j < 11; j++){
			a[i][j] = st;
			(st *= prd) %= mod;
		}
		cout<<"? "<<prd<<endl;
		cin>>val;
		a[i][11] = val;
	}
	GaussMod(a);
	vector<ll> coef(11);
	for(int i = 0; i < 11; i++){
		coef[i] = a[i][11];
	}
	for(int i = 0; i < mod; i++){
		ll val = 0, prd = i, st = 1;
		for(int j = 0; j < 11; j++){
			val += coef[j]*st%mod;
			(st *= prd) %= mod;
			if(val >= mod)val -= mod;
		}
		if(val == 0){
			cout<<"! "<<i<<endl;
			return 0;
		}
	}
	cout<<"! -1"<<endl;
	return 0;
}