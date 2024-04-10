#include <bits/stdc++.h>

#define int long long

using namespace std;

typedef long long ll;
typedef long double ld;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, m;
    cin >> n >> m;
    ll cnt = n;
    ll k = 0, b = 0;
    vector <pair <int, int>> st;
    st.push_back({0, 0});
    for (int i = 0; i < m; ++i) {
    	auto get = [&] (int id) {
    		ll val = st[id].first;
    		ll i = st[id].second;
    		return val + b + k * i;
    	};
    	int t;
    	cin >> t;
    	if (t == 1) {
    		int c;
    		cin >> c;
    		st.clear();
    		k = 0, b = 0;
    		st.push_back({0, 0});
    		cnt += c;
    	}
    	else if (t == 2) {
    		int c;
    		cin >> c;
    		pair <ll, ll> p = {-b - k * cnt, cnt};

    		while (st.size() > 1) {
	    		pair <ll, ll> a = {st[(int)st.size() - 1].second, get((int)st.size() - 1)};
	    		pair <ll, ll> b = {st[(int)st.size() - 2].second, get((int)st.size() - 2)};
	    		pair <ll, ll> c = {cnt, 0};

	    		pair <ll, ll> d = {a.first - b.first, a.second - b.second};
	    		pair <ll, ll> e = {c.first - b.first, c.second - b.second};

	    		if ((ld)d.first * e.second <= (ld)d.second * e.first) st.pop_back();
	    		else break;
    		}

    		st.push_back(p);
    		cnt += c;
    	}
    	else {
    		int x, y;
    		cin >> x >> y;
    		b += x;
    		k += y;
    	}

    	while (st.size() > 1) {
    		if (get((int)st.size() - 1) >= get((int)st.size() - 2)) st.pop_back();
    		else break;
    	}

    	/*cout << endl;
    	for (int i = 0; i < (int)st.size(); ++i) {
    		cout << st[i].second + 1 << ' ' << get(i) << endl;
    	}
    	cout << endl;*/

    	cout << st.back().second + 1 << ' ' << get((int)st.size() - 1) << '\n';
    }
}