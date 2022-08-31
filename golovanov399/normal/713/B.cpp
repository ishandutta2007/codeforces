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

int cnt;
vector<int> r1, r2;

bool inside(vector<int> a, vector<int> b) {
	return a[0] >= b[0] && a[1] >= b[1] && a[2] <= b[2] && a[3] <= b[3];
}

inline int ask(int x1, int y1, int x2, int y2) {
	cout << "? " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
	int res;
	cin >> res;
	return res;

	// cnt++;
	// if (cnt > 200) {
	// 	cerr << "more that 200 attempts\n";
	// 	exit(0);
	// }
	// vector<int> rect = {x1, y1, x2, y2};
	// int res = 0;
	// if (inside(r1, rect))
	// 	res++;
	// if (inside(r2, rect))
	// 	res++;


	// cerr << res << "\n";

	return res;
}

void answer(vector<int> ans1, vector<int> ans2) {
	cout << "!";
	for (int x : ans1)
		cout << " " << x;
	for (int x : ans2)
		cout << " " << x;
	cout << endl;

	// if ((ans1 == r1 && ans2 == r2) || (ans1 == r2 && ans2 == r1)) {
	// 	cerr << "ok\n";
	// 	return;
	// } else {
	// 	cerr << "I guessed";
	// 	for (int x : r1)
	// 		cerr << " " << x;
	// 	cerr << " and";
	// 	for (int x : r2)
	// 		cerr << " " << x;
	// 	cerr << "\nwhile you said";
	// 	for (int x : ans1)
	// 		cerr << " " << x;
	// 	cerr << " and";
	// 	for (int x : ans2)
	// 		cerr << " " << x;
	// 	cerr << "\n";
	// 	exit(0);
	// }
}

int n;

pair<int, int> find_hor(int u, int d) {
	int l = 0, r = n;
	while (r > l + 1) {
		int mid = (l + r) / 2;
		int res = ask(u, 1, d, mid);
		if (res == 0) {
			l = mid;
		} else {
			r = mid;
		}
	}
	int R = r;

	l = 0, r = R;
	while (r > l + 1) {
		int mid = (l + r) / 2;
		int res = ask(u, R + 1 - mid, d, R);
		if (res == 0) {
			l = mid;
		} else {
			r = mid;
		}
	}
	int L = R + 1 - r;

	return {L, R};
}

pair<int, int> find_ver(int u, int d) {
	int l = 0, r = n;
	while (r > l + 1) {
		int mid = (l + r) / 2;
		int res = ask(1, u, mid, d);
		if (res == 0) {
			l = mid;
		} else {
			r = mid;
		}
	}
	int R = r;

	l = 0, r = R;
	while (r > l + 1) {
		int mid = (l + r) / 2;
		int res = ask(R + 1 - mid, u, R, d);
		if (res == 0) {
			l = mid;
		} else {
			r = mid;
		}
	}
	int L = R + 1 - r;

	return {L, R};
}

void solve() {
	int l = 0, r = n;
	while (r > l + 1) {
		int mid = (l + r) / 2;
		int res = ask(1, 1, n, mid);
		if (res == 0) {
			l = mid;
		} else {
			r = mid;
		}
	}
	int R = r;

	l = 0, r = n;
	while (r > l + 1) {
		int mid = (l + r) / 2;
		int res = ask(1, n + 1 - mid, n, n);
		if (res == 0) {
			l = mid;
		} else {
			r = mid;
		}
	}
	int L = n + 1 - r;

	l = 0, r = n;
	while (r > l + 1) {
		int mid = (l + r) / 2;
		int res = ask(1, 1, mid, n);
		if (res == 0) {
			l = mid;
		} else {
			r = mid;
		}
	}
	int D = r;

	l = 0, r = n;
	while (r > l + 1) {
		int mid = (l + r) / 2;
		int res = ask(n + 1 - mid, 1, n, n);
		if (res == 0) {
			l = mid;
		} else {
			r = mid;
		}
	}
	int U = n + 1 - r;

	if (R < L) {
		l = 1, r = R + 1;
		while (r > l + 1) {
			int mid = (l + r) / 2;
			int res = ask(1, mid, n, R);
			if (res == 0) {
				r = mid;
			} else {
				l = mid;
			}
		}
		auto p1 = find_ver(l, R);
		vector<int> ans1 = {p1.first, l, p1.second, R};

		l = L - 1, r = n;
		while (r > l + 1) {
			int mid = (l + r) / 2;
			int res = ask(1, L, n, mid);
			if (res == 0) {
				l = mid;
			} else {
				r = mid;
			}
		}
		auto p2 = find_ver(L, r);
		vector<int> ans2 = {p2.first, L, p2.second, r};		
		answer(ans1, ans2);
	} else {
		// cerr << "qwe\n";
		l = 1, r = D + 1;
		while (r > l + 1) {
			int mid = (l + r) / 2;
			int res = ask(mid, 1, D, n);
			if (res == 0) {
				r = mid;
			} else {
				l = mid;
			}
		}
		auto p1 = find_hor(l, D);
		vector<int> ans1 = {l, p1.first, D, p1.second};

		// cerr << "rty\n";

		l = U - 1, r = n;
		while (r > l + 1) {
			int mid = (l + r) / 2;
			int res = ask(U, 1, mid, n);
			if (res == 0) {
				l = mid;
			} else {
				r = mid;
			}
		}
		auto p2 = find_hor(U, r);
		vector<int> ans2 = {U, p2.first, r, p2.second};
		answer(ans1, ans2);
	}
}

int main(){

	n = nxt();

	while (true) {
		// n = 4;
		// do {
		// 	r1.assign(4, 0);
		// 	r2.assign(4, 0);
		// 	for (int i = 0; i < 4; i++)
		// 		r1[i] = rand() % n + 1;
		// 	for (int i = 0; i < 4; i++)
		// 		r2[i] = rand() % n + 1;
		// 	if (r1[0] > r1[2])
		// 		swap(r1[0], r1[2]);
		// 	if (r1[1] > r1[3])
		// 		swap(r1[1], r1[3]);
		// 	if (r2[0] > r2[2])
		// 		swap(r2[0], r2[2]);
		// 	if (r2[1] > r2[3])
		// 		swap(r2[1], r2[3]);
		// } while (!(r1[2] < r2[0] || r2[2] < r1[0] || r1[3] < r2[1] || r2[3] < r1[1]));

		// cnt = 0;
		solve();
		break;
	}

	return 0;
}