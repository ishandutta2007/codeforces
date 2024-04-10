#include <iostream>
#include <vector>

#define ll long long

using namespace std;

struct query {
	ll type, l, r;
};

int main() {
	ll n, q, m;
	cin >> n >> q >> m;
	vector <ll> a(n + 1);
	for (ll i = 1; i <= n; i++)
		cin >> a[i];

	vector <query> hm(q);
	for (ll i = 0; i < q; i++)
		cin >> hm[i].type >> hm[i].l >> hm[i].r;

	vector <ll> ans;
	for (ll i = 0; i < m; i++) {
		ll pos;
		cin >> pos;
		for (ll j = q - 1; j >= 0; j--) {
			if (pos < hm[j].l || pos > hm[j].r)
				continue;
			if (hm[j].type == 1) {
				pos--;
				if (pos == hm[j].l - 1)
					pos = hm[j].r;
			}
			if (hm[j].type == 2)
				pos = (hm[j].l + hm[j].r) - pos;
		}
		ans.push_back(a[pos]);
	}
	
	for (auto now : ans)
		cout << now << " ";

	return 0;
}