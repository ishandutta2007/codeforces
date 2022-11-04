#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

const ll INF = 1'000'000'000'000'000;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll k, n, w;
	cin >> k >> n >> w;
	cout << max(0ll, w*(w + 1) / 2 * k - n);
}

/*
















*/