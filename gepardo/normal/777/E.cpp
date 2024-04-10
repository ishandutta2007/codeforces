#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cstdint>
#define int int64_t

using namespace std;

class Fenwick {
	private:
		int n;
		vector<int> v;
	public:
		inline void upd(int i, int nVal) {
			for (; i < n; i |= i+1) {
				v[i] = max(v[i], nVal);
			}
		}
		
		inline int ans(int i) {
			int res = 0;
			for (; i >= 0; i &= i+1, i--) {
				res = max(res, v[i]);
			}
			return res;
		}
		
		Fenwick(int n)
			: n(n), v(n) {
		}	
};

struct Disc {
	int a, b, h;

	friend bool operator<(const Disc& a, const Disc& b){
		return make_pair(a.b, a.a) > make_pair(b.b, b.a);
	}

	friend istream& operator>>(istream& is, Disc& q) {
		return is >> q.a >> q.b >> q.h;
	}
};

signed main() {
	ios_base::sync_with_stdio(false);
	int n; cin >> n;
	vector<Disc> v(n);
	map<int, int> compr;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		compr[v[i].a] = 42;
		compr[v[i].b] = 42;
	}
	int cnt = 0;
	for (auto& it: compr) {
		it.second = cnt++;
	}
	for (int i = 0; i < n; i++) {
		v[i].a = compr[v[i].a];
		v[i].b = compr[v[i].b];
	}
	sort(v.begin(), v.end());
	Fenwick f(cnt);
	for (int i = 0; i < n; i++) {
		int res = f.ans(v[i].b - 1) + v[i].h;
		f.upd(v[i].a, res);
	}
	cout << f.ans(cnt-1) << endl;
	return 0;
}