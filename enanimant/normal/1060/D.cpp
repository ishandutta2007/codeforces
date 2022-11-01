// October 31, 2018
// http://codeforces.com/problemset/problem/1060/D

/*

*/


#include <bits/stdc++.h>

using namespace std;


const int MAXN = 100000;

struct person {
	int id;
	int l, r;
};

int n;
vector<person> p;
bool used[MAXN];

bool cmp_l(person &a, person &b) {
	return a.l < b.l;
}

bool cmp_r(person &a, person &b) {
	return a.r < b.r;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG


	cin >> n;
	p.resize(n);
	for (int i = 0; i < n; i++) {
		p[i].id = i;
		cin >> p[i].l >> p[i].r;
	}
	sort(p.begin(), p.end(), cmp_r);
	vector<person> q = p;
	sort(p.begin(), p.end(), cmp_l);
	long long ans = n;
	for (int i = 0; i < n; i++) {
		ans += max(p[i].l, q[i].r);
	}
	cout << ans << '\n';


	return 0;
}