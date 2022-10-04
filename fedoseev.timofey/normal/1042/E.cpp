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

int mul(int a, int b) {
	return ((ll)a * b) % md;
}

void add(int &a, int b) {
	a += b;
	if (a >= md) a -= md;
}

void sub(int &a, int b) {
	a -= b;
	if (a <= 0) a += md;
}

int power(int a, ll b) {
	int res = 1;
	while (b > 0) {
		if (b & 1) res = mul(res, a);
		a = mul(a, a);
		b >>= 1;
	}
	return res;
}

int inv(int a) {
	return power(a, md - 2);
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, m;
    cin >> n >> m;
    vector <int> a(n * m);
    for (int i = 0; i < n; ++i) {
    	for (int j = 0; j < m; ++j) {
    		cin >> a[i * m + j];
    	}
    }
    vector <int> idx;
    for (int i = 0; i < n * m; ++i) {
    	idx.push_back(i);
    }
    sort(idx.begin(), idx.end(), [&] (int i, int j) {
    	return a[i] < a[j];
    });
    int sum = 0;
    int sr = 0, sc = 0, pr = 0, pc = 0;
    vector <int> dp(n * m);
    int x = 0;
    while (x < n * m && a[idx[x]] == a[idx[0]]) ++x;

    for (int i = 0; i < x; ++i) {
    	dp[idx[i]] = 0;
    	add(sr, mul(idx[i] / m, idx[i] / m));
    	add(sc, mul(idx[i] % m, idx[i] % m));
    	add(pr, idx[i] / m);
    	add(pc, idx[i] % m);
    }
    for (int i = x; i < n * m; ++i) {
    	int j = i;
    	while (j < n * m && a[idx[j]] == a[idx[i]]) ++j;
    	--j;
    	for (int k = i; k <= j; ++k) {
    		add(dp[idx[k]], sum);
    		add(dp[idx[k]], sr);
    		add(dp[idx[k]], sc);
    		add(dp[idx[k]], mul(i, mul(idx[k] / m, idx[k] / m)));
    		add(dp[idx[k]], mul(i, mul(idx[k] % m, idx[k] % m)));
    		sub(dp[idx[k]], mul(2, mul(pr, idx[k] / m)));
    		sub(dp[idx[k]], mul(2, mul(pc, idx[k] % m)));

    		dp[idx[k]] = mul(dp[idx[k]], inv(i));
    	}

    	for (int k = i; k <= j; ++k) {
    		add(sum, dp[idx[k]]);
    		add(sr, mul(idx[k] / m, idx[k] / m));
    		add(sc, mul(idx[k] % m, idx[k] % m));
    		add(pr, idx[k] / m);
    		add(pc, idx[k] % m);
    	}
    	i = j;
    }
    int r, c;
    cin >> r >> c;
    --r, --c;
    cout << dp[r * m + c] << '\n';
}