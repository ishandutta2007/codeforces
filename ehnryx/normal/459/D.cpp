#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct BIT {
	int size;
	vector<ll> freq;
	BIT(int n) {
		size = n;
		freq.resize(n+1);
		memset(&freq[0], 0, (n+1)*sizeof(freq[0]));
	}
	void insert(int x, ll cnt=1) {
		for ( ; x <= size; x += x & -x) freq[x] += cnt;
	}
	ll query(int xl, int xr) {
		return query(xr) - query(xl-1);
	}
	ll query(int x) {
		ll sum = 0;
		for ( ; x > 0; x -= x & -x) sum += freq[x];
		return sum;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	int a[n];
	map<int,int> nums;
	int left[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (nums.count(a[i])) nums[a[i]]++;
		else nums.insert(pair<int,int>(a[i], 1));
		left[i] = nums[a[i]];
	}
	nums.clear();
	int right[n];
	for (int i = n-1; i >= 0; i--) {
		if (nums.count(a[i])) nums[a[i]]++;
		else nums.insert(pair<int,int>(a[i], 1));
		right[i] = nums[a[i]];
	}

	ll ans = 0;
	BIT freq(n);
	for (int i = n-1; i >= 0; i--) {
		if (left[i] > 1) 
			ans += freq.query(1, left[i]-1);
		freq.insert(right[i]);
	}
	cout << ans << endl;

	return 0;
}