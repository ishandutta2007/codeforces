#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

#define sz(x) (int)((x).size())

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

struct Fenvick {
	int n;
	vector<int> a;

	Fenvick(int nn) {
		n = nn;
		a.resize(n);
	}

	void add(int pos, int x) {
		while (pos < n) {
			a[pos] += x;
			pos |= (pos + 1);
		}
	}

	int get(int pos) {
		int res = 0;
		while (pos >= 0) {
			res += a[pos];
			pos = (pos & (pos + 1)) - 1;
		}
		return res;
	}

	int get(int l, int r) {
		if (l < r) {
			return get(r - 1) - get(l - 1);
		} else {
			return get(n - 1) - get(l - 1) + get(r - 1);
		}
	}
};

int main(){

	int n = nxt(), k = nxt();
	k = min(k, n - k);
	long long cur = 1;
	cout.sync_with_stdio(0);
	Fenvick fenv(n);
	int lst = 0;
	for (int i = 0; i < n; ++i) {
		int nx = lst + k;
		if (nx >= n) {
			nx -= n;
		}
		// cerr << lst << " " << nx << " " << fenv.get(lst + 1, nx) << "\n";
		cur += fenv.get(lst + 1, nx) + 1;
		fenv.add(lst, 1);
		fenv.add(nx, 1);
		lst = nx;
		cout << cur << " ";
	}
	cout << "\n";

	return 0;
}