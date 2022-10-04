#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <ctime>
#include <random>
#include <cmath>
#include <bitset>
#include <iomanip>
#include <list>
#include <unordered_set>
#include <unordered_map>
#include <cassert>

using namespace std;

typedef long long ll;
typedef long double ld;

const int md = 998244353;

const int N = 2e5 + 7;

void add(int &a, int b) {
	a += b;
	if (a >= md) a -= md;
}

int mul(int a, int b) {
	return ((ll)a * b) % md;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int p2[N];
    p2[0] = 1;
    for (int i = 1; i < N; ++i) p2[i] = (p2[i - 1] * 2) % md;
    int n, m;
    cin >> n >> m;
    vector <int> a(n);
    string s;
    cin >> s;
    for (int i = 0; i < n; ++i) a[i] = s[i] - '0';
    cin >> s;
	vector <int> b(m);
	for (int i = 0; i < m; ++i) b[i] = s[i] - '0';
	vector <int> pref(m + 1);
	for (int i = 1; i <= m; ++i) {
		pref[i] = pref[i - 1] + b[i - 1];
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (!a[i]) continue;
		int kek = n - i;
		int mem = m - kek;
		if (mem < 0) continue;
		add(ans, mul(p2[n - i - 1], pref[mem + 1]));
	}
	cout << ans << '\n';
}