#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){

	int d = nxt(), n = nxt(), m = nxt() + 2;
	vector<pair<int, int>> a(m);
	for (int i = 0; i < m - 2; i++){
		a[i].first = nxt();
		a[i].second = nxt();
	}
	a[m - 2] = {0, 0};
	a[m - 1] = {d, 0};
	sort(all(a));

	vector<int> nx(m, -1);
	vector<int> st;
	for (int i = 0; i < m; i++){
		while (!st.empty() && a[st.back()].second >= a[i].second){
			nx[st.back()] = i;
			st.pop_back();
		}
		st.push_back(i);
	}

	int cur = n;
	long long ans = 0;
	int pos = 0;
	vector<pair<int, int>> econ;
	vector<int> minh;
	for (int i = 1; i < m; i++){
//		cerr << a[i - 1].first << " " << cur << " " << ans << "\n";
		int npos = a[i].first;
		while (!econ.empty() && a[i - 1].second <= a[econ.back().first].second && cur > 0){
			long long amount = min(minh.back(), econ.back().second);
			ans -= 1ll * (a[i - 1].second - a[econ.back().first].second) * amount;
			cur -= amount;
			minh.back() -= amount;
			if (econ.back().second == 0){
				econ.pop_back();
				int q = minh.back();
				minh.pop_back();
				if (!minh.empty())
					minh.back() = min(minh.back(), q);
			}
		}
		if (cur == 0){
			econ.clear();
			minh.clear();
		}
		if (!minh.empty())
			minh.back() = min(minh.back(), cur);
		if (nx[i - 1] > -1 && a[nx[i - 1]].first <= a[i - 1].first + cur){
		} else {
			if (nx[i - 1] > -1 && a[nx[i - 1]].first <= a[i - 1].first + n){
				ans += 1ll * (a[nx[i - 1]].first - a[i - 1].first - cur) * a[i - 1].second;
				cur += (a[nx[i - 1]].first - a[i - 1].first - cur);
			} else {
				econ.push_back({i - 1, n - cur});
				minh.push_back(cur);
				ans += 1ll * a[i - 1].second * (n - cur);
				cur = n;
				if (a[i].first > a[i - 1].first + n){
					puts("-1");
					return 0;
				}
			}
		}
		pos = npos;
		cur -= (a[i].first - a[i - 1].first);
		if (!minh.empty())
			minh.back() = min(minh.back(), cur);
	}
	while (!econ.empty() && a[m - 1].second <= a[econ.back().first].second && cur > 0){
		long long amount = min(minh.back(), econ.back().second);
		ans -= 1ll * (a[m - 1].second - a[econ.back().first].second) * amount;
		cur -= amount;
		minh.back() -= amount;
		econ.back().second -= amount;
		if (econ.back().second == 0){
			econ.pop_back();
			int q = minh.back();
			minh.pop_back();
			if (!minh.empty())
				minh.back() = min(minh.back(), q);
		}
	}
	cout << ans << "\n";
	
	return 0;
}