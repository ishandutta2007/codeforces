#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt(){
	int x;
	scanf("%d", &x);
	return x;
}

struct Fenwick{
	vector<long long> a;
	int n;

	Fenwick(int n = 0):n(n){
		a.resize(n);
	}

	void add(int pos, int x){
		while (pos < n){
			a[pos] += x;
			pos |= (pos + 1);
		}
	}

	long long get(int pos){
		long long res = 0;
		while (pos >= 0){
			res += a[pos];
			pos = (pos & (pos + 1)) - 1;
		}
		return res;
	}
};

int main(){

	int n = nxt(), k = nxt(), a = nxt(), b = nxt(), q = nxt();
	vector<int> ar(n);
	Fenwick L(n), R(n);

	while (q--){
		int t = nxt();
		if (t == 1){
			int d = nxt() - 1, x = nxt();
			int lx = min(x, max(0, b - ar[d]));
			int rx = min(x, max(0, a - ar[d]));
			ar[d] += x;
			L.add(d, lx);
			R.add(n - 1 - d, rx);
		} else {
			int p = nxt() - 1;
			printf("%I64d\n", L.get(p - 1) + R.get(n - p - k - 1));
		}
	}

	return 0;
}