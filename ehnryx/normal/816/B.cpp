#include <bits/stdc++.h>
using namespace std;

typedef int ll;
const ll MAXN = 200000;
struct BITree { ll freq[MAXN+1]; BITree() { memset(freq, 0, sizeof freq); }
  void insert(int x, ll cnt=1) {
    for ( ; x <= MAXN; x += x & -x) freq[x] += cnt;
      //for (int y = argy; y <= MAXN; y += y & -y) freq[x][y] += cnt;
  }
  ll query(int x) { ll sum = 0;
    for ( ; x; x -= x & -x) sum += freq[x];
      //for (int y = argy; y; y -= y & -y) sum += freq[x][y];
    return sum; }
  void insert_range(int xl,int xr,ll cnt=1) {insert(xl,cnt); insert(xr+1,-cnt);}
  ll query_range(int xl, int xr) { return query(xr) - query(xl-1); }
  int get_nth(ll n) { int x = 1<<30; // assumes non-negative frequencies
    for (int step = x>>1; step; step >>= 1)
      if (x-step > MAXN || freq[x-step] >= n) x -= step; else n -= freq[x-step];
    return x; }
};

int main() {
	BITree bit, ans;
	int n, k, q;
	int a, b;
	cin >> n >> k >> q;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		bit.insert_range(a, b);
	}
	for (int i = 1; i <= 200000; i++) {
		if (bit.query(i) >= k)
			ans.insert(i);
	}
	for (int i = 0; i < q; i++) {
		cin >> a >> b;
		cout << ans.query_range(a, b) << endl;
	}
	return 0;
}