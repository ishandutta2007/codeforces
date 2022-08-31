#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;

ll choose[3000][3050];

int main() {
	for(ll i = 0; i < 3000; i++) {
		choose[i][0] = choose[i][i] = 1;
		for(ll j = 1; j < i; j++) {
			choose[i][j] = choose[i - 1][j - 1] + choose[i - 1][j];
			if(choose[i][j] >= MOD) choose[i][j] -= MOD;
		}
	}

	ll K; cin >> K;
	ll cnt = 0;
	ll ways = 1;
	for(ll i = 0; i < K; i++) {
		ll c;
		cin >> c;
		ways *= choose[cnt + c - 1][cnt];
		ways %= MOD;
		cnt += c;
	}

	cout << ways % MOD << '\n';

	return 0;
}