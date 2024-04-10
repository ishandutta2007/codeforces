#define _FORTIFY_SOURCE 0
#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 7;

pair <int, int> a[MAXN];
int v[MAXN];
int last[MAXN];

bool comp(int i, int j) {
	return last[i] < last[j];
}

vector <int> pos[MAXN];

bool check(int ans, int num, const set <int> &ms) {
	int l = pos[ans][num - 1] + 1;
	int r = pos[ans][num] - 1;
	
	int k = 0;
	for (int key : ms) {
		auto tl = lower_bound(pos[key].begin(), pos[key].end(), l);
		auto tr = upper_bound(pos[key].begin(), pos[key].end(), r);
	 	k += tr - tl;
	}

	return k < r - l + 1;
}

bool check(int l, int ans, const set <int> &ms, int n) {
	int k = 0;
	k += pos[ans].size() - (lower_bound(pos[ans].begin(), pos[ans].end(), l) - pos[ans].begin());
	for (int key : ms) {
	 	k += pos[key].size() - (lower_bound(pos[key].begin(), pos[key].end(), l) - pos[key].begin());
	}
	return k < n - l;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	for (int i = 0; i < MAXN; ++i) last[i] = -1;

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i].first >> a[i].second;
	for (int i = 0; i < n; ++i) --a[i].first;
	for (int i = 0; i < n; ++i) last[a[i].first] = i;
	for (int i = 0; i < n; ++i) v[i] = i;
	sort(v, v + n, comp);
	
	for (int i = 0; i < n; ++i) pos[a[i].first].push_back(i);

	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
	 	int k;
	 	cin >> k;
	 	set <int> ms;
	 	for (int j = 0; j < k; ++j) {
	 	 	int x;
	 	 	cin >> x;
	 	 	--x;
	 	 	ms.insert(x);
	 	}
		
	 	int ans = -1;
	 	for (int j = n - 1; j >= 0; --j) {
	 	 	if (ms.find(v[j]) == ms.end()) {
	 	 		ans = v[j];
	 	 		break;
	 	 	}
	 	}
		
	 	if (ans == -1 || last[ans] == -1) {                                                    
	 	 	cout << "0 0\n";
	 	}
	 	else {
	 	 	cout << ans + 1 << ' ';

			int l = -1;
			int r = n;
			while (l < r - 1) {
			 	int m = (l + r) / 2;
			 	if (check(m, ans, ms, n)) l = m;
			 	else r = m;
	 	 	}
			
			auto it = upper_bound(pos[ans].begin(), pos[ans].end(), l);
			cout << a[*it].second << '\n';
	 	}
	}

    return 0;
}