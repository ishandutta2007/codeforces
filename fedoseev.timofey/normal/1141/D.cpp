#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    string l, r;
    cin >> l >> r;
    vector <vector <int>> wl(26);
    vector <vector <int>> wr(26);
    vector <int> a, b;
    for (int i = 0; i < n; ++i) {
    	if (l[i] == '?') {
    		a.push_back(i);
    	}
    	else {
    		wl[l[i] - 'a'].push_back(i);
    	}
    	if (r[i] == '?') {
    		b.push_back(i);
    	}
    	else {
    		wr[r[i] - 'a'].push_back(i);
    	}
    }
    vector <pair <int, int>> ans;
    for (int i = 0; i < 26; ++i) {
    	while (!wl[i].empty() && !wr[i].empty()) {
    		ans.emplace_back(wl[i].back(), wr[i].back());
    		wl[i].pop_back();
    		wr[i].pop_back();
    	}
    }
    for (int i = 0; i < 26; ++i) {
    	while (!wl[i].empty() && !b.empty()) {
    		ans.emplace_back(wl[i].back(), b.back());
    		wl[i].pop_back();
    		b.pop_back();
    	}
    	while (!wr[i].empty() && !a.empty()) {
    		ans.emplace_back(a.back(), wr[i].back());
    		a.pop_back();
    		wr[i].pop_back();
    	}
    }
    while (!a.empty() && !b.empty()) {
    	ans.emplace_back(a.back(), b.back());
    	a.pop_back();
    	b.pop_back();
    }
    cout << (int)ans.size() << '\n';
    for (auto p : ans) {
    	cout << p.first + 1 << ' ' << p.second + 1 << '\n';
    }
}