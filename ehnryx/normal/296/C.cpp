#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll MOD = 1e9+7;
const ll INF = 0x7f7f7f7f;
const ll INFLL = 0x7f7f7f7f7f7f7f7f;

#define End return 0; }
#define of ios::sync_with_stdio(0); cin.tie(0);
#define story int main() {
#define The

struct BIT {
	int size;
	vector<ll> freq;
	BIT(int n) {
		freq.resize(n+1);
		memset(&freq[0], 0, (n+1)*sizeof(freq[0]));
		size = n;
	}
	void insert(int x, ll c=1) {
		for ( ; x <= size; x += x & -x) freq[x] += c;
	}
	void insert_range(int xl, int xr, ll c=1) {
		insert(xl, c);
		insert(xr+1, -c);
	}
	ll query(int x) {
		ll sum = 0;
		for ( ; x; x -= x & -x) sum += freq[x];
		return sum;
	}
};
struct query {
	int a, b;
	ll d;
};

The story of BITS:

int a, b;
int n, m, k;
cin >> n >> m >> k;
vector<ll> arr(n);
for (int i = 0; i < n; i++) {
	cin >> arr[i];
}
vector<query> q(m);
for (int i = 0; i < m; i++) {
	cin >> q[i].a >> q[i].b >> q[i].d;
}
BIT qbit(m);
for (int i = 0; i < k; i++) {
	cin >> a >> b;
	qbit.insert_range(a, b);
}
BIT nbit(n);
for (int i = 0; i < m; i++) {
	nbit.insert_range(q[i].a, q[i].b, q[i].d*qbit.query(i+1));
}
for (int i = 0; i < n; i++) {
	cout << arr[i] + nbit.query(i+1) << " ";
} cout << endl;

The End