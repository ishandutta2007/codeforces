#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

void winlose(ll a, ll b, ll &Alice, ll &Bob) {
	if (a == b) return;
	a++, b++;
	if ((a == 1 && b == 3) || (a == 2 && b == 1) || (a == 3 && b == 2)) Alice++;
	else Bob++;
}

int main() {
	ll k, a, b;
	cin >> k >> a >> b;
	vector <vector <ll>> A(3, vector <ll>(3)), B(3, vector <ll>(3));
	for (ll i = 0; i < 3; i++)
		for (ll j = 0; j < 3; j++) {
			cin >> A[i][j];
			A[i][j]--;
		}
	for (ll i = 0; i < 3; i++)
		for (ll j = 0; j < 3; j++) {
			cin >> B[i][j];
			B[i][j]--;
		}
	a--, b--;
	ll Alice = 0, Bob = 0;
	vector <bool> used(9);
	vector <pair <ll, ll>> p;
	p.push_back({ a, b });
	k--;
	winlose(a, b, Alice, Bob);
	used[a * 3 + b] = true;
	while (k > 0) {
		ll newa = A[a][b];
		ll newb = B[a][b];
		a = newa, b = newb;
		if (used[newa * 3 + newb]) {
			ll pos = 0;
			while (p[pos].first != a || p[pos].second != b)
				pos++;
			ll newcntAlice = 0, newcntBob = 0;
			ll length = p.size() - pos;
			for (ll i = pos; i < p.size(); i++)
				winlose(p[i].first, p[i].second, newcntAlice, newcntBob);
			ll val = k / length;
			newcntAlice *= val, newcntBob *= val;
			Alice += newcntAlice, Bob += newcntBob;
			k %= length;
			if (!k) break;
		}
		used[a * 3 + b] = true;
		winlose(a, b, Alice, Bob);
		p.push_back({ a, b });
		k--;
	}
	cout << Alice << " " << Bob << endl;
	return 0;
}