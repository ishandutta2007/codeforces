#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(m);
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 0; i < m; ++i) cin >> b[i];
	map<int, int> lst;
	for (int i = 0; i < n; ++i) {
		lst[a[i]] = i;
	}
	set<int> s(a.begin(), a.end());
	long long ans = all_of(b.begin(), b.end(), [&](int x){ return s.count(x);});
	int fin;
	for (int i = 0, cur = 0, ind = 0; i < n && ind < m; ++i, ++cur) {
		ans *= a[i] >= b[ind - (ind != 0)];
		if (a[i] < b[ind]) cur = -1;
		if (i == lst[b[ind]])	{
			if (ind) (ans *= cur + 1)%=998244353;
			++ind;
			cur = -1;
		}	             
		fin = ind;
	}
	ans *= all_of(a.begin() + lst[b.back()], a.end(), [&](int x){ return x >= b.back();});
	cout << ans * (fin == m);
}