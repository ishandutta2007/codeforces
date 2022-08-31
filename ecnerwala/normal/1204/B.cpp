#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	long long N, L, R; cin >> N >> L >> R;
	cout << ((N-L) + (1ll << L) - 1) << ' ' << (((N - R + 2) << (R-1)) - 1) << '\n';

	return 0;
}