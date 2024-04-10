#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <iomanip>
#include <numeric>

using namespace std;

int main() {
	
	function<int64_t(int, int, int, int)> gOrder = [&](int x, int y, int iter, int rot) -> int64_t {
		if (iter == 0) {
			return 0;
		}
		int sz = 1 << iter, hsz = sz >> 1;
		int64_t ans = 0;
		
		const int rx[4] = { 0, hsz, hsz, 0   };
		const int ry[4] = { 0, 0  , hsz, hsz };
		
		auto aksept = [&](int qr, int sr, bool rev) -> bool {
			int sx = rx[qr & 3], sy = ry[qr & 3];
			sr &= 3;
			if (sx <= x && x < sx + hsz && sy <= y && y < sy + hsz) {
				int64_t add = gOrder(x - sx, y - sy, iter - 1, sr);
				if (rev) {
					add = ((int64_t)1 << (2*iter - 2)) - add - 1;
				}
				ans += add;
				return true;
			} else {
				ans += (int64_t)1 << (2*iter - 2);
				return false;
			}
		};
		
		aksept(rot+0, rot+1, true ) ||
		aksept(rot+1, rot+0, false) ||
		aksept(rot+2, rot+0, false) ||
		aksept(rot+3, rot+3, true ) ;
		
		return ans;
	};
	
	ios_base::sync_with_stdio(false);
	int n; cin >> n;
	vector<int64_t> ord(n);
	for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		ord[i] = gOrder(x, y, 20, 0);
	}
	
	vector<int> p(n);
	iota(p.begin(), p.end(), 0);
	sort(p.begin(), p.end(), [&](int a, int b) {
		return ord[a] < ord[b];
	});
	
	for (int i = 0; i < n; i++) {
		cout << p[i]+1 << " ";
	}
	cout << endl;
	return 0;
}