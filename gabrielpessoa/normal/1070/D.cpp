#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int ms = 1e5+5;

int main() {
	ll need = 0, cur = 0;
	ll ans = 0;
	int n, k;
	cin >> n >> k;
	for(int i = 0; i < n; i++) {
		ll aux = (need + k - 1)/k;
		//cout << need << ' ' << k << ' ' << aux << endl;
		ans += aux;
		cur = max(0ll, cur - (aux * k - need));
		need = cur;
		//cout << aux << ' ' << need << endl;
		cin >> cur;
	}
	ans += (need + cur + k - 1)/k;
	cout << ans << endl;
}