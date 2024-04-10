#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

#define sz(x) (int)((x).size())

using namespace std;

inline int nxt(){
	int x;
	cin >> x;
	return x;
}

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);

	int n = nxt();
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		a[i] = nxt();
	}
	vector<long long> pref(n + 1);
	for (int i = 0; i < n; i++) {
		pref[i + 1] = pref[i] + a[i];
	}

	set<int> S;
	S.insert(0);
	S.insert(n + 1);
	multiset<long long> sums;
	sums.insert(-pref[n]);
	sums.insert(0);

	for (int i = 0; i < n; i++) {
		int pos = nxt();
		auto it = S.lower_bound(pos);
		auto it1 = it;
		--it1;

		int l = *it1, r = *it;

		sums.erase(sums.find(pref[l] - pref[r - 1]));
		sums.insert(pref[pos] - pref[r - 1]);
		sums.insert(pref[l] - pref[pos - 1]);
		S.insert(pos);

		cout << -(*sums.begin()) << "\n";
	}

	return 0;
}