#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef pair<ii, int> iii;
typedef pair<ll, ll> llll;

const int SIZE  = 1E5+5;
const int MOD = 1E9+7;
const int DELTA = 1E5+2;
const double PI = atan(1)*4;
const double EPS = 1e-7;
const int INF = 0x3f3f3f3f;
const double INFF = 1e100;

ll s1[SIZE];
ll s2[SIZE];

ll fastExp(ll a, ll b) {
	if(b == 0) return 1;
	ll resposta = fastExp(a, b/2);
	resposta = (resposta * resposta) % MOD;
	if(b & 1) resposta = (resposta * a) % MOD;
	return resposta;
}

int main() {
	ll n, m;
	scanf("%lld %lld", &n, &m);
	for(int i = 0; i < n; i++) {
		scanf("%lld", s1+i);
	}
	for(int i = 0; i < n; i++) {
		scanf("%lld", s2+i);
	}
	ll resposta = 0;
	ll probEqual = 1;
	ll inverseM = fastExp(m, MOD - 2);	
	ll probMaiorAux = (((((m * m) % MOD - m) % MOD * fastExp(2, MOD - 2)) % MOD) * inverseM) % MOD;
	for(int i = 0; i < n; i++) {
		if(s1[i] && s2[i]) {
			if(s1[i] > s2[i]) {
				resposta = (resposta + probEqual) % MOD;
				probEqual = 0;
				break;
			} else if(s1[i] < s2[i]) {
				probEqual = 0;
				break;
			} 
		} else if(s1[i]) {
			resposta = (resposta + ((inverseM*(s1[i] - 1)) % MOD * probEqual) % MOD ) % MOD;
			probEqual = (probEqual * inverseM) % MOD;
		} else if(s2[i]) {
			resposta = (resposta + ((inverseM *(m - s2[i])) % MOD * probEqual) % MOD) % MOD;
			probEqual = (probEqual * inverseM) % MOD;
		} else {
			resposta = (resposta + ((inverseM * probMaiorAux) % MOD * probEqual) % MOD) % MOD;
			probEqual = (probEqual * inverseM) % MOD;
		}
	}
	//cout << probMaiorAux << '\n';
	cout << resposta << '\n';
	return 0;
}