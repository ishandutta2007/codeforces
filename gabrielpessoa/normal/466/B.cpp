#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int SIZE = 5e5+5;
const ll INF = 1e9;

ll arr[SIZE];
ll somaAcc[SIZE];
ll somaAccR[SIZE];

int main() {
	ll n, a, b;
	cin >> n >> a >> b;
	n *= 6;
	ll x = min(a, b);
	ll y = max(a, b);
	if(a * b < n) {
		ll menorA = INF;
		ll menorB = INF;
		for(ll i = x; (i-1) * (i-1) <= n; i++) {
			if(i * max(y, ((n-1)/i + 1)) < menorA * menorB) {
				menorA = i;
				menorB = max(y, ((n-1)/i+1));
			}
		}
		if(x != a) swap(menorA, menorB);
		a = menorA;
		b = menorB;
	}
	cout << a * b << '\n' << a << ' ' << b << '\n';
}