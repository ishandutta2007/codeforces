#include <bits/stdc++.h>
using namespace std;

const int SIZE = 1E6 + 5;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;

vii pf;
ll smallest = INFLL;
ll biggest = 0;

ll fastExp(ll a, ll b) {
	if(b == 0) return 1;
	ll resp = fastExp(a, b/2);
	resp *= resp;
	if(b % 2) resp *= a;
	return resp;
}
void completeSearch(ll num, ll a, ll b, ll c, int pos) {
	//printf("Cheguei com %lld %lld %lld %lld %d\n", num, a, b, c, pos);
	if(pos == pf.size()) {
		ll total = ((a+1) * (b+2) * (c+2)) - num;
		biggest = max(biggest, total);
		smallest = min(smallest, total);
		return;
	}
	ll prime = pf[pos].first;
	ll amount = pf[pos].second;
	//printf("%lld tem %lld\n", prime, amount);
	for(ll i = 0; i <= amount; i++) {
		ll aTemp = fastExp(prime, i) * a;
		//printf("aTemp de %lld eh %lld\n", i, aTemp);
		for(ll j = 0; j <= (amount - i); j++) {
			ll bTemp = fastExp(prime, j) * b;
			ll cTemp = fastExp(prime, amount - i - j) * c;
			completeSearch(num, aTemp, bTemp, cTemp, pos + 1);
		}
	}
}

int main() {
	int n;
	scanf("%d", &n);
	ll num = n;
	for(int i = 2; i * i <= n; i++) {
		int qnt = 0;
		while(n % i == 0) {
			qnt++;
			n /= i;
		}
		if(qnt) pf.push_back(ii(i, qnt));
	}
	if(n > 1) {
		pf.push_back(ii(n, 1));
	}
	completeSearch(num, 1, 1, 1, 0);
	cout << smallest << " " << biggest;	
}