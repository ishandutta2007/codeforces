#include <bits/stdc++.h>
using namespace std;

const int SIZE = 1E5 + 5;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;

ll prefixSum[SIZE];
ll n, k;
map<ll, ll> dic;

int main() {
	scanf("%lld %lld", &n, &k);
	ll soma = 0, resposta = 0;
	dic[0] = 1;
	for(ll i = 1; i <= n; i++) {
		ll x;
		scanf("%lld", &x);
		soma += abs(x);
		prefixSum[i] = prefixSum[i-1] + x;
		ll atual = 1;
		while(abs(atual) <= soma) {
			resposta += dic[prefixSum[i] - atual];
			//printf("%lld: %lld %lld\n", atual, prefixSum[i], dic[atual - prefixSum[i]]);
			atual *= k;
			if(atual == 1) break;
		}
		dic[prefixSum[i]]++;
	}
	printf("%lld\n", resposta);
}