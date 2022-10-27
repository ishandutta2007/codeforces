#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	for(int a = 2; a + a < n - 1; a++){
		int b = n - 1 - a;
		if(__gcd(a, b) == 1){
			cout << a << " " << b << " " << 1 << '\n';
			return;
		}
	}
	assert(false);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--)solve();

	return 0;
}