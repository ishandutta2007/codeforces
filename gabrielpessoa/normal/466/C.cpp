#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int SIZE = 5e5+5;

ll arr[SIZE];
ll somaAcc[SIZE];
ll somaAccR[SIZE];

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%lld", &arr[i]);
	}
	for(int i = 1; i <= n; i++) {
		somaAcc[i] = somaAcc[i-1] + arr[i];
	}
	for(int i = n; i >= 1; i--) {
		somaAccR[i] = somaAccR[i+1] + arr[i];
	}
	if(somaAcc[n] % 3) {
		cout << 0 << '\n';
		return 0;
	}
	ll qnt = 0, resposta = 0;
	ll nec = somaAcc[n] / 3;
	for(int i = n; i >= 2; i--) {
		if(somaAccR[i] == nec) qnt++;
	}
	for(int i = 1; i < n; i++) {
		if(somaAccR[i+1] == nec) qnt--;
		if(somaAcc[i] == nec) resposta += qnt;
		//cout << somaAcc[i] << ' ' << somaAccR[i] << ' ' << qnt << ' ' << resposta << '\n';
	}
	cout << resposta << '\n';
}