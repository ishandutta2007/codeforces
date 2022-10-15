#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int n;
		long long k;
		cin >> n >> k;
		int l1, l2, r1, r2;
		cin >> l1 >> r1 >> l2 >> r2;
		if (l1 > l2) {
			swap(l1, l2);
			swap(r1, r2);
		}
		int s = 1, e = n;
		auto get = [&](int val) -> long long {
			long long sk = k;
			if (l1 <= l2 && r1 >= r2) {
				int f = r2 - l2, one = (l2 - l1) + (r1 - r2);
				sk -= 1ll * f * val;
				sk = max(0ll, sk);
				long long res = min(1ll * one * val, sk); 
				sk -= res;
				return res + sk * 2;
			}	else if (r1 > l2) {
				int f = r1 - l2;
				sk -= 1ll * f * val;					
				sk = max(0ll, sk);
				long long one = r2 - l1 - f;
				long long res = min(1ll * one * val, sk); 
				sk -= res;
				return sk * 2 + res;
			} else {
				int cost = l2 - r1, one = r2 - l1;
				long long res = 1ll * cost * val;
				long long res2 = min(sk, 1ll * one * val);
				sk -= res2;
				res += res2;
				return res + sk * 2;
			}		
		};
		while (s != e) {
			int sz = (e - s + 1) / 3;
			int l = s + sz, r = e - sz;
			if (l == r) ++r;
			if (get(l) < get(r)) {
				e = r - 1;
			}	else s = l + 1;		
		}
		cerr << "ans " <<  s << ' ';
		cout << get(s) << '\n';
	}
}