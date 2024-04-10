// who's it from?
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define f first
#define s second
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(), (x).end()
 
ll n;
vector<pair<ll,string> > po;
map<ll, string> mp;
 
int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int base = 2; base <= 100000; base++) {
		ll val = base;
		string s = to_string(base) + '^';
		for (int e = 2; val * base <= 10000000000ll; e++) {
			val *= base;
			po.emplace_back(val, s + to_string(e));
			if(mp.count(val) && SZ(s + to_string(e)) < SZ(mp[val])) {
				mp[val] = s + to_string(e);
			} else if (!mp.count(val)) {
				mp[val] = s + to_string(e);
			}
		}
	}
	//for (ll n = 1; n <= 10000; n++) {
	string res = to_string(n);
	for (const pair<ll,string> &p : po) {
		if (n >= p.f) {
			if (mp.count(n - p.f)) {
				string tmp = p.s + '+' + mp[n - p.f];
				if (SZ(tmp) < SZ(res)) {
					res = tmp;
				}
			}
			for (int i = 0; i < 10; i++) {
				if ((n - i) % p.f == 0 && mp.count((n - i) / p.f)) {
					string tmp = p.s + '*' + mp[(n - i) / p.f];
					if (i != 0) {
						tmp += '+';
						tmp += to_string(i);
					}
					if (SZ(tmp) < SZ(res)) {
						res = tmp;
					}
				}
				
			}
			for (int i = 2; i < 10; i++) {
				if (p.f * i <= n) {
					if (mp.count(n - p.f * i)) {
						string tmp = p.s + '*' + to_string(i) + '+' + mp[n - p.f * i];
						if (SZ(tmp) < SZ(res)) {
							res = tmp;
						}
					}
					if (n % (p.f * i) == 0) {
						if (mp.count(n / (p.f * i))) {
							string tmp = p.s + '*' + to_string(i) + '*' + mp[n / (p.f * i)];
							if (SZ(tmp) < SZ(res)) {
								res = tmp;
							}
						}
					}
				}
			}
			string tmp = p.s;
			if (n - p.f != 0) {
				tmp += '+';
				tmp += to_string(n - p.f);
			}
			if (SZ(tmp) < SZ(res)) {
				res = tmp;
			}
			ll c = n / p.f;
			int d = 0;
			ll asdf = c;
			while (asdf) {
				d++;
				asdf /= 10;
			}
			ll num = 0;
			for (int i = 1; i < d; i++) {
				num = num * 10 + 9;
				tmp = to_string(num) + '*' + p.s;
				assert(n - num * p.f >= 0);
				if (n - num * p.f != 0) {
					tmp += '+';
					tmp += to_string(n - num * p.f);
				}
				if (SZ(tmp) < SZ(res)) {
					res = tmp;
				}
			}
			tmp = to_string(c) + '*' + p.s;
			if (n - c * p.f != 0) {
				tmp += '+';
				tmp += to_string(n - c * p.f);
			}
			if (SZ(tmp) < SZ(res)) {
				res = tmp;
			}
		}
	}
	//cout << n << ' ';
	cout << res << endl;
	//}
	return 0;
}