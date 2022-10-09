#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

#define int long long
#define all(x) x.begin(), x.end()
#define pb emplace_back
#define mp make_pair

using namespace std;

void setup() {
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#else
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);
	#endif

	//srand(time(NULL));
}

int gcd(int a, int b) {
	if (a == 0)
		return b;
	return (gcd(b % a, a));
}

signed main() {
	setup();
	
	int a, b;
	cin >> a >> b;
	int d = gcd(a, b);

	vector<int> dl;
	for(int i = 1; i * i <= d; ++i) {
		if (d % i == 0)
			dl.push_back(i);
	}
	int z = dl.size();
	for(int i = z - 1; i >= 0; --i)  {
		if (dl[i] * dl[i] != d)
			dl.push_back(d / dl[i]);
	}

	int t;
	cin >> t;
	for(int i = 0; i < t; ++i) {
		int l, r;
		cin >> l >> r;
		int left = 0, right = dl.size();
		while (right - left > 1) {
			int middle = (left + right) / 2;
			if (dl[middle] > r)
				right = middle;
			else
				left = middle;
		}
		if (dl[left] >= l)
			cout << dl[left] << '\n';
		else 
			cout << -1 << '\n';
	}
}