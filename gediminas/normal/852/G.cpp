/*input
3 1
abc
aec
ac
ab???

*/
#include <bits/stdc++.h>

using namespace std;

unordered_map<string, int> zod;
unordered_set<string> buv;

int rek(string &a, int ind) {
	//cout << asdasd << a << " " << ind << endl;

	if (ind == -1) {
		unordered_map<string, int>::iterator x = zod.find(a);

		if (x == zod.end() || buv.find(a) != buv.end())
			return 0;

		buv.insert(a);
		return x->second;
	}

	int tol = a.find('?', ind + 1);
	int ret = 0;

	for (char i = 'a'; i <= 'e'; i++) {
		a[ind] = i;
		ret += rek(a, tol);
	}

	string b = a.substr(0, ind);
	b += a.substr(ind + 1, a.size());
	ret += rek(b, (tol == -1 ? -1 : tol - 1));
	a[ind] = '?';
	return ret;
}

int main () {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string x;
		cin >> x;
		zod[x]++;
	}

	for (int i = 0; i < m; i++) {
		string a;
		cin >> a;
		buv.clear();
		cout << rek(a, a.find('?')) << "\n";
	}


	return 0;
}