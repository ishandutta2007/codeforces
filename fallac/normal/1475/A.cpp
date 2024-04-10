#include <bits/stdc++.h>
using namespace std;
#define MAX 3000
#define all(v) v.begin(), v.end()
#define ln '\n'
#define MOD 993244853
typedef long long ll;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while (T-- > 0) {
		ll N;
		cin >> N;
		while (N % 2 == 0) N /= 2;
		if (N == 1) cout << "NO" << ln;
		else cout << "YES" << ln;
	}
}