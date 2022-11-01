#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int main() {
	ll n, m;
	cin >> n >> m;
	vector <bool> str(n), sto(n);
	vector <ll> ans;
	ll cntstr = n, cntsto = n, cnt = 0;
	for (ll i = 0; i < m; i++) {
		ll x, y;
		cin >> x >> y;
		x--;
		y--;;
		if (!str[x] && !sto[y]) {
			cnt += (cntstr + cntsto - 1);
			cntstr--;
			cntsto--;
			str[x] = true;
			sto[y] = true;
			ans.push_back(n * n - cnt);
			continue;
		}
		if (!str[x]) {
			cnt += cntsto;
			cntstr--;
			str[x] = true;
			ans.push_back(n * n - cnt);
			continue;
		}
		if (!sto[y]) {
			cnt += cntstr;
			cntsto--;
			sto[y] = true;
			ans.push_back(n * n - cnt);
			continue;
		}
		ans.push_back(n * n - cnt);
	}
	for (auto now : ans)
		cout << now << " ";
	return 0;
}