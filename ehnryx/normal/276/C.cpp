#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9+7;
const ll INF = 0x7f7f7f7f;
const ll INFLL = 0x7f7f7f7f7f7f7f7f;

#define End return 0; }
#define of ios::sync_with_stdio(0); cin.tie(0);
#define story int main() {
#define The

struct BIT {
	int size;
	vector<ll> f;
	BIT(int n) {
		f.resize(n+1);
		memset(&f[0], 0, (n+1)*sizeof(f[0]));
		size = n;
	}
	void insert(int x, ll c=1) {
		for ( ; x <= size; x += x & -x)
			f[x] += c;
	}
	void insert_range(int xl, int xr, ll c=1) {
		insert(xl, c);
		insert(xr+1, -c);
	}
	ll query(int x) {
		ll sum = 0;
		for ( ; x; x -= x & -x)
			sum += f[x];
		return sum;
	}
};

The story of idk_why_this_contest_is_obsessed_with_little_girls:

int n, q;
cin >> n >> q;
vector<ll> arr(n);
vector<ll> freq(n);
for (int i = 0; i < n; i++) {
	cin >> arr[i];
} sort(arr.begin(), arr.end());

int a, b;
BIT bit(n);
for (int i = 0; i < q; i++) {
	cin >> a >> b;
	bit.insert_range(a, b);
}
for (int i = 0; i < n; i++) {
	freq[i] = bit.query(i+1);
} sort(freq.begin(), freq.end());

ll ans = 0;
for (int i = 0; i < n; i++) {
	ans += freq[i]*arr[i];
}
cout << ans << endl;

The End