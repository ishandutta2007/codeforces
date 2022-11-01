#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long
using namespace std;

vector <vector <ll>> f(31);
vector <ll> p(31);

ll rec(vector <ll> &hm, ll st) {
	if (st < 0)
		return 0;
	vector <ll> with;
	vector <ll> without;
	for (ll i = 0; i < hm.size(); i++) {
		if ((hm[i] & p[st]) != 0)
			without.push_back(hm[i]);
		else
			with.push_back(hm[i]);
	}
	if (without.size() == 0 || with.size() == 0) 
		return rec(hm, st - 1);
	ll l = rec(with, st - 1);
	ll r = rec(without, st - 1);
	return max(min(l, r) + p[st], max(l, r));
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n;
	cin >> n;
	vector <ll> a(n);
	for (ll i = 0; i < n; i++)
		cin >> a[i];
	p[0] = 1;
	for (ll i = 1; i < 31; i++)
		p[i] = p[i - 1] * 2;
	cout << rec(a, 29);
	return 0;
}