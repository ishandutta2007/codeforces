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
		int N;
		cin >> N;
		int k = N / 2020;
		if (N <= k * 2021) cout << "YES" << ln;
		else cout << "NO" << ln;
	}
}