#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

/*class Grader {
	private:
		int n, k;
		vector<int> v;
		
		inline int nearest(int x) {
			int ans = INT_MAX;
			for (int i: v) {
				ans = min(ans, abs(i - x));
			}
			return ans;
		}
		
		bool exists(int x) {
			for (int i: v) {
				if (i == x) {
					return true;
				}
			}
			return false;
		}
	public:
		void init(int &$n, int &$k) {
			cout << "init(" << n << ", " << k << ");" << endl;
			$n = n; $k = k;
		}
		
		bool ok(int x, int y) {
			cout << "ok(" << x << ", " << y << ") = ";
			bool res = nearest(x) <= nearest(y);
			cout << (res ? "TAK" : "NIE") << ";" << endl;
			return res;
		}
		
		void print(int x, int y) {
			cout << "print(" << x << ", " << y << ");" << endl;
			bool ok = (x != y) && exists(x) && exists(y);
			if (ok) {
				cout << "OK" << endl;
			} else {
				cout << "WA" << endl;
			}
			exit(0);
		}
		
		Grader() {
			cin >> n >> k;
			v = vector<int>(k);
			for (int &i: v) {
				cin >> i;
			}
		}
} grader;*/

class Grader {
	public:
		void init(int &n, int &k) {
			cin >> n >> k;
		}
		
		bool ok(int x, int y) {
			cout << 1 << " " << x << " " << y << endl;
			string s; cin >> s;
			if (s == "TAK") {
				return true;
			} else if (s == "NIE") {
				return false;
			} else {
				cerr << "FATAL!!! Expected \"TAK\" or \"NIE\"." << endl;
				exit(42);
			}
		}
		
		void print(int x, int y) {
			cout << 2 << " " << x << " " << y << endl;
			exit(0);
		}
} grader;

inline int binSearch(int l, int r) {
	while (l < r) {
		int m = (l + r) / 2;
		if (grader.ok(m, m+1)) {
			r = m;
		} else {
			l = m+1;
		}
	}
	return l;
}

int main() {
	int n, k; grader.init(n, k);
	int x = binSearch(1, n);
	int cand1 = (x == 1) ? 0 : binSearch(1, x-1);
	int cand2 = (x == n) ? 0 : binSearch(x+1, n);
	if (cand1 != 0 && grader.ok(cand1, x)) {
		grader.print(x, cand1);
	} else {
		grader.print(x, cand2);
	}
	return 0;
}