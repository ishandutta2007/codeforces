#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

bool prime(int x) {
	for (int d = 2; d * d <= x; ++d) if (x % d == 0) return false;
	return true;
}

int nxtPrime(int x) {
	while (!prime(x)) ++x;
	return x;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    int cur = n;
    vector <pair <int, int>> ed;
    for (int i = 0; i < n; ++i) {
    	ed.push_back({i, (i + 1) % n});
    }
    int need = nxtPrime(cur);
    assert(need - cur <= n / 2);
    vector <int> used(n);
    for (int i = 0; i < n; ++i) {
    	if (cur < need) {
    		if (!used[i] && !used[(i + 2) % n]) {
    			ed.push_back({i, (i + 2) % n});
    			++cur;
    			used[i] = used[(i + 2) % n] = 1;
    		}
    	}
    }
    cout << need << '\n';
    for (auto p : ed) {
    	cout << p.first + 1 << ' ' << p.second + 1 << '\n';
    }
}