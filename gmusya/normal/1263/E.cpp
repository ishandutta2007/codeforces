#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct tree {
	int mod, min, max;
};
char a[1000000];
tree t[2100000];
int bal = 0;

int maaa(int v, int tl, int tr, int l, int r) {
	if (l > r)
		return 0;
	if (l == tl && r == tr)
		return t[v].max + t[v].mod;
	int tm = (tl + tr) / 2;
	t[v * 2].mod += t[v].mod;
	t[v * 2 + 1].mod += t[v].mod;
	t[v].max += t[v].mod;
	t[v].min += t[v].mod;
	t[v].mod = 0;
	return max(maaa(v * 2, tl, tm, l, min(r, tm)), maaa(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}

int miii(int v, int tl, int tr, int l, int r) {
	if (l > r)
		return 100000000;
	if (l == tl && r == tr)
		return t[v].min + t[v].mod;
	int tm = (tl + tr) / 2;
	t[v * 2].mod += t[v].mod;
	t[v * 2 + 1].mod += t[v].mod;
	t[v].max += t[v].mod;
	t[v].min += t[v].mod;
	t[v].mod = 0;
	return min(miii(v * 2, tl, tm, l, min(r, tm)), miii(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}

void update(int v, int tl, int tr, int l, int r, int k) {
	if (l > r)
		return;
	if (l == tl && r == tr) {
		t[v].mod += k;
		return;
	}
	int tm = (tl + tr) / 2;
	t[v * 2].mod += t[v].mod;
	t[v * 2 + 1].mod += t[v].mod;
	t[v].mod = 0;
	update(v * 2, tl, tm, l, min(r, tm), k);
	update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, k);
	t[v].max = max(t[v * 2].max + t[v * 2].mod, t[v * 2 + 1].max + t[v * 2 + 1].mod);
	t[v].min = min(t[v * 2].min + t[v * 2].mod, t[v * 2 + 1].min + t[v * 2 + 1].mod);
}
int main() {
	int n;
	cin >> n;
	vector <char> b(n);
	for (int i = 0; i < n; i++)
		cin >> b[i];
	int uk = 0;
	int minuk = uk;
	int maxuk = uk;
	for (int i = 0; i < n; i++) {
		minuk = min(uk, minuk);
		maxuk = max(uk, maxuk);
		if (i != 0)
		{
			if (bal != 0 || miii(1, 0, 1000000, minuk, maxuk) < 0)
				cout << -1 << " ";
			else
				cout << maaa(1, 0, 1000000, minuk, maxuk) << " ";
		}
		if (b[i] == 'L') {
			uk--;
			uk = max(0, uk);
			continue;
		}
		if (b[i] == 'R') {
			uk++;
			continue;
		}
		if (b[i] == ')' && a[uk] != '(' && a[uk] != ')') {
			a[uk] = ')';
			bal--;
			update(1, 0, 1000000, uk, 1000000, -1);
			continue;
		}
		if (b[i] == ')' && a[uk] == '(') {
			a[uk] = ')';
			bal -= 2;
			update(1, 0, 1000000, uk, 1000000, -2);
			continue;
		}
		if (b[i] == '(' && a[uk] != '(' && a[uk] != ')') {
			a[uk] = '(';
			bal++;
			update(1, 0, 1000000, uk, 1000000, 1);
			continue;
		}
		if (b[i] == '(' && a[uk] == ')') {
			a[uk] = '(';
			bal += 2;
			update(1, 0, 1000000, uk, 1000000, 2);
			continue;
		}
		if (a[uk] == ')' && b[i] != ')') {
			bal++;
			a[uk] = 'a';
			update(1, 0, 1000000, uk, 1000000, 1);
			continue;
		}
		if (a[uk] == '(' && b[i] != '(') {
			bal--;
			a[uk] = 'a';
			update(1, 0, 1000000, uk, 1000000, -1);
			continue;
		}
	}
	minuk = min(uk, minuk);
	maxuk = max(uk, maxuk);
	if (bal != 0 || miii(1, 0, 1000000, minuk, maxuk) < 0)
		cout << -1 << " ";
	else
		cout << maaa(1, 0, 1000000, minuk, maxuk) << " ";
	return 0;
}